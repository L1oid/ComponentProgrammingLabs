echo off

"C:\Program Files\CodeBlocks\MinGW\bin\g++" Server.cpp IServer.cpp IServer2.cpp Main.cpp -c 
"C:\Program Files\CodeBlocks\MinGW\bin\g++" Server.o IServer.o IServer2.o Main.o -o run.exe

PAUSE
