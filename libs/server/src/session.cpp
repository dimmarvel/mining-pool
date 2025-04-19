
#include "session.hpp"
#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using namespace boost::system;

session::session(socket_type socket)
    : socket_(std::move(socket))
{}

void session::start() {
    do_read();
}

void session::do_read() {
    auto self(shared_from_this());
    
    socket_.async_read_some(
        buffer(buffer_, buffer_size),
        [this, self](const error_code& ec, size_t bytes_transferred) {
            if (!ec) {
                std::cout << "Received: " 
                          << std::string(buffer_, bytes_transferred) 
                          << std::endl;
                do_write(bytes_transferred);
            } else {
                if (ec != error::operation_aborted) {
                    std::cerr << "Read error: " << ec.message() << std::endl;
                    socket_.close();
                }
            }
        });
}

void session::do_write(size_t length) {
    auto self(shared_from_this());
    
    async_write(
        socket_,
        buffer(buffer_, length),
        [this, self](const error_code& ec, size_t /*bytes_transferred*/) {
            if (!ec) {
                do_read();
            } else {
                if (ec != error::operation_aborted) {
                    std::cerr << "Write error: " << ec.message() << std::endl;
                    socket_.close();
                }
            }
        });
}