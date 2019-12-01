#ifndef ROOM_HPP
# define ROOM_HPP
# include "header.hpp"
# define MAXBUFFMASSEGE 5000

typedef struct  massege
{
    char    *nickname;
    char    *massege;
}               massege;

class Room
{
    public:
        ~Room();
        Room();
        int AddMessegeToBuffer(void *buffer, unsigned int len_buffer);
        int AddClient(TCPSocketPtr socket, SocketAddress addres);
        int UpdateClients(TCPSocketPtr socket);
        ClientPtr SearchClient(TCPSocketPtr socket);
    private:
        vector<ClientPtr> clients;
        char (massege)[MAXBUFFMASSEGE];
};
#endif
