#ifndef SERVER2_H
#define SERVER2_H
#include "IUnknown.h"
#include "OBJBASE.h"
class Server2 : public IY
{
private:
    int a, b, result;
    long m_cRef;
public:
    Server2();
    Server2(int, int);
    ~Server2();
    virtual int Nod();
    HRESULT_ QueryInterface(IID_, void**);
    ULONG_ AddRef();
    ULONG_ Release();
};
#endif

class Server2Factory : public IClassFactory2
{
private:
    long m_cRef;
public:
    Server2Factory();
    ~Server2Factory();
    HRESULT_ CreateInstance(IID_, void**);
    HRESULT_ CreateInstance2(IID_, void**, int, int);
    HRESULT_ QueryInterface(IID_, void**);
    ULONG_ AddRef();
    ULONG_ Release();
};