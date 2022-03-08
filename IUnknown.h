#ifndef IUNKNOWN_H
#define IUNKNOWN_H
class IUnknown
{
public:
    virtual int QueryInterface(int, void**) = 0;
};
#endif