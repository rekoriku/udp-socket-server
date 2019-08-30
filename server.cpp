#include "SocketServer.h"

int checkArg(int argc,char *argv[]); // forward declaration
int main(int argc, char *argv[])
{
    int port = checkArg(argc, argv);
    SocketServer* servu = new SocketServer(port);
    //servu->server.sin_port = htons(4500);
    
    servu->start();
    servu->listen();
    //servu->printall();
    //servu->stop();
};

int checkArg(int argc, char *argv[]){
 if (argc < 2) {
         int port = 5000;
         fprintf(stderr,"ERROR, no port provided, port set to 5000 \n");
         return port;
     }else {
         int port = std::stoi(argv[1]);
         return port;
     }
};
