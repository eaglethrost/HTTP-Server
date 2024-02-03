#ifndef SOCKET_ADDRESS_H
#define SOCKET_ADDRESS_H

#include <arpa/inet.h>

// Assign socket to an address and port
struct socketaddr_in {
    short             sin_family;     /* socket family */
    unsigned short    sin_port;       /* port used in our server, usually 80 is reserved of TCP */
    struct in_addr    sin_addr;       /* ip address of network. must be in network byte order. 0.0.0.0 lets the device choose any address */
    char              sin_zero[8];    /* buffer to adjust address size */
};

#endif