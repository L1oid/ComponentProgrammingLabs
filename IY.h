#ifndef IY_H
#define IY_H
#include "IUnknown.h"
#include "OBJBASE.h"
class IY : public IUnknown
{
public:
    virtual int Func2() = 0;
};
#endif