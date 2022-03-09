#include <iostream>
#include "Server2.h"
using namespace std;

Server2::Server2()
{
    a = 0;
    b = 0;
}

Server2::~Server2() {};

int Server2::Func2()
{
    return 22;
}

int Server2::QueryInterface(int IID, void** ppv)
{
    switch (IID)
    {
    case 0:
        cout << "Server2.QueryInterface: return IUnknown" << endl;
        *ppv = (IUnknown*)(IY*)ppv;
        break;
    case 2:
        cout << "Server2.QueryInterface: return IY" << endl;
        *ppv = (IY*)this;
        break;
    default:
        cout << "Server2.QueryInterface: Invalid interface" << endl;
        *ppv = NULL;
        return 1;
    }
    return 0;
}