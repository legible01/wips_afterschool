#ifndef SVRSOCKET_H
#define SVRSOCKET_H

#include <iostream>
#include <cstdint>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <thread>

#include "mac.h"



class svrsocket
{
public:



    int serverSocket;
    int clientSocket;

    int acceptChg;

    //bool readFlag = false;
    bool wrtFlag = false;
    bool thFlag = false;

    int recvLen = 0;


    uint8_t recvBuf[50]={};
    uint8_t sendBuf[50]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    char * inetAdr;
    uint16_t portNo;
    struct sockaddr_in serverAdr,clientAdr;

    typedef struct recv_info{
        mac apMac;
        char rss;
        uint16_t channel;
        mac stationMac;
    }info;
    info infoForm;


    svrsocket();
    void testFunc(void);
    void readFunc(int clientSocket,uint8_t* recvBuf);
    void writeFunc(int clientSocket ,uint8_t* sendBuf);

};

#endif // SVRSOCKET_H
