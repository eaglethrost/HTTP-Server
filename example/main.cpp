#include <iostream>
#include "httpserver/Server.h"

void START_CLOSE_SERVER_DEFAULT_TEST()
{
    std::cout << "Start Default Server Test...\n";
    Server server;
    server.startServer();
    return;
}

void START_CLOSE_SERVER_CUSTOM_TEST(std::string ip_address, int port)
{
    std::cout << "Start Custom IP & Port Server Test...\n";
    Server server(ip_address,port);
    server.startServer();
    return;
}

void LISTEN_TEST()
{
    std::cout << "Start Listening Test...\n";
    Server server;
    server.startServer();
    server.startListening();
}

void RESPOND_REQUEST_TEST(std::string ip_address, int port)
{
    std::cout << "Start Responding to Request Test...\n";
    Server server(ip_address,port);
    server.startServer();
    server.startListening();
    server.acceptConnection();
}

int main(void)
{
    // START_CLOSE_SERVER_DEFAULT_TEST();
    // std::cout << "\n========================\n\n";
    // START_CLOSE_SERVER_CUSTOM_TEST("0.0.0.0",8080);
    RESPOND_REQUEST_TEST("0.0.0.0",8080);
    return 0;
}