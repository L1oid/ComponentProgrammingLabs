#ifndef SERVER_H
#define SERVER_H
#include "IUnknown.h"
#include "OBJBASE.h"
class Server : public IX, public IY
{
private:
    long m_cRef;
public:
    Server();
    ~Server();
    virtual int Func1();
    virtual int Func2();
    HRESULT_ QueryInterface(IID_, void**);
    ULONG_ AddRef();
    ULONG_ Release();
};
#endif

class ServerFactory : public IClassFactory
{
private:
    long m_cRef;
public:
    ServerFactory();
    ~ServerFactory();
    HRESULT_ CreateInstance(IID_, void**);
    HRESULT_ QueryInterface(IID_, void**);
    ULONG_ AddRef();
    ULONG_ Release();
};