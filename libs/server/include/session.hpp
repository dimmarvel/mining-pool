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

	socket_type _socket;
	enum { buffer_size = 1024 };
	char _buffer[buffer_size];
};