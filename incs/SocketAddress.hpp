#ifndef SOCKETADDRESS_HPP
# define SOCKETADDRESS_HPP
# include <header.hpp>

class SocketAddress
{
    public:
    SocketAddress(uint32_t inAddress, uint16_t inPort);
    SocketAddress(const sockaddr& inSockAddr);
    SocketAddress();
    size_t GetSize() const {return sizeof( sockaddr );}
    
    private:
    friend class UDPSocket;
	friend class TCPSocket;
#if _WIN32
	uint32_t&				GetIP4Ref()					{ return *reinterpret_cast< uint32_t* >( &GetAsSockAddrIn()->sin_addr.S_un.S_addr ); }
#else
	uint32_t&				GetIP4Ref()					{ return GetAsSockAddrIn()->sin_addr.s_addr; }
#endif
    sockaddr mSockAddr;
    sockaddr_in* GetAsSockAddrIn();
};
typedef shared_ptr<SocketAddress> SocketAddressPtr;

#endif
