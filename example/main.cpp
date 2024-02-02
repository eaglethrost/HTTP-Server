#include <iostream>
#include "httpserver/Server.h"

void START_CLOSE_SERVER_TEST(Server& server)
{
    server.startServer();
    server.closeServer();
}

int main(void)
{
    Server MainServer;
    START_CLOSE_SERVER_TEST(MainServer);
    return 0;
}