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
        void UpdateNickname(char *new_nickname, unsigned int len);
        TCPSocketPtr GetSocket() const {return (socket);}
    private:
        friend class Room;
        char *nickname;
        unsigned int len_nickname;
        TCPSocketPtr socket;
};
typedef shared_ptr<Client> ClientPtr;

#endif