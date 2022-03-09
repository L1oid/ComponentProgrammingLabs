#ifndef SERVER_H
#define SERVER_H
#include "IX.h"
#include "IY.h"
#include "OBJBASE.h"
class Server : public IX, public IY
{
private:
    int a;
    int b;
public:
    Server();
    ~Server();
    virtual int Func1();
    virtual int Func2();
    HRESULT_ QueryInterface(int, void**);
};
#endif