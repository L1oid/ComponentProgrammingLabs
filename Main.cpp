#include <iostream>
#include "IServer.h"
#include "IServer2.h"
#include "IManager.h"
using namespace std;

int main()
{
    IServer* S = CreateInstance();
    IServer2* S2 = (IServer2*)S;
    cout << S2->Func2() << endl;
    system("pause");
}