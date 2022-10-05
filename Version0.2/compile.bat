echo off

@REM pause
@REM exit

g++ -c ./source/ServerDLL.cpp -o ./build/ServerDLL.o
g++ -c ./source/Manager.cpp -o ./build/Manager.o
g++ -shared ./build/ServerDLL.o -o ./build/ServerDLL.dll -Wl,--kill-at
g++ -shared ./build/Manager.o -o ./build/Manager.dll -Wl,--kill-at

@REM pause
@REM exit

g++ -c ./source/Main.cpp -o ./build/Main.o

g++ ./build/Main.o -o ./build/run.exe

pause
exit