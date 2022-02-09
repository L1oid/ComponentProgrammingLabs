#ifndef ISERVER_H
#define ISERVER_H
class IServer
{
public:
    virtual int Func() = 0;
};

IServer* CreateInstance(int x, int y);
#endif