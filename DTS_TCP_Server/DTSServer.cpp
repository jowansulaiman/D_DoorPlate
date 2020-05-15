#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include<boost/asio/steady_timer.hpp>
#include<chrono>

boost::asio::io_service ioservice;
boost::asio::ip::tcp::resolver resolver(ioservice);

void resolverHandler(const boost::system::error_code& ec,
    boost::asio::ip::tcp::resolver::iterator iter) {
    if (ec) {
        std::cout << "Error: " << ec.message() << std::endl;
    }
    else
    {
        boost::asio::ip::tcp::endpoint endpoint = *iter;
        std::cout << "Connection to: " << endpoint.address() << ":" << endpoint.port() << std::endl;
    }
}

int main()
{
    boost::asio::ip::tcp::resolver::query query("127.0.0.1", "80");
    resolver.async_resolve(query, resolverHandler);

    ioservice.run();
    return 0;
}