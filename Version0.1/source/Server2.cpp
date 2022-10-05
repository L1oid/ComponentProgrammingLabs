#include <iostream>
#include "Server2.h"
#include "OBJBASE.h"
using namespace std;

Server2::Server2() 
{
    m_cRef = 0;
};
Server2::Server2(int a_p, int b_p) 
{
    a = a_p;
    b = b_p;
};
Server2::~Server2() 
{
    cout << "Server2.Destructor: Liquidated." << endl;
};

int Server2::Nod()
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
    return S_OK_;
}

ULONG_ Server2::AddRef() 
{
    cout << "Server2.AddRef = " << m_cRef + 1 << endl;
    return ++m_cRef; 
} 
 
ULONG_ Server2::Release() 
{ 
    cout << "Server2.Release = " << m_cRef - 1 << endl;
    if(--m_cRef == 0)
    {
        delete this;
        return 0;
    }
    return m_cRef;
}


Server2Factory::Server2Factory() 
{
    m_cRef = 0;
};
Server2Factory::~Server2Factory() 
{
    cout << "Server2Factory.Destructor: Liquidated." << endl;
};

HRESULT_ Server2Factory::CreateInstance(IID_ IID, void** ppv)
{
    Server2* server2 = new Server2;
    cout << "Server2.CreateInstance: Server2 connected." << endl;
    return server2->QueryInterface(IID, ppv);
};

HRESULT_ Server2Factory::CreateInstance2(IID_ IID, void** ppv, int num1, int num2)
{
    Server2* server2 = new Server2(num1, num2);
    cout << "Server2.CreateInstance2: Server2 connected." << endl;
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
    case IID_ICLASSFACTORY2:
        cout << "Server2Factory.QueryInterface: IClassFactory2 connected." << endl;
        *ppv = (IClassFactory2*)this;
        break;
    default:
        cout << "Server2Factory.QueryInterface: Invalid interface" << endl;
        *ppv = NULL;
        return S_FAIL;
    }
    return S_OK_;
}

ULONG_ Server2Factory::AddRef() 
{ 
    cout << "Server2Factory.AddRef = " << m_cRef + 1 << endl;
    return ++m_cRef; 
} 
 
ULONG_ Server2Factory::Release() 
{ 
    cout << "Server2Factory.Release = " << m_cRef - 1 << endl;
    if(--m_cRef == 0)
    {
        delete this;
        return 0;
    }
    return m_cRef;
}
