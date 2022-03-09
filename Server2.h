#ifndef SERVER2_H
#define SERVER2_H
#include "IY.h"
#include "OBJBASE.h"
class Server2 : public IY
{
private:
    int a;
    int b;
public:
    Server2();
    ~Server2();
    virtual int Func2();
    HRESULT_ QueryInterface(int, void**);
};
#endif