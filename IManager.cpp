#include <iostream>
#include "IManager.h"
using namespace std;

IUnknown* CreateInstance(int S_ID)
{
    IUnknown* pI = NULL;
    switch (S_ID) 
    {
    case 1:
        cout << "CreateInstance: Linked Server." << endl;
        pI = (IX*) new Server;
        break;
    case 2:
        cout << "CreateInstance: Lined Server2." << endl;
        pI = (IY*) new Server2;
        break;
    default:
        cout << "CreateInstance: Invalid server. Linked Server1" << endl;
        pI = (IX*) new Server;
        break;
    }
    return pI;
}