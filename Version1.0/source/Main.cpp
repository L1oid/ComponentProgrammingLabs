#include <windows.h>
#include <iostream>
#include "IUnknown.h"
#include "OBJBASE.h"
using namespace std;

int main()
{
    CoInitialize(NULL);
    IClassFactory* pF = NULL;
    cout << "BeforeCOGET" << endl;
    HRESULT result = CoGetClassObject(CLSID_ServerMod, CLSCTX_INPROC_SERVER, NULL, IID_IClassFactory, (void**)&pF);
    cout << "AfterCOGET" << endl;
    if (result == S_OK)
    {
        IY* pY = NULL;
        result = pF->CreateInstance(NULL, IID_IY, (void**)&pY);
        if (result == S_OK)
        {
            cout << "Sum: " << pY->Sum() << endl;
        }
        else
        {
            cout << "Warning1" << endl;
            pF->Release();
            CoUninitialize();
            system("pause");
            return 0;
        }
        pY->Release();
        pF->Release();
        CoUninitialize();
        system("pause");
        return 0;
    }
    else
    {
        cout << "Warning2" << endl;
        CoUninitialize();
        system("pause");
        return 0;
    } 
}