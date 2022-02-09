#ifndef SERVER_H
#define SERVER_H
#include "IServer.h"
class Server : public IServer
{
private:
    int a;
    int b;
public:
    Server();
    Server(int a_p, int b_p);
    ~Server();
    int Func();
};
#endif