#include <iostream>
#include "IManager.h"
#include "OBJBASE.h"
using namespace std;

int main()
{
    IClassFactory* pF = NULL;
    HRESULT_ result = GetClassObject(CLSID_SERVER, IID_ICLASSFACTORY, (void**)&pF);
    if (result == S_OK)
    {
        IX* pX = NULL;
        result = pF->CreateInstance(IID_IX, (void**)&pX);
        if (result == S_OK)
        {
            cout << pX->Func1() << endl;
        }
        else cout << "Warning" << endl;
    }
    else cout << "Warning" << endl;
    system("pause");
    return 0;
}