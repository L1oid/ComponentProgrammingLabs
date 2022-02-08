#include <iostream>
#include "Server.h"
using namespace std;

MyServer::MyServer()
{
    a = 0;
    b = 0;
}

MyServer::MyServer(int a_p, int b_p)
{
    a = a_p;
    b = b_p;
}

MyServer::~MyServer() {};

int MyServer::Func()
{
    return a + b;
}