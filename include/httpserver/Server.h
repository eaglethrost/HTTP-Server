#ifndef SERVER_H
#define SERVER_H

/*
 * An HTTP Server that opens a socket and listens to incoming connections
 */

#include "logger/Logs.h"
#include "SocketAddr.h"

#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class Server{
    public:
        Server();
        Server(std::string ipAddress, int port);
        ~Server();

        int startServer();                          /* opens socket */
        void startListening();                      /* starts listening to connection requests */
        void acceptConnection();                    /* accept an incoming connection and process the request */
        void readRequest();                         /* processes incoming request message */
        void respondRequest();                      /* responds back to device who requested */
    
    private:
        int socket_;                                /* current device endpoint for communication */
        int newConnSocket_;                         /* socket to handle a new connection request */
        struct socketaddr_in socketAddress_;        /* socket's address information */
        unsigned int socketAddressLen_;
        int port_;                                  /* current device port number used to communicate*/
        std::string ipAddress_;                     /* current device ip address */
        Logs logger;                                /* logger object */

        static const int MAX_CONNECTIONS = 20;
        static const int REQUEST_BUFFER_SIZE = 30000;
};

#endif