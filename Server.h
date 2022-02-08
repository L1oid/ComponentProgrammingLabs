#ifndef SERVER_H
#define SERVER_H
class MyServer
{
private:
    int a;
    int b;
public:
    MyServer();
    MyServer(int a_p, int b_p);
    ~MyServer();
    int Func();
};
#endif