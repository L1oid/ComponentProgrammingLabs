#include <iostream>
#include "IServer2.h"
#include "Server.h"
using namespace std;

IServer2* CreateInstance2(int x, int y)
{
    return new Server(x, y);
}