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

const int MAX_CONNECTIONS = 20;
const int REQUEST_BUFFER_SIZE = 30000;

/*
 * An HTTP Server that opens a socket and listens to incoming connections
 */
class Server{
    private:
        int m_socket;                               /* current device endpoint for communication */
        int m_new_socket;                           /* socket to handle a new connection request */
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
        void startListening();                      /* starts listening to connection requests */
        void acceptConnection();     /* accept an incoming connection and process the request */
        void readRequest();                         /* processes incoming request message */
        void respondRequest();                      /* responds back to device who requested */
};

#endif