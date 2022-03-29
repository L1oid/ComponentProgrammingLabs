#include <iostream>
#include "IManager.h"
#include "OBJBASE.h"
using namespace std;

int main()
{
    IClassFactory* pF = NULL;
    HRESULT_ result = GetClassObject(CLSID_SERVER, IID_ICLASSFACTORY, (void**)&pF);
    pF->Release();
    if (result == S_OK)
    {
        IX* pX = NULL;
        result = pF->CreateInstance(IID_IX, (void**)&pX);
        pF->Release();
        if (result == S_OK)
        {
            cout << "Func result: " << pX->Func1() << endl;
            pX->Release();
        }
        else cout << "Warning" << endl;
        IY* pY = NULL;
        result = pX->QueryInterface(IID_IY, (void**)&pY);
        if (result == S_OK)
        {
            cout << "Func result: " << pY->Func2() << endl;
            pX->Release();
        }
        else cout << "Warning" << endl;
        pX->Release();
    }
    else cout << "Warning" << endl;
    system("pause");
    return 0;
}