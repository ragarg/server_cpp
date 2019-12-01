#include "header.hpp"

bool gIsGameRunning = 1;

void DoTCPLoop()
{
    TCPSocketPtr listenSocket = SocketUtil::CreateTCPSocket(INET);
    SocketAddress receivingAddres(INADDR_ANY, 48002);
    if( listenSocket->Bind(receivingAddres ) != NO_ERROR)
    {
        return;
    }
    if( listenSocket->Listen() != NO_ERROR)
    {
        return;
    }
    vector<TCPSocketPtr> readBlockSockets;
    readBlockSockets.push_back(listenSocket);
    vector<TCPSocketPtr> readableSockets;
    Room room;
    while(gIsGameRunning)
    {
        if(SocketUtil::Select(&readBlockSockets, &readableSockets,
        nullptr, nullptr,
        nullptr, nullptr))
        {
            for(const TCPSocketPtr& socket : readableSockets)
            {
                if(socket == listenSocket)
                {
                    SocketAddress newClientAddress;
                    auto newSocket = listenSocket->Accept(newClientAddress);
                    readBlockSockets.push_back(newSocket);
                    room.AddClient(newSocket, newClientAddress);
                }
                else
                {
                    room.UpdateClients(socket);
                }
            }
        }
    }
}
