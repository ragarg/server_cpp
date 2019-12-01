#include "header.hpp"

SocketAddressPtr SocketAddressFactory::CreateIPv4FromString(const string& inString)
{
    auto pos = inString.find_last_of(':');
    string host, service;
    if(pos != string::npos)
    {
        host = inString.substr(0, pos);
        service = inString.substr(pos + 1);
    }
    else
    {
        host = inString;
        // использовать порт по умолчанию...
        service = "0";
    }
    addrinfo hint;
    ft_memset(&hint, 0, sizeof(hint));
    hint.ai_family = AF_INET;
    addrinfo* result;
    int error = getaddrinfo(host.c_str(), service.c_str(), &hint, &result);
    addrinfo* initResult = result;
    if(error != 0 && result != nullptr)
    {
        freeaddrinfo(initResult);
        return nullptr;
    }
    while(!result->ai_addr && result->ai_next)
        result = result->ai_next;
    if(!result->ai_addr)
    {
        freeaddrinfo(initResult);
        return nullptr;
    }
    auto toRet = std::make_shared< SocketAddress >(*result->ai_addr);
    freeaddrinfo(initResult);
    return (toRet);
}