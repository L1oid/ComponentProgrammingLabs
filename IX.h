#ifndef IX_H
#define IX_H
#include "IUnknown.h"
#include "OBJBASE.h"
class IX : public IUnknown
{
public:
    virtual int Func1() = 0;
    virtual int Func2() = 0;
};
#endif