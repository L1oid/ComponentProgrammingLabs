#ifndef SERVER_H
#define SERVER_H
#include "IServer.h"
#include "IServer2.h"
class Server : public IServer, public IServer2
{
private:
    int a;
    int b;
public:
    Server();
    Server(int a_p, int b_p);
    ~Server();
    int Func();
    int Func2();
};
#endif