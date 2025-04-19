#include <server.hpp>
#include <session.hpp>

class server::impl 
{
public:
    impl(boost::asio::io_context& io_context, uint16_t port)
        : acceptor_(io_context, 
                    boost::asio::ip::tcp::endpoint(
                        boost::asio::ip::tcp::v4(), port)) 
    {
        start_accept();
    }

    void start() {
        // ...
    }

    void stop() {
        acceptor_.close();
    }

private:
    void start_accept() {
        acceptor_.async_accept(
            [this](boost::system::error_code ec, 
                    session::socket_type socket) {
                if (!ec) {
                    std::make_shared<session>(std::move(socket))->start();
                }
                start_accept();
            });
    }

    boost::asio::ip::tcp::acceptor acceptor_;
};

// PIMPL
server::server(boost::asio::io_context& io_context, uint16_t port)
    : _pimpl(std::make_unique<impl>(io_context, port)) {}

server::~server() = default;

server::server(server&&) noexcept = default;
server& server::operator=(server&&) noexcept = default;

void server::start() { _pimpl->start(); }
void server::stop() { _pimpl->stop(); }