#include <iostream>
#include "Server2.h"
#include "OBJBASE.h"
using namespace std;

Server2::Server2() {};
Server2::~Server2() {};

int Server2::Func2()
{
    return 22;
}

HRESULT_ Server2::QueryInterface(IID_ IID, void** ppv)
{
    switch (IID)
    {
    case IID_IUNKNOWN:
        *ppv = (IUnknown*)(IY*)ppv;
        cout << "Server2.QueryInterface: IUnknown connected." << endl;
        break;
    case IID_IY:
        *ppv = (IY*)this;
        cout << "Server2.QueryInterface: IY connected." << endl;
        break;
    default:
        *ppv = NULL;
        cout << "Server2.QueryInterface: Invalid interface" << endl;
        return S_FAIL;
    }
    return S_OK;
}

Server2Factory::Server2Factory() {};
Server2Factory::~Server2Factory() {};

HRESULT_ Server2Factory::CreateInstance(IID_ IID, void** ppv)
{
    Server2* server2 = new Server2;
    cout << "Server2.CreateInstance: Server2 connected." << endl;
    return server2->QueryInterface(IID, ppv);
};

HRESULT_ Server2Factory::QueryInterface(IID_ IID, void** ppv)
{
    switch (IID)
    {
    case IID_ICLASSFACTORY:
        cout << "Server2Factory.QueryInterface: IClassFactory connected." << endl;
        *ppv = (IClassFactory*)this;
        break;
    default:
        cout << "Server2Factory.QueryInterface: Invalid interface" << endl;
        *ppv = NULL;
        return S_FAIL;
    }
    return S_OK;
}
