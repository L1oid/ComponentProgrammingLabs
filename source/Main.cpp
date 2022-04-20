#include <iostream>
#include "IManager.h"
#include "OBJBASE.h"
using namespace std;

int main()
{
    IClassFactory2* pF = NULL;
    HRESULT_ result = GetClassObject(CLSID_SERVER, IID_ICLASSFACTORY2, (void**)&pF);
    if (result == S_OK_)
    {
        IY* pY = NULL;
        result = pF->CreateInstance2(IID_IY, (void**)&pY, 3, 6);
        if (result == S_OK_)
        {
            cout << "NOD: " << pY->Nod() << endl;
        }
        else cout << "Warning" << endl;
        result = pY->QueryInterface(IID_IX, (void**)&pY);
        if (result == S_OK_)
        {
            cout << "NOK: " << pY->Nod() << endl;
            pY->Release();
        }
        else cout << "Warning" << endl;
        pY->Release();
    }
    else cout << "Warning" << endl;
    pF->Release();
    system("pause");
    return 0;
}