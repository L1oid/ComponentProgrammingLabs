#include <iostream>
#include <stdlib.h>
#include "IServer.h"
#include "IServer2.h"
using namespace std;

int main()
{
    IServer* S = CreateInstance(3, 2);
    IServer2* S2 = (IServer2*)S;
    cout << S2->Func2() << endl;
    system("pause");
}