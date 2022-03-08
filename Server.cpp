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
    return 1;
}

int Server::Func2()
{
    return 2;
}

int Server::QueryInterface(int IID, void** ppv) 
{
    switch (IID) 
    {
    case 0:
        cout << "ServerQueryInterface: return IUnknown" << endl;
        system("pause");
        *ppv = (IUnknown*)(IX*)ppv;
        break;
    case 1:
        cout << "ServerQueryInterface: return IX" << endl;
        system("pause");
        *ppv = (IX*)this;
        break;
    case 2:
        cout << "ServerQueryInterface: return IY" << endl;
        system("pause");
        *ppv = (IY*)this;
        break;
    default:
        cout << "ServerQueryInterface: Invalid interface" << endl;
        system("pause");
        *ppv = NULL;
        return 1;
    }
    return 0;
}