#include "header.hpp"

Room::Room()
{
}

Room::~Room()
{
}

int         Room::AddClient(TCPSocketPtr socket, SocketAddress addres)
{
    ClientPtr client = ClientPtr(new Client(nullptr, socket));

    clients.push_back(client);
    string mass = "Input your nickname, pls!";
    client->GetSocket()->Send(&(mass.front()), mass.size());
    return (0);
}

int         Room::UpdateClients(TCPSocketPtr socket)
{
    ClientPtr client = SearchClient(socket);
    char segment[1500];
    int dataReceived;

    if (client)
    {
        dataReceived = socket->Receive(segment, 1500);
        if (dataReceived > 0)
        {
            if (client->CheckNickname())
            {
                AddMessegeToBuffer(segment, dataReceived);
                return(0);
            }
            else
            {
                client->UpdateNickname((char*)segment);
                return(1);
            }
        }
    }
    return (-1);
}

int         Room::AddMessegeToBuffer(void *buffer, unsigned int len_buffer)
{
    for (auto &client: clients)
    {
        if (client->CheckNickname())
            client->GetSocket()->Send(buffer, len_buffer);
    }
    return (0);
}

ClientPtr   Room::SearchClient(TCPSocketPtr socket)
{
    for (auto &client: clients)
    {
        if (client->CheckSocket(socket))
            return (client);
    }
    return (nullptr);
}
