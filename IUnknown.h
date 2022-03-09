#ifndef IUNKNOWN_H
#define IUNKNOWN_H
#include "OBJBASE.h"
class IUnknown
{
public:
    virtual HRESULT_ QueryInterface(IID_, void**) = 0;
};
#endif