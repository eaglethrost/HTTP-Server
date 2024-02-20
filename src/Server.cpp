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
    close(m_socket);
    std::cout << "Destroyed server!!\n";
}

/*
 *  Opens a socket in the current device and binds an IP address to it
 */
int Server::startServer()
{
    m_socket = socket(AF_INET, SOCK_STREAM, 0);     /* domain, communication structure, protocol */
    if (m_socket < 0)
    {
        // cannot open socket
        Log.exitWithError("Cannot open socket");
        return 1;
    }
    
    if (bind(m_socket, (sockaddr*)&m_socket_address, m_socket_address_len) < 0)
    {
        Log.exitWithError("Cannot bind socket with address");
        return 1;
    }

    // TODO: Implement logger that takes in a variable to be printed
    std::cout << "Opened socket address at IP " << m_ip_address << "\n";
    return 0;
}

/*
 * Start socket listening to incoming connections
 */
void Server::startListening()
{
    if (listen(m_socket, MAX_CONNECTIONS) < 0)
    {
        Log.exitWithError("Socket failed to listen");
    }
    std::cout << "\nListening on ADDRESS: "
              << inet_ntoa(m_socket_address.sin_addr)
              << "\nPORT: " << ntohs(m_socket_address.sin_port)
              << "\n";
}

/*
 * Accept a connection and create a new thread socket to deal with it
 */
void Server::acceptConnection()
{
    m_new_socket = accept(m_socket, (sockaddr *)&m_socket_address, &m_socket_address_len);
    if (m_new_socket < 0)
    {
        std::cout << "\nServer failed to accept incoming connection from ADDRESS: "
                << inet_ntoa(m_socket_address.sin_addr)
                << "\nPORT: " << m_socket_address.sin_port
                << "\n";
        Log.exitWithError("Cannot accept incoming request");
    }
    
    std::cout << "\nServer accepted incoming connection from ADDRESS: "
            << inet_ntoa(m_socket_address.sin_addr)
            << "\nPORT: " << m_socket_address.sin_port
            << "\n";

    readRequest();
    respondRequest();
}

void Server::readRequest()
{
    char buffer[REQUEST_BUFFER_SIZE] = {};
    ssize_t bytesRead = read(m_new_socket, buffer, REQUEST_BUFFER_SIZE);
    if (bytesRead < 0)
    {
        Log.exitWithError("Faild to read bytes from client socket connection");
    }
}

void Server::respondRequest()
{
    std::string response = "your request has been processed!!\n";
    ssize_t bytesSent = write(m_new_socket, response.c_str(), response.size());
    if (bytesSent == response.size())
    {
        Log.log("===== Client Request has been served and responsed =====\n");
    }
    else
    {
        Log.log("Error responding to client");
    }
}