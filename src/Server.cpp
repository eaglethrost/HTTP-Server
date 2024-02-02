#include "httpserver/Server.h"

#include <iostream>

Server::Server()
{
    std::cout << "Initialized server!!\n";
    Log = Logs();
}

Server::~Server()
{
    std::cout << "Destroyed server!!\n";
}

int Server::startServer()
{
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    // cannot open socket
    if (m_socket < 0)
    {
        Log.exitWithError("Cannot open socket");
        return 1;
    }
    Log.log("Opened Socket!!");
    return 0;
}

void Server::closeServer()
{
    close(m_socket);
}