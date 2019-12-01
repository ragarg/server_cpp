#include "header.hpp"

SocketAddress::SocketAddress(uint32_t inAddress, uint16_t inPort)
{
    GetAsSockAddrIn()->sin_family = AF_INET;
    GetAsSockAddrIn()->sin_addr.s_addr = htonl(inAddress);
    GetAsSockAddrIn()->sin_port = htons(inPort);
}

SocketAddress::SocketAddress(const sockaddr& inSockAddr)
{
    memcpy(&mSockAddr, &inSockAddr, sizeof(sockaddr));
}

SocketAddress::SocketAddress()
{
	GetAsSockAddrIn()->sin_family = AF_INET;
	GetIP4Ref() = INADDR_ANY;
	GetAsSockAddrIn()->sin_port = 0;
}

sockaddr_in* SocketAddress::GetAsSockAddrIn()
{
    return reinterpret_cast<sockaddr_in*>( &mSockAddr );
}
