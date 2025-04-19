#pragma once

#include <boost/asio.hpp>

class server
{
public:
    server(boost::asio::io_context& io_context, uint16_t port);
    void start();
    void stop();

private:
    class Impl;
    std::unique_ptr<Impl> _pimpl;
};