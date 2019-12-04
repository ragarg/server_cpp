#include "header.hpp"

int Connect(TCPSocketPtr socket)
{
    int buffer[1501];
    SocketAddressFactory addr;
    string s;
    printf("put addr\n");
    std::getline(std::cin, s);
    SocketAddressPtr Addres;
    if (!(Addres = addr.CreateIPv4FromString(s)))
    {
        printf("ERROR: IP");
        return (-1);
    }
    if (socket->Connect(*Addres))
    {
        printf("ERROR: CONNECT");
        return (-2);
    }
    if (socket->Receive(buffer, 1500) < 0)
    {
        printf("ERROR: RECEIVE");
        return (-3);
    }
    buffer[1500] = 0;
    printf("\n1 %s 1\n", (char*)buffer);
    std::getline(std::cin, s);
    if (socket->Send(&s.front(), s.size() + 1) < 0)
    {
        printf("ERROR: SEND");
        return (-4);
    }
    socket->SetNonBlockingMode(1);
    return (0);
}
