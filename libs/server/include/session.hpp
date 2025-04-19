#pragma once

#include <boost/asio.hpp>
#include <memory>

class session : public std::enable_shared_from_this<session> {
public:
    using socket_type = boost::asio::ip::tcp::socket;
    
    explicit session(socket_type socket);
    void start();

private:
    void do_read();
    void do_write(size_t length);

    socket_type socket_;
    enum { buffer_size = 1024 };
    char buffer_[buffer_size];
};