#ifndef ISERVER2_H
#define ISERVER2_H
class IServer2
{
public:
    virtual int Func2() = 0;
};

IServer2* CreateInstance2(int x, int y);
#endif