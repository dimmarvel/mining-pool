#pragma once

#include <boost/asio.hpp>
#include <memory>

class server
{
public:
    server(boost::asio::io_context& io_context, uint16_t port);

    ~server();

    server() = delete;
    server(const server&) = delete;
    server& operator=(const server&) = delete;
    server(server&&) noexcept;
    server& operator=(server&&) noexcept;

public:
    void start();
    void stop();

private:
    class impl;
    std::unique_ptr<impl> _pimpl;
};