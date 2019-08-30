#include "SocketServer.h"
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

SocketServer::SocketServer(int port)
{
    server.sin_family = AF_INET; // ipv4 address
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(port);
}

void SocketServer::start()
{
    std::cout << "Starting server \n";
    bind(sock, (sockaddr *)&server, sizeof(server));
}

void SocketServer::stop()
{
    std::cout << "Stopping server \n";
    close(sock);
    end = true;
}

void SocketServer::listen()
{
    while (!end)
    {
        count = recvfrom(sock, buffer, sizeof(buffer) - 1, 0, (sockaddr *)&client, &addrlen);
        if (count > 0)
        {
            buffer[count] = 0;
            receivedmsg();
            // build the echo message
            sprintf(editedbuffer, "%d", strlen(buffer));
            sendto(sock, editedbuffer, strlen(editedbuffer), 0, (sockaddr *)&client, addrlen);
        }else{
            stop();
        }
    }
}

void SocketServer::receivedmsg()
{
    std::string viiva(strlen(buffer) + 10, '-');
    std::cout << "Address: " << inet_ntoa(client.sin_addr) << "\n"
              << "Port: " << ntohs(client.sin_port) << "\n"
              << "Message: " << buffer << "\n"
              << "Message count: " << strlen(buffer) << "\n"
              << viiva << std::endl;
}

void SocketServer::printall()
{
    //std::string val = to_string()
    std::cout << std::to_string(server.sin_family) << "\n";
    std::cout << "allowed ip:s: " << inet_ntoa(server.sin_addr) << "\n";
    std::cout << "port number: " << ntohs(server.sin_port) << "\n";
}
