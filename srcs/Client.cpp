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

void    Client::UpdateNickname(char *new_nickname, unsigned int len)
{
    nickname = strdup(new_nickname);
    len_nickname = len - 1;
}

bool    Client::CheckNickname()
{
    return (nickname);
}
