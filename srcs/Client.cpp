#include "header.hpp"

Client::~Client()
{
    socket->~TCPSocket();
}

Client::Client(char *inNickname, TCPSocketPtr inSocket)
{
    nickname = inNickname;
    socket = inSocket;
}

bool Client::CheckSocket(TCPSocketPtr inSocket)
{
    return (socket == inSocket);
}

void    Client::UpdateNickname(char *new_nickname)
{
    nickname = new_nickname;
}

bool    Client::CheckNickname()
{
    return (nickname);
}
