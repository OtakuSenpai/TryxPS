#!/usr/bin/env sh

echo "Compiling the main library file..."

g++  -fPIC -g3 -c -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ -ldl  ./src/plugin.cpp -I ./include

g++  -fPIC -g3 -c -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ -ldl  ./src/kernel.cpp -I ./include plugin.o

echo "Compiling the examples..."

g++ -fPIC -g -c -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ ./examples/plugin1.cpp -I ./include -I ./examples

g++ -g -shared -Wl,-soname,libplugin1.so.1 -o libplugin.so.0.1 ./plugin1.o -lstdc++

echo "Compiling main.cpp ..."      

g++ -g3 -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ -ldl -I ./include ./main.cpp kernel.o plugin.o

rm *.o

echo "Done..."
 
