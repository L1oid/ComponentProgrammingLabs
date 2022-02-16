echo off

"C:\Program Files\CodeBlocks\MinGW\bin\g++" Server.cpp IServer.cpp Main.cpp -c 
C:\Program Files\CodeBlocks\MinGW\bin\g++" Server.o IServer.o Main.o run.exe -static-libstdc++ -static-libgcc

PAUSE
