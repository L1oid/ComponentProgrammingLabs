#include <iostream>
#include <stdlib.h>
#include "IServer.h"
using namespace std;

int main()
{
    IServer* S = CreateInstance(3, 2);
    cout << S->Func() << endl;
    delete S;
    system("pause");
}