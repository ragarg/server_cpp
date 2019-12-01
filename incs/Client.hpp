#ifndef CLIENT_HPP
# define CLIENT_HPP
# include "header.hpp"

class Client
{
    public:
        ~Client();
        Client(char *nickname, TCPSocketPtr socket);
        bool CheckSocket(TCPSocketPtr socket);
        bool CheckNickname();
        void UpdateNickname(char *new_nickname);
        TCPSocketPtr GetSocket() const {return (socket);}
    private:
        char *nickname;
        TCPSocketPtr socket;
};
typedef shared_ptr<Client> ClientPtr;

#endif