echo off

g++ -c ./source/Server.cpp -o ./build/Server.o
g++ -c ./source/Server2.cpp -o ./build/Server2.o
g++ -c ./source/IManager.cpp -o ./build/IManager.o
g++ -c ./source/Main.cpp -o ./build/Main.o

g++ ./build/Server.o ./build/Server2.o ./build/IManager.o ./build/Main.o -o ./build/run.exe