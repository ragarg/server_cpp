#ifndef TCPSOCKET_HPP
# define TCPSOCKET_HPP
#include "header.hpp"

class TCPSocket
{
    public:
        ~TCPSocket();
        int     Connect(const SocketAddress& inAddress);
        int     Bind(const SocketAddress& inToAddress);
        int     Listen(int inBackLog = 32);
        shared_ptr<TCPSocket> Accept(SocketAddress& inFromAddress);
        int     Send(const void* inData, int inLen);
        int     Receive(void* inBuffer, int inLen);
        bool    operator==(const TCPSocket &first);
        SOCKET mSocket;
    private:
        friend class SocketUtil;
        TCPSocket(SOCKET inSocket) : mSocket(inSocket) {}
};
typedef shared_ptr<TCPSocket> TCPSocketPtr;

#endif
