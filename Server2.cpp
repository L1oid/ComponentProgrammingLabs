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
    return 2;
}

int Server2::QueryInterface(int IID, void** ppv)
{
    switch (IID)
    {
    case 0:
        cout << "Server2QueryInterface: return IUnknown" << endl;
        system("pause");
        *ppv = (IUnknown*)(IY*)ppv;
        break;
    case 2:
        cout << "Server2QueryInterface: return IY" << endl;
        system("pause");
        *ppv = (IY*)this;
        break;
    default:
        cout << "Server2QueryInterface: Invalid interface" << endl;
        system("pause");
        *ppv = NULL;
        return 1;
    }
    return 0;
}