#!/usr/bin/sh

echo "Compiling the plugin.cpp file..."

g++  -fPIC -g -c -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ -ldl  ./src/plugin.cpp -I ./include

g++  -fPIC -g -c -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ -ldl  ./src/kernel.cpp -I ./include

#g++ -g -shared -Wl, -soname, libplugin.so.1 \ 
#      -o libplugin.so.0.1 plugin.o -lc

#g++ -o main -std=c++14 -fmessage-length=30 -fdiagnostics-color=always -Wall -Wextra -pedantic -lstdc++ -I ./include 

echo "Done..."
 
