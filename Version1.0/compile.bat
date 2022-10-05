echo off

@REM pause
@REM exit

g++ -c ./source/ServerDLL.cpp -o ./build/ServerDLL.o
g++ -shared ./build/ServerDLL.o -o ./build/ServerDLL.dll -lole32 -loleaut32 -luser32 -Wl,--kill-at

@REM pause
@REM exit

g++ -c ./source/Main.cpp -o ./build/Main.o

g++ ./build/Main.o -o ./build/run.exe -lole32 -loleaut32 -luser32

pause
exit