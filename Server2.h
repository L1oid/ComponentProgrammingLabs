#ifndef SERVER_H
#define SERVER_H
#include "IServer2.h"
class Server2 : public IServer2
{
private:
    int a;
    int b;
public:
    Server2();
    ~Server2();
    int Func2();
};
#endif