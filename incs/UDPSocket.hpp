#ifndef UDPSOCKET_HPP
# define UDPSOCKET_HPP
#include "header.hpp"

class UDPSocket
{
    public:
        ~UDPSocket();
        int Bind(const SocketAddress& inToAddress);
        int SendTo(const void* inData, int inLen, const SocketAddress& inTo);
        int ReceiveFrom(void* inBuffer, int inLen, SocketAddress& outFrom);
        int SetNonBlockingMode(bool inShouldBeNonBlocking);
    private:
        friend class SocketUtil;
        UDPSocket(SOCKET inSocket) : mSocket(inSocket) {}
        SOCKET mSocket;
};
typedef shared_ptr<UDPSocket> UDPSocketPtr;

#endif
