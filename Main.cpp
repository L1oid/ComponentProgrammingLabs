#include <iostream>
#include "IManager.h"
using namespace std;

int main()
{
    IUnknown* pIUnknown = CreateInstance(1);
    IX* pIX = NULL;
    int result = pIUnknown->QueryInterface(1, (void**)&pIX);
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