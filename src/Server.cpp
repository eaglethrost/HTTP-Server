#include "httpserver/Server.h"

#include <iostream>

Server::Server()
{
    Log = Logs();

    m_ip_address = "0.0.0.0";
    m_port = 8080;

    m_socket_address.sin_family = AF_INET;
    m_socket_address.sin_port = htons(m_port);
    m_socket_address.sin_addr.s_addr = inet_addr(m_ip_address.c_str());
    m_socket_address_len = sizeof(m_socket_address);

    Log.log("Initialized Server!!");
}

Server::Server(std::string ip_address, int port)
{
    Log = Logs();

    m_ip_address = ip_address;
    m_port = port;

    m_socket_address.sin_family = AF_INET;
    m_socket_address.sin_port = htons(m_port);
    m_socket_address.sin_addr.s_addr = inet_addr(m_ip_address.c_str());
    m_socket_address_len = sizeof(m_socket_address);

    Log.log("Initialized Server!!");
}

Server::~Server()
{
    std::cout << "Destroyed server!!\n";
}

int Server::startServer()
{
    m_socket = socket(AF_INET, SOCK_STREAM, 0);     /* domain, communication structure, protocol */
    if (m_socket < 0)
    {
        // cannot open socket
        Log.exitWithError("Cannot open socket");
        return 1;
    }
    
    // bind socket
    if (bind(m_socket, (sockaddr*)&m_socket_address, m_socket_address_len) < 0)
    {
        Log.exitWithError("Cannot bind socket with address");
        return 1;
    }

    Log.log("Opened Socket!!");
    return 0;
}

void Server::closeServer()
{
    close(m_socket);
}