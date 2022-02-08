#include <iostream>
#include "Server.h"
using namespace std;

int main()
{
    MyServer* S = new MyServer(2, 3);
    cout << S->Func() << endl;
    delete S;
}