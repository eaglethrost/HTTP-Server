#ifndef SERVER_H
#define SERVER_H

#include "logger/Logs.h"

#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class Server{

    private:
        int m_socket;
        int m_port;
        std::string ip_address;
        
        Logs Log;

    public:
        Server();
        ~Server();

        int startServer();
        void closeServer();
};

#endif