#include <netinet/in.h>
#include <string>

class SocketServer
{
public:
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in server, client;

    int count;
    bool end = false;

    char buffer[100];
    char editedbuffer[100];
    socklen_t addrlen = sizeof(sockaddr_in);

    SocketServer(int);
    void start();
    void stop();
    void listen();
    void printall();
    void receivedmsg();
};