#include "httpserver/Server.h"

#include <iostream>

Server::Server()
{
    logger = Logs();

    ipAddress_ = "0.0.0.0";
    port_ = 8080;

    socketAddress_.sin_family = AF_INET;
    socketAddress_.sin_port = htons(port_);
    socketAddress_.sin_addr.s_addr = inet_addr(ipAddress_.c_str());
    socketAddressLen_ = sizeof(socketAddress_);

    logger.log("Initialized Server!!");
}

Server::Server(std::string ipAddress, int port)
{
    logger = Logs();

    ipAddress_ = ipAddress;
    port_ = port;

    socketAddress_.sin_family = AF_INET;
    socketAddress_.sin_port = htons(port_);
    socketAddress_.sin_addr.s_addr = inet_addr(ipAddress_.c_str());
    socketAddressLen_ = sizeof(socketAddress_);

    logger.log("Initialized Server!!");
}

Server::~Server()
{
    close(socket_);
    std::cout << "Destroyed server!!\n";
}

/*
 *  Opens a socket in the current device and binds an IP address to it
 */
int Server::startServer()
{
    socket_ = socket(AF_INET, SOCK_STREAM, 0);     /* domain, communication structure, protocol */
    if (socket_ < 0)
    {
        // cannot open socket
        logger.exitWithError("Cannot open socket");
        return 1;
    }
    
    if (bind(socket_, (sockaddr*)&socketAddress_, socketAddressLen_) < 0)
    {
        logger.exitWithError("Cannot bind socket with address");
        return 1;
    }

    // TODO: Implement logger that takes in a variable to be printed
    std::cout << "Opened socket address at IP " << ipAddress_ << "\n";
    return 0;
}

/*
 * Start socket listening to incoming connections
 */
void Server::startListening()
{
    if (listen(socket_, MAX_CONNECTIONS) < 0)
    {
        logger.exitWithError("Socket failed to listen");
    }
    std::cout << "\nListening on ADDRESS: "
              << inet_ntoa(socketAddress_.sin_addr)
              << "\nPORT: " << ntohs(socketAddress_.sin_port)
              << "\n";
}

/*
 * Accept a connection and create a new thread socket to deal with it
 */
void Server::acceptConnection()
{
    newConnSocket_ = accept(socket_, (sockaddr *)&socketAddress_, &socketAddressLen_);
    if (newConnSocket_ < 0)
    {
        std::cout << "\nServer failed to accept incoming connection from ADDRESS: "
                << inet_ntoa(socketAddress_.sin_addr)
                << "\nPORT: " << socketAddress_.sin_port
                << "\n";
        logger.exitWithError("Cannot accept incoming request");
    }
    
    std::cout << "\nServer accepted incoming connection from ADDRESS: "
            << inet_ntoa(socketAddress_.sin_addr)
            << "\nPORT: " << socketAddress_.sin_port
            << "\n";

    readRequest();
    respondRequest();
}

void Server::readRequest()
{
    char buffer[REQUEST_BUFFER_SIZE] = {};
    ssize_t bytesRead = read(newConnSocket_, buffer, REQUEST_BUFFER_SIZE);
    std::cout << buffer << "\n"; 
    if (bytesRead < 0)
    {
        logger.exitWithError("Faild to read bytes from client socket connection");
    }
}

void Server::respondRequest()
{
    std::string response = "your request has been processed!!\n";
    ssize_t bytesSent = write(newConnSocket_, response.c_str(), response.size());
    if (bytesSent == response.size())
    {
        logger.log("===== Client Request has been served and responsed =====\n");
    }
    else
    {
        logger.log("Error responding to client");
    }
}