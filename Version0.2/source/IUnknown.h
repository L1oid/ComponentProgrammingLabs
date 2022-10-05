#ifndef IUNKNOWN_H
#define IUNKNOWN_H
#include "OBJBASE.h"
class IUnknown_
{
public:
    virtual HRESULT_ QueryInterface_(IID_, void**) = 0;
    virtual ULONG_ AddRef_() = 0;
    virtual ULONG_ Release_() = 0;
};

class IX : public IUnknown_
{
public:
    virtual int Nok() = 0;
    virtual int Nod() = 0;
};

class IY : public IUnknown_
{
public:
    virtual int Sum() = 0;
};

class IClassFactory_ : public IUnknown_
{
public:
    virtual HRESULT_ CreateInstance_(IID_, void**) = 0;
};

class IClassFactory2_ : public IUnknown_
{
public:
    virtual HRESULT_ CreateInstance2_(IID_, void**, int, int) = 0;
};
#endif