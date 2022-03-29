#ifndef SERVER2_H
#define SERVER2_H
#include "IUnknown.h"
#include "OBJBASE.h"
class Server2 : public IY
{
private:
    long m_cRef;
public:
    Server2();
    ~Server2();
    virtual int Func2();
    HRESULT_ QueryInterface(IID_, void**);
    ULONG_ AddRef();
    ULONG_ Release();
};
#endif

class Server2Factory : public IClassFactory
{
private:
    long m_cRef;
public:
    Server2Factory();
    ~Server2Factory();
    HRESULT_ CreateInstance(IID_, void**);
    HRESULT_ QueryInterface(IID_, void**);
    ULONG_ AddRef();
    ULONG_ Release();
};