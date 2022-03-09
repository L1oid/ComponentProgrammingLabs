#include <iostream>
#include "IManager.h"
#include "OBJBASE.h"
using namespace std;

HRESULT_ CreateInstance(CLSID_ CLS_ID, IID_ I_ID, void** ppv)
{
    IUnknown* pIUnknown = NULL;
    HRESULT_ result;
    switch (CLS_ID) 
    {
    case 1:
        cout << "CreateInstance: Linked Server." << endl;
        pIUnknown = (IX*) new Server;
        result = pIUnknown->QueryInterface(I_ID, ppv);
        break;
    case 2:
        cout << "CreateInstance: Lined Server2." << endl;
        pIUnknown = (IY*) new Server2;
        result = pIUnknown->QueryInterface(I_ID, ppv);
        break;
    default:
        cout << "CreateInstance: Invalid server. Linked Server1" << endl;
        pIUnknown = (IX*) new Server;
        result = pIUnknown->QueryInterface(I_ID, ppv);
        break;
    }
    return result;
}