#!/bin/sh -

g++ -std=c++11 module.cpp -c -o module.o
g++ -std=c++11 main.cpp -c -o main.o
g++ module.o main.o -o horror.exe
./horror.exe
