#include <iostream>
#include <windows.h>
#include <fstream>
#include "Server.h"
#include <vector>
#include "OBJBASE.h"

using namespace std;

long global_m_cRef;
IClassFactory2* pFGlobal = NULL;

extern "C" HRESULT __declspec(dllexport) __stdcall DllGetClassObject(const CLSID& CLSID, const IID& IID, void** ppv)
{
    cout << "BeforeDLLGET" << endl;
    IUnknown* pIUnknown = NULL;
    if (CLSID == CLSID_Server)
    {
        pIUnknown = (IUnknown*) new ServerFactory;
        cout << "DllGetClassObject: ServerFactory connected." << endl;
    }
    else if (CLSID == CLSID_ServerMod)
    {
        pIUnknown = (IUnknown*) new ServerModFactory;
        cout << "DllGetClassObject: ServerModFactory connected." << endl;    
    }
    else
    {
        cout << "DllGetClassObject: connection error." << endl;
        return S_FALSE; 
    }
    HRESULT resTmp = pIUnknown->QueryInterface(IID, ppv);
    cout << "AfterDLLGET" << endl;
    return resTmp;
}

extern "C"  HRESULT __declspec(dllexport) __stdcall DllRegisterServer(void) {};

extern "C"  HRESULT __declspec(dllexport) __stdcall DllUnregisterServer() {};

extern "C" HRESULT __declspec(dllexport) __stdcall DllCanUnloadNow()
{
    if(global_m_cRef == 0)
    {
        return S_OK;
    }
    else return S_FALSE;
}
 
Server::Server() 
{
    m_cRef = 0;
    cout << "Server.Constructor: Created." << endl;
};
Server::Server(int a_p, int b_p) 
{
    a = a_p;
    b = b_p;
    m_cRef = 0;
    cout << "Server.Constructor: Created." << endl;
};
Server::~Server() 
{
    cout << "Server.Destructor: Liquidated." << endl;
};

int __stdcall Server::LCM()
{
    result = (a * b) / GCD();
	return result;
}

int __stdcall Server::GCD()
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

HRESULT __stdcall Server::QueryInterface(const IID& IID, void** ppv) 
{
    if (IID == IID_IUnknown)
    {
        *ppv = (IUnknown*)(IX*)ppv;
        cout << "Server.QueryInterface: IUnknown connected." << endl;
    }
    else if (IID == IID_IX)
    {
        *ppv = (IX*)this;
        cout << "Server.QueryInterface: IX connected." << endl;
    }
    else if (IID == IID_IY)
    {
        *ppv = (IY*)this;
        cout << "Server.QueryInterface: IY connected." << endl;
    }
    else
    {
        *ppv = NULL;
        cout << "Server.QueryInterface: Invalid interface" << endl;
        return S_FALSE;
    }
    reinterpret_cast<IUnknown*>(*ppv)->AddRef();
    return S_OK;
}

ULONG __stdcall Server::AddRef() 
{ 
    cout << "Server.AddRef = " << m_cRef + 1 << endl;
    cout << "Server.GlobalAddRef = " << global_m_cRef + 1 << endl;
    ++global_m_cRef;
    return ++m_cRef; 
} 
 
ULONG __stdcall Server::Release()
{ 
    cout << "Server.Release = " << m_cRef - 1 << endl;
    if(global_m_cRef != 0)
    {
        cout << "Server.GloblaRelease = " << global_m_cRef - 1 << endl;
        --global_m_cRef;
    }
    if(--m_cRef == 0)
    {
        delete this;
        return 0;
    }
    return m_cRef;
}

ServerMod::ServerMod() 
{
    m_cRef = 0;
    cout << "ServerMod.Constructor: Created." << endl;
    IClassFactory2* pF = NULL;
    CoGetClassObject(CLSID_Server, CLSCTX_INPROC_SERVER, NULL, IID_IClassFactory2, (void**)&pF);
    IX* pX = NULL;
    pF->CreateInstance2(NULL, IID_IX, (void**)&ServerDefautlt, 3, 6);
    pF->Release();
};


ServerMod::~ServerMod() 
{
    cout << "ServerMod.Destructor: Liquidated." << endl;
};

HRESULT __stdcall ServerMod::QueryInterface(const IID& IID, void** ppv) 
{
    if (IID == IID_IUnknown)
    {
        *ppv = (IUnknown*)(IX*)ppv;
        cout << "ServerMod.QueryInterface: IUnknown connected." << endl;
    }
    else if (IID == IID_IX)
    {
        *ppv = (IX*)this;
        cout << "ServerMod.QueryInterface: IX connected." << endl;
    }
    else if (IID == IID_IY)
    {
        *ppv = (IY*)this;
        cout << "ServerMod.QueryInterface: IY connected." << endl;
    }
    else
    {
        *ppv = NULL;
        cout << "ServerMod.QueryInterface: Invalid interface" << endl;
        return S_FALSE;
    }
    reinterpret_cast<IUnknown*>(*ppv)->AddRef();
    return S_OK;
}

ULONG __stdcall ServerMod::AddRef() 
{ 
    cout << "ServerMod.AddRef = " << m_cRef + 1 << endl;
    cout << "ServerMod.GlobalAddRef = " << global_m_cRef + 1 << endl;
    ++global_m_cRef;
    return ++m_cRef; 
} 
 
ULONG __stdcall ServerMod::Release()
{ 
    cout << "ServerMod.Release = " << m_cRef - 1 << endl;
    ServerDefautlt->Release();
    if(global_m_cRef != 0)
    {
        cout << "ServerMod.GloblaRelease = " << global_m_cRef - 1 << endl;
        --global_m_cRef;
    }
    if(--m_cRef == 0)
    {
        delete this;
        return 0;
    }
    return m_cRef;
}

int __stdcall ServerMod::LCM()
{
    return ServerDefautlt->LCM();
}

int __stdcall ServerMod::GCD()
{
    return ServerDefautlt->GCD();
}

int __stdcall ServerMod::Sum()
{
    return LCM() + GCD();
}

ServerFactory::ServerFactory() 
{
    m_cRef = 0;
    cout << "ServerFactory.Constructor: Created." << endl;
};
ServerFactory::~ServerFactory() 
{
    cout << "ServerFactory.Destructor: Liquidated." << endl;
};

HRESULT __stdcall ServerFactory::CreateInstance(IUnknown* pUnknownOuter, const IID& IID, void** ppv)
{
    if (pUnknownOuter != NULL)
    {
        return E_NOTIMPL;
    }
    Server* server = new Server;
    cout << "ServerFactory.CreateInstance: Server connected." << endl;
    return server->QueryInterface(IID, ppv);
};

HRESULT __stdcall ServerFactory::CreateInstance2(IUnknown* pUnknownOuter, const IID& IID, void** ppv, int num1, int num2)
{
    if (pUnknownOuter != NULL)
    {
        return E_NOTIMPL;
    }
    Server* server = new Server(num1, num2);
    cout << "ServerFactory.CreateInstance2: Server connected." << endl;
    return server->QueryInterface(IID, ppv);
};

HRESULT __stdcall ServerFactory::QueryInterface(const IID& IID, void** ppv)
{
    if (IID == IID_IClassFactory)
    {
        cout << "ServerFactory.QueryInterface: IClassFactory connected." << endl;
        *ppv = (IClassFactory*)this;
    }
    else if (IID == IID_IClassFactory2)
    {
        cout << "ServerFactory.QueryInterface: IClassFactory2 connected." << endl;
        *ppv = (IClassFactory2*)this;
    }
    else
    {
        cout << "ServerFactory.QueryInterface: Invalid interface" << endl;
        *ppv = NULL;
        return S_FALSE;
    }
    reinterpret_cast<IUnknown*>(*ppv)->AddRef();
    return S_OK;
};

ULONG __stdcall ServerFactory::AddRef() 
{ 
    cout << "ServerFactory.AddRef = " << m_cRef + 1 << endl;
    cout << "ServerFactory.GlobalAddRef = " << global_m_cRef + 1 << endl;
    ++global_m_cRef;
    return ++m_cRef; 
} 
 
ULONG __stdcall ServerFactory::Release() 
{ 
    cout << "ServerFactory.Release = " << m_cRef - 1 << endl;
    if(global_m_cRef != 0)
    {
        cout << "ServerFactory.GloblaRelease = " << global_m_cRef - 1 << endl;
        --global_m_cRef;
    }
    if(--m_cRef == 0)
    {
        delete this;
        return 0;
    }
    return m_cRef;
}

HRESULT __stdcall ServerFactory::LockServer(BOOL bLock)
{
  cout << "ServerFactory.LockServer";
  return S_OK;
}

ServerModFactory::ServerModFactory() 
{
    m_cRef = 0;
    cout << "ServerModFactory.Constructor: Created." << endl;
};
ServerModFactory::~ServerModFactory() 
{
    cout << "ServerModFactory.Destructor: Liquidated." << endl;
};

HRESULT __stdcall ServerModFactory::CreateInstance(IUnknown* pUnknownOuter, const IID& IID, void** ppv)
{
    if (pUnknownOuter != NULL)
    {
        return E_NOTIMPL;
    }
    ServerMod* serverMod = new ServerMod;
    cout << "ServerModFactory.CreateInstance: Server connected." << endl;
    return serverMod->QueryInterface(IID, ppv);
};

HRESULT __stdcall ServerModFactory::QueryInterface(const IID& IID, void** ppv)
{
    cout << "Before ServerModFactory::QueryInterface" << endl;
    if (IID == IID_IClassFactory)
    {
        cout << "ServerModFactory.QueryInterface: IClassFactory connected." << endl;
        *ppv = (IClassFactory*)this;
    }
    else
    {
        cout << "ServerModFactory.QueryInterface: Invalid interface" << endl;
        *ppv = NULL;
        return S_FALSE;
    }
    reinterpret_cast<IUnknown*>(*ppv)->AddRef();
    cout << "After ServerModFactory::QueryInterface" << endl;
    return S_OK;
};

ULONG __stdcall ServerModFactory::AddRef() 
{ 
    cout << "ServerModFactory.AddRef = " << m_cRef + 1 << endl;
    cout << "ServerModFactory.GlobalAddRef = " << global_m_cRef + 1 << endl;
    ++global_m_cRef;
    return ++m_cRef; 
} 
 
ULONG __stdcall ServerModFactory::Release() 
{ 
    cout << "ServerModFactory.Release = " << m_cRef - 1 << endl;
    if(global_m_cRef != 0)
    {
        cout << "ServerModFactory.GlobalRelease = " << global_m_cRef - 1 << endl;
        --global_m_cRef;
    }
    if(--m_cRef == 0)
    {
        delete this;
        return 0;
    }
    return m_cRef;
}

HRESULT __stdcall ServerModFactory::LockServer(BOOL bLock)
{
  cout << "ServerModFactory.LockServer";
  return S_OK;
}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    global_m_cRef = 0;
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}