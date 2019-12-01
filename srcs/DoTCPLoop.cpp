#include "header.hpp"
#include "iostream"

bool gIsGameRunning = 1;

void DoTCPLoop()
{
    int buffer[1501];
    TCPSocketPtr listenSocket = SocketUtil::CreateTCPSocket(INET);
    SocketAddressFactory addr;
    string s;
    printf("put addr\n");
    std::getline(std::cin, s);
    SocketAddressPtr receivingAddres = addr.CreateIPv4FromString(s);
    SocketAddressPtr Addres = addr.CreateIPv4FromString("192.168.1.225:48002");
    printf("qwerqewr\n");
    if( listenSocket->Bind(*receivingAddres ) != NO_ERROR)
    {
        return;
    }
    vector<TCPSocketPtr> readBlockSockets;
    readBlockSockets.push_back(listenSocket);
    vector<TCPSocketPtr> readableSockets;
    Room room;
    printf("%d\n", listenSocket->Connect(*Addres));
    printf("qwerqewr\n");
    int d = listenSocket->Receive(buffer, 1500);
    if (d != 0)
    {
        printf("\n%d\n", d);
    }
    buffer[1500] = 0;
    printf("\n1 %s 1\n", (char*)buffer);
    listenSocket->Send("ragarg", 7);
    listenSocket->SetNonBlockingMode(1);
    while(gIsGameRunning)
    {
        std::getline(std::cin, s);
        listenSocket->Send(&s.front(), s.size() + 1);
        while ((d = listenSocket->Receive(buffer, 1500)) > 0)
        {
            printf("\n%d\n", d);
            buffer[1500] = 0;
            printf("ragarg: %s\n", (char*)buffer);
        }
    }
}
