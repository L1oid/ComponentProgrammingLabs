#include <iostream>
#include "Server.h"
#include "OBJBASE.h"
using namespace std;

Server::Server() {};
Server::~Server() {};

int Server::Func1()
{
    return 11;
}

int Server::Func2()
{
    return 12;
}

HRESULT_ Server::QueryInterface(IID_ IID, void** ppv) 
{
    switch (IID)
    {
    case IID_IUNKNOWN:
        *ppv = (IUnknown*)(IX*)ppv;
        cout << "Server.QueryInterface: IUnknown connected." << endl;
        break;
    case IID_IX:
        *ppv = (IX*)this;
        cout << "Server.QueryInterface: IX connected." << endl;
        break;
    case IID_IY:
        *ppv = (IY*)this;
        cout << "Server.QueryInterface: IY connected." << endl;
        break;
    default:
        *ppv = NULL;
        cout << "Server.QueryInterface: Invalid interface" << endl;
        return S_FAIL;
    }
    return S_OK;
}

ServerFactory::ServerFactory() {};
ServerFactory::~ServerFactory() {};

HRESULT_ ServerFactory::CreateInstance(IID_ IID, void** ppv)
{
    Server* server = new Server;
    cout << "Server.CreateInstance: Server connected." << endl;
    return server->QueryInterface(IID, ppv);
};

HRESULT_ ServerFactory::QueryInterface(IID_ IID, void** ppv)
{
    switch (IID)
    {
    case IID_ICLASSFACTORY:
        cout << "ServerFactory.QueryInterface: IClassFactory connected." << endl;
        *ppv = (IClassFactory*)this;
        break;
    default:
        cout << "ServerFactory.QueryInterface: Invalid interface" << endl;
        *ppv = NULL;
        return S_FAIL;
    }
    return S_OK;
};