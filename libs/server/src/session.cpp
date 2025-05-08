
#include "session.hpp"
#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using namespace boost::system;

session::session(socket_type socket)
	: _socket(std::move(socket))
{}

void session::start() {
	do_read();
}

void session::do_read() {
	auto self(shared_from_this());

	_socket.async_read_some(
		buffer(_buffer, buffer_size),
		[this, self](const error_code& ec, size_t bytes_transferred) {
			if (!ec) {
				std::cout << "Received: " 
						  << std::string(_buffer, bytes_transferred) 
						  << std::endl;
				do_write(bytes_transferred);
			} else {
				if (ec != error::operation_aborted) {
					std::cerr << "Read error: " << ec.message() << std::endl;
					_socket.close();
				}
			}
		});
}

void session::do_write(size_t length) {
	auto self(shared_from_this());

	async_write(
		_socket,
		buffer(_buffer, length),
		[this, self](const error_code& ec, size_t /*bytes_transferred*/) {
			if (!ec) {
				do_read();
			} else {
				if (ec != error::operation_aborted) {
					std::cerr << "Write error: " << ec.message() << std::endl;
					_socket.close();
				}
			}
		});
}