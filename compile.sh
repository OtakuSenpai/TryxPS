#!/usr/bin/env sh

echo "Compiling the main library file..."

g++  -fPIC -g -c -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic ./src/plugin.cpp -I ./include -ldl -lstdc++ -ldl

g++  -fPIC -g -c -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic ./src/kernel.cpp -I ./include plugin.o -lstdc++ -ldl

echo "Compiling the examples..."

g++ -fPIC -c -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ ./examples/plugin1.cpp -I ./include -I ./examples

g++ -shared -Wl,-soname,libplugin1.so.1 -o libplugin.so.0.1 ./plugin1.o -lstdc++

echo "Compiling main.cpp ..."      

g++ -o main -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ -ldl -I ./include ./main.cpp kernel.o plugin.o

rm *.o
cp ./libplugin.so.0.1 ./plugins
rm *.1

echo "Done..."
 
