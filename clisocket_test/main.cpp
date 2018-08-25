#include <iostream>



#include <iostream>
#include <cstdint>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <thread>

using namespace std;

int main()
{

    int clientSocket;
    bool wrtFlag = false;

    uint8_t recvBuf[50];
    uint8_t sendBuf[50]={1,2,3,4,5,6,7,8,9,10};
    char * inetAdr="127.0.0.1";
    uint16_t portNo=4000;
    struct sockaddr_in serverAdr;
    int len=0;
    bool conFlag = true;



    serverAdr.sin_family = AF_INET;
    serverAdr.sin_port = htons(portNo);
    serverAdr.sin_addr.s_addr = inet_addr(inetAdr);
    //serverAdr.sin_addr.s_addr = htonl(INADDR_ANY);

    while(conFlag == true){
        clientSocket = socket(PF_INET,SOCK_STREAM,0);
        if(clientSocket == -1){
            printf("server socket create fail");

        }

        if(connect(clientSocket,(struct sockaddr *)&serverAdr,sizeof(serverAdr)) == -1){
            printf("can't connect\n");
            close(clientSocket);
            sleep(0.1);
            continue;
            //return -1;
        }
        //connect where? need debug?
        printf("after connect");
        conFlag = false;
    }


   // while(true){
        //len = read(clientSocket,recvBuf,sizeof(recvBuf));
        //if(len>0){
        //recvBuf something
            //printf(" client recvBuf is %p %d\n\n",&recvBuf[0],recvBuf[2]);
        //}
        //debug code
        for(int i=0;i!=5;i++){
            wrtFlag = true;

            if(wrtFlag == true)
            {
                write(clientSocket,sendBuf,sizeof(sendBuf));
                printf("sizeof sendbuf is %d\n",sizeof(sendBuf));
                wrtFlag = false;

            }
            //write
            printf("%d send count\n",i);
        }



   // }

    return 0;
}



