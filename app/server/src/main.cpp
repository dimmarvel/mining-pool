#include <server.hpp>
#include <boost/asio.hpp>
#include <iostream>

int main() {
    try {
        boost::asio::io_context io_context;
        const unsigned short port = 8080;
        
        server nest(io_context, port);
        nest.start();
        
        std::cout << "Server running on port " << port << std::endl;
        io_context.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}