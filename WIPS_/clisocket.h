#ifndef CLISOCKET_H
#define CLISOCKET_H

#include <iostream>
#include <cstdint>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>




class clisocket
{
private:

    int clientSocket;
    bool wrtFlag = false;

    uint8_t recvBuf[15];
    uint8_t sendBuf[15];
    char * inetAdr;
    uint16_t portNo;
    struct sockaddr_in serverAdr;



public:
    clisocket();
};

#endif // CLISOCKET_H
