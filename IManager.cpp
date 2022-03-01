#include "IManager.h"
using namespace std;

IServer* CreateInstance()
{
    return new Server();
}