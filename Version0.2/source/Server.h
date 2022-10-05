#ifndef SERVER_H
#define SERVER_H
#include "IUnknown.h"
#include "OBJBASE.h"
class Server : public IX
{
private:
    int a, b, result;
    long m_cRef_;
public:
    Server();
    Server(int, int);
    ~Server();
    HRESULT_ QueryInterface_(IID_, void**);
    ULONG_ AddRef_();
    ULONG_ Release_();

    virtual int Nok();
    virtual int Nod();
};

class ServerMod : public IX, public IY
{
private:
    Server* ServerDefautlt;
    int a, b, result;
    long m_cRef_;
public:
    ServerMod();
    ~ServerMod();
    HRESULT_ QueryInterface_(IID_, void**);
    ULONG_ AddRef_();
    ULONG_ Release_();

    virtual int Nok();
    virtual int Nod();
    virtual int Sum();

};

class ServerFactory : public IClassFactory2_
{
private:
    long m_cRef_;
public:
    ServerFactory();
    ~ServerFactory();
    HRESULT_ CreateInstance_(IID_, void**);
    HRESULT_ CreateInstance2_(IID_, void**, int, int);
    HRESULT_ QueryInterface_(IID_, void**);
    ULONG_ AddRef_();
    ULONG_ Release_();
};

class ServerModFactory : public IClassFactory_
{
private:
    long m_cRef_;
public:
    ServerModFactory();
    ~ServerModFactory();
    HRESULT_ CreateInstance_(IID_, void**);
    HRESULT_ CreateInstance2_(IID_, void**, int, int);
    HRESULT_ QueryInterface_(IID_, void**);
    ULONG_ AddRef_();
    ULONG_ Release_();
};
#endif