#include "clisocket.h"

 clisocket::clisocket()
{
    clientSocket = socket(PF_INET,SOCK_STREAM,0);
    if(clientSocket == -1){
        printf("server socket create fail");

    }

    serverAdr.sin_family = AF_INET;
    serverAdr.sin_port = htons(portNo);
    serverAdr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(connect(clientSocket,(struct sockaddr *)&clientSocket,sizeof(clientSocket)) == -1){

        printf("can't connect\n");
        close(clientSocket);
        //return -1;

    }
    int len=0;
    while(true){
        len = read(clientSocket,recvBuf,sizeof(recvBuf));
        if(len>0){
        //recvBuf something

        }

        if(wrtFlag == true)
        {
            write(clientSocket,sendBuf,sizeof(sendBuf));
            this->wrtFlag = false;
        }
        //write

    }

}
