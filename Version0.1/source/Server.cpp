#include <iostream>
#include "Server.h"
#include "OBJBASE.h"
using namespace std;

Server::Server() 
{
    m_cRef = 0;
};
Server::Server(int a_p, int b_p) 
{
    a = a_p;
    b = b_p;
};
Server::~Server() 
{
    cout << "Server.Destructor: Liquidated." << endl;
};

int Server::Nok()
{
    result = (a * b) / Nod();
	return result;
}

int Server::Nod()
{
    result = 0;
	for (int i = a; i > 0; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			result = i;
			break;
		}
	}
	return result;
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
    return S_OK_;
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
    return server->QueryInterface(IID, ppv);
};

HRESULT_ ServerFactory::CreateInstance2(IID_ IID, void** ppv, int num1, int num2)
{
    Server* server = new Server(num1, num2);
    cout << "Server.CreateInstance2: Server connected." << endl;
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
    case IID_ICLASSFACTORY2:
        cout << "ServerFactory.QueryInterface: IClassFactory2 connected." << endl;
        *ppv = (IClassFactory2*)this;
        break;
    default:
        cout << "ServerFactory.QueryInterface: Invalid interface" << endl;
        *ppv = NULL;
        return S_FAIL;
    }
    reinterpret_cast<IUnknown*>(*ppv)->AddRef();
    return S_OK_;
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