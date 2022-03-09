#include <iostream>
#include "IManager.h"
#include "OBJBASE.h"
using namespace std;

int main()
{
    IX* pIX = NULL;
    HRESULT_ result = CreateInstance(CLSID_SERVER, IID_IX, (void**)&pIX);
    if (result == 0)
    {
        cout << pIX->Func1() << endl;
    }
    else
    {
        cout << "Warning" << endl;
    }
    system("pause");
    return 0;
}