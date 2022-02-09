#include <iostream>
#include "IServer.h"
#include "Server.h"
using namespace std;

IServer* CreateInstance(int x, int y)
{
    return new Server(x, y);
}

