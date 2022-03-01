echo off

g++ Server.cpp IManager.cpp Main.cpp -c 
g++ Server.o IManager.o Main.o -o run.exe

PAUSE
