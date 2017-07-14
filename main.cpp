#include <iostream>
#include <string>
#include <stdexcept> 
#include <cstring>
#include "kernel.hpp"

#define TRYX_SOURCE 1

using namespace Tryx;

int main(int argc, char* argv[]) {
  try {
    std::string s;
    if((argc < 2) || (strcmp(argv[1],"-h") == 0)) {
      std::cout<<"\n\nCommand parameters are:- \n"
               <<"   -h :           Prints this help \n"
               <<"   -f <folder> :  Loads folder \n\n";
    }
    else if(strcmp(argv[1],"-f") == 0) {
      s.assign(argv[2]);
    }
    if(s.size() != 0) {
      Kernel k;
      k.loadPlugins(s,true);
      std::cout<<"Size: "<<k.getSize()<<std::endl;
      int pos = k.getFuncPos("Plugin1");
      std::string temp = k.getPluginName(pos);
      PluginInterface *p = k.getFuncHandle(temp);
      std::cout<<p->onCommand("Hello world!!")<<"\n";
      delete p;
      
    }
    else std::cout<<"Empty parameters. See help. \n";
  }
  catch(std::exception& e) {
    std::cout<<"Caught exception: \n"<<e.what();
  }
  return 0;
}
  
  
