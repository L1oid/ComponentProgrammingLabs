#ifndef SERVER_H
#define SERVER_H
#include "IUnknown.h"
#include "OBJBASE.h"
class Server : public IX, public IY
{
private:
    int a, b, result;
    long m_cRef;
public:
    Server();
    Server(int, int);
    ~Server();
    virtual int Nok();
    virtual int Nod();
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
    HRESULT_ CreateInstance2(IID_, void**, int, int);
    HRESULT_ QueryInterface(IID_, void**);
    ULONG_ AddRef();
    ULONG_ Release();
};