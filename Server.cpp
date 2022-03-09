#include <iostream>
#include "Server.h"
using namespace std;

Server::Server()
{
    a = 0;
    b = 0;
}

Server::~Server() {};

int Server::Func1()
{
    return 11;
}

int Server::Func2()
{
    return 12;
}

int Server::QueryInterface(int IID, void** ppv) 
{
    switch (IID) 
    {
    case 0:
        cout << "Server.QueryInterface: return IUnknown" << endl;
        *ppv = (IUnknown*)(IX*)ppv;
        break;
    case 1:
        cout << "Server.QueryInterface: return IX" << endl;
        *ppv = (IX*)this;
        break;
    case 2:
        cout << "Server.QueryInterface: return IY" << endl;
        *ppv = (IY*)this;
        break;
    default:
        cout << "Server.QueryInterface: Invalid interface" << endl;
        *ppv = NULL;
        return 1;
    }
    return 0;
}