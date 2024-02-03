#include <iostream>
#include "httpserver/Server.h"

void START_CLOSE_SERVER_DEFAULT_TEST()
{
    std::cout << "Start Default Server Test...\n";
    Server server;
    server.startServer();
    server.closeServer();
    return;
}

void START_CLOSE_SERVER_CUSTOM_TEST(std::string ip_address, int port)
{
    std::cout << "Start Custom IP & Port Server Test...\n";
    Server server(ip_address,port);
    server.startServer();
    server.closeServer();
    return;
}

int main(void)
{
    START_CLOSE_SERVER_DEFAULT_TEST();
    std::cout << "========================\n";
    START_CLOSE_SERVER_CUSTOM_TEST("0.0.0.0",8080);
    return 0;
}