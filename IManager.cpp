#include <iostream>
#include "IManager.h"
#include "OBJBASE.h"
using namespace std;

HRESULT_ CreateInstance(CLSID_ CLSID, IID_ IID, void** ppv)
{
    IUnknown* pIUnknown = NULL;
    switch (CLSID) 
    {
    case CLSID_SERVER:
        pIUnknown = (IX*) new Server;
        cout << "Global.CreateInstance: Server connected." << endl;
        break;
    case CLSID_SERVER2:
        pIUnknown = (IY*) new Server2;
        cout << "Global.CreateInstance: Server2 connected." << endl;
        break;
    default:
        cout << "Global.CreateInstance: connection error." << endl;
        return S_FAIL;
        break;
    }
    pIUnknown->AddRef();
    return pIUnknown->QueryInterface(IID, ppv);
}

HRESULT_ GetClassObject(CLSID_ CLSID, IID_ IID, void** ppv)
{
    IUnknown* pIUnknown = NULL;
    switch (CLSID) 
    {
    case CLSID_SERVER:
        pIUnknown = (IClassFactory*) new ServerFactory;
        cout << "GetClassObject: ServerFactory connected." << endl;
        break;
    case CLSID_SERVER2:
        pIUnknown = (IClassFactory*) new Server2Factory;
        cout << "GetClassObject: Server2Factory connected." << endl;
        break;
    default:
        cout << "GetClassObject: connection error." << endl;
        return S_FAIL;
        break;
    }
    pIUnknown->AddRef();
    return pIUnknown->QueryInterface(IID, ppv);
}