#!/usr/bin/env sh

echo "Compiling the main library file..."

g++  -fPIC -g -c -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ -ldl  ./src/plugin.cpp -I ./include

g++  -fPIC -g -c -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ -ldl  ./src/kernel.cpp -I ./include

echo "Compiling the examples..."

g++ -fPIC -g -c -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ -ldl ./examples/plugin1.cpp -I ./include -I ./examples

g++ -g -shared -Wl,-soname,libplugin1.so.1 -o libplugin.so.0.1 ./plugin1.o -lstdc++

echo "Compiling main.cpp ..."      

g++ -o main -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ -I ./include ./main.cpp

rm *.o

echo "Done..."
 
