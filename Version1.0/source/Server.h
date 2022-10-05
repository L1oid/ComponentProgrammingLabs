#ifndef SERVER_H
#define SERVER_H
#include "IUnknown.h"
#include <windows.h>
#include "OBJBASE.h"
class Server : public IX
{
private:
    int a, b, result;
    long m_cRef;
public:
    Server();
    Server(int, int);
    virtual ~Server();
    virtual HRESULT __stdcall QueryInterface(const IID&, void**);
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();

    virtual int __stdcall LCM();
    virtual int __stdcall GCD();
};

class ServerMod : public IX, public IY
{
private:
    Server* ServerDefautlt;
    int a, b, result;
    long m_cRef;
public:
    ServerMod();
    virtual ~ServerMod();
    virtual HRESULT __stdcall QueryInterface(const IID&, void**);
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();

    virtual int __stdcall LCM();
    virtual int __stdcall GCD();
    virtual int __stdcall Sum();

};

class ServerFactory : public IClassFactory2
{
private:
    long m_cRef;
public:
    ServerFactory();
    virtual ~ServerFactory();
    virtual HRESULT __stdcall CreateInstance(IUnknown*, const IID&, void**);
    virtual HRESULT __stdcall CreateInstance2(IUnknown*, const IID&, void**, int, int);
    virtual HRESULT __stdcall QueryInterface(const IID&, void**);
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();
    virtual HRESULT __stdcall LockServer(BOOL bLock);
};

class ServerModFactory : public IClassFactory
{
private:
    long m_cRef;
public:
    ServerModFactory();
    virtual ~ServerModFactory();
    virtual HRESULT __stdcall CreateInstance(IUnknown*, const IID&, void**);
    virtual HRESULT __stdcall QueryInterface(const IID&, void**);
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();
    virtual HRESULT __stdcall LockServer(BOOL bLock);
};
#endif