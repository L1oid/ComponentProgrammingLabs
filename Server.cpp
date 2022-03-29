#include <iostream>
#include "Server.h"
#include "OBJBASE.h"
using namespace std;

Server::Server() 
{
    m_cRef = 0;
};
Server::~Server() 
{
    cout << "Server.Destructor: Liquidated." << endl;
};

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
    reinterpret_cast<IUnknown*>(*ppv)->AddRef();
    return S_OK;
}

ULONG_ Server::AddRef() 
{ 
    cout << "Server.AddRef = " << m_cRef + 1 << endl;
    return ++m_cRef; 
} 
 
ULONG_ Server::Release()
{ 
    cout << "Server.Release = " << m_cRef - 1 << endl;
    if(--m_cRef == 0)
    {
        delete this;
        return 0;
    }
    return m_cRef;
}

ServerFactory::ServerFactory() 
{
    m_cRef = 0;
};
ServerFactory::~ServerFactory() 
{
    cout << "ServerFactory.Destructor: Liquidated." << endl;
};

HRESULT_ ServerFactory::CreateInstance(IID_ IID, void** ppv)
{
    Server* server = new Server;
    cout << "Server.CreateInstance: Server connected." << endl;
    server->AddRef();
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
    reinterpret_cast<IUnknown*>(*ppv)->AddRef();
    return S_OK;
};

ULONG_ ServerFactory::AddRef() 
{ 
    cout << "ServerFactory.AddRef = " << m_cRef + 1 << endl;
    return ++m_cRef; 
} 
 
ULONG_ ServerFactory::Release() 
{ 
    cout << "ServerFactory.Release = " << m_cRef - 1 << endl;
    if(--m_cRef == 0)
    {
        delete this;
        return 0;
    }
    return m_cRef;
}