#ifndef IUNKNOWN_H
#define IUNKNOWN_H
#include "OBJBASE.h"
class IUnknown
{
public:
    virtual HRESULT_ QueryInterface(IID_, void**) = 0;
    virtual ULONG_ AddRef() = 0;
    virtual ULONG_ Release() = 0;
};

class IX : public IUnknown
{
public:
    virtual int Nok() = 0;
};

class IY : public IUnknown
{
public:
    virtual int Nod() = 0;
};

class IClassFactory : public IUnknown
{
public:
    virtual HRESULT_ CreateInstance(IID_, void**) = 0;
};

class IClassFactory2: public IClassFactory
{
public:
    virtual HRESULT_ CreateInstance2(IID_, void**, int, int) = 0;
};
#endif