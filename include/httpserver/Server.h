#ifndef SERVER_H
#define SERVER_H

/*
=========================================
Uses m_ prefix to denote member variables
=========================================
*/

#include "logger/Logs.h"
#include "SocketAddr.h"

#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class Server{

    private:
        struct in_addr x;
        int m_socket;                               /* current device endpoint for communication */
        struct socketaddr_in m_socket_address;      /* socket's address information */
        unsigned int m_socket_address_len;
        int m_port;                                 /* current device port number used to communicate*/
        std::string m_ip_address;                   /* current device ip address */

        Logs Log;                                   /* logger object */
    public:
        Server();
        Server(std::string ip_address, int port);
        ~Server();

        int startServer();                          /* opens socket */
        void closeServer();                         /* closes socket */
};

#endif