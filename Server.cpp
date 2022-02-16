#include <iostream>
#include "Server.h"
using namespace std;

Server::Server()
{
    a = 0;
    b = 0;
}

Server::Server(int a_p, int b_p)
{
    a = a_p;
    b = b_p;
}

Server::~Server() {};

int Server::Func()
{
    return a + b;
}

int Server::Func2()
{
    return 2 * a + b;
}