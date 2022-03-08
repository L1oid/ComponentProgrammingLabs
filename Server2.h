#ifndef SERVER2_H
#define SERVER2_H
#include "IY.h"
class Server2 : public IY
{
private:
    int a;
    int b;
public:
    Server2();
    ~Server2();
    virtual int Func2();
    int QueryInterface(int, void**);
};
#endif