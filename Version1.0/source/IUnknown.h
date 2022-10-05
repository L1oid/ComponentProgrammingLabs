#ifndef IUNKNOWN_H
#define IUNKNOWN_H
#include "OBJBASE.h"
#include <windows.h>

class IX : public IUnknown
{
public:
    virtual int __stdcall LCM() = 0;
    virtual int __stdcall GCD() = 0;
};

class IY : public IUnknown
{
public:
    virtual int __stdcall Sum() = 0;
};

class IClassFactory2 : public IUnknown
{
public:
    virtual HRESULT __stdcall CreateInstance2(IUnknown*, const IID&, void**, int, int) = 0;
};
#endif