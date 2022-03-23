#ifndef SERVER_H
#define SERVER_H
#include "IUnknown.h"
#include "OBJBASE.h"
class Server : public IX, public IY
{
public:
    Server();
    ~Server();
    virtual int Func1();
    virtual int Func2();
    HRESULT_ QueryInterface(IID_, void**);
};
#endif

class ServerFactory : public IClassFactory
{
public:
    ServerFactory();
    ~ServerFactory();
    HRESULT_ CreateInstance(IID_, void**);
    HRESULT_ QueryInterface(IID_, void**);
};