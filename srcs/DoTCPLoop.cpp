#include "header.hpp"
#include <iostream>
#include <fstream>

bool gIsGameRunning = 1;

void DoTCPLoop()
{
    int buffer[1501];
    TCPSocketPtr listenSocket = SocketUtil::CreateTCPSocket(INET);
    if (Connect(listenSocket))
    {
        return ;
    }
    int fd = open("cha", O_WRONLY);
    printf("fd = %d\n", fd);
    int fd2 = open("ch", O_RDONLY);
    printf("fd = %d\n", fd2);
    int bite = 0;
    string s;
    while(gIsGameRunning)
    {
        char ch;
        int d;
        if(read(fd2, &ch, 1) > 0)
        {
            s.push_back(ch);
            printf("n = %c\n", ch);
            printf("str = %s, %d\n", &s.front(), (int)(s.size()));
            if (ch == '\n')
            {
                s[bite] = 0;
                printf("str = %s, %d\n", &s.front(), (int)(s.size()));
                printf("bite = %d\n", bite);
                if (!strcmp(&s.front(), "exit"))
                {
                    delete listenSocket.get();
                    close(fd);
                    return ;
                }
                listenSocket->Send(&s.front(), s.size());
                bite = 0;
                s.clear();
            }
            else
                bite++;
        }
        while ((d = listenSocket->Receive(buffer, 1500))> 0)
        {
            printf("mass: %s %d\n", (char*)buffer, d);
            printf("size = %d\n", (int)write(fd, buffer, d - 1));
            write(fd, "\n", 1);
        }
    }
}
