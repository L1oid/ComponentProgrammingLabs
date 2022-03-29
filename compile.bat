echo off

g++ Server.cpp Server2.cpp IManager.cpp Main.cpp -c 
g++ Server.o Server2.o IManager.o Main.o -o run.exe