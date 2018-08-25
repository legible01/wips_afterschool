#include "svrsocket.h"

svrsocket::svrsocket()
{
        serverSocket = socket(PF_INET,SOCK_STREAM,0);//IPPROTO_TCP

        //bzero(&serverAdr,sizeof(serverAdr));
        //struct sockaddr_in addr = {0, };
        memset( &serverAdr, 0, sizeof(serverAdr));
        printf("size Adr is %d\n",sizeof(serverAdr));
        serverAdr.sin_family = AF_INET;
        serverAdr.sin_port = htons(4000);
        serverAdr.sin_addr.s_addr = htonl(INADDR_ANY);






}


void svrsocket::testFunc(void)
{
    //int ret = connect(sd, (struct sockaddr*)&addr, sizeof(addr));
    if (bind(serverSocket, (struct sockaddr*)&serverAdr, sizeof(serverAdr)) == -1) {
        printf("bind error()\n");
        exit(0);
    }
    if(listen(serverSocket,5) == -1){
        printf("server listen error()\n");
        exit(0);
    }
    printf("listen\n");
    int leng = sizeof(clientAdr);
    uint8_t* readBufAdr =&recvBuf[0];
    while(true){
        clientSocket = accept(serverSocket,(struct sockaddr*)&clientAdr,(socklen_t*)&leng);
        //D printf("accept client socket = %d\n",clientSocket);
        if(acceptChg != clientSocket){
            acceptChg = clientSocket;
            thFlag = true;
           // wrtFlag = true;
        }
        printf("accepted\n");
        if(thFlag == true){
            std::thread readData(&svrsocket::readFunc,this,clientSocket,recvBuf);
            readData.join();
            std::thread wrtData(&svrsocket::writeFunc,this,clientSocket,sendBuf);
            wrtData.join();
            thFlag = false;
        }
        printf("re\n");
        sleep(0.001);
    }


}
void svrsocket::readFunc(int clientSocket,uint8_t* recvBuf)
{
    while(true)
    {
        //read buf size is need define?(now is 10)
        recvLen = read(clientSocket, recvBuf, 10);
        printf("recv = %d\n",recvLen);
        if(recvLen > 0) {
            //write(1, buf, recvLen);
            printf("recv buf is %p %d\n\n",recvBuf,recvBuf[1]);
            //memcpy buf to list
        }
        sleep(0.001);
    }
}

void svrsocket::writeFunc(int clientSocket ,uint8_t* sendBuf)
{
    //if buf is not zero
    if(this->wrtFlag == true){
        write(clientSocket, sendBuf, sizeof(sendBuf));
        this->wrtFlag = false;
    }
    sleep(0.01);
}
