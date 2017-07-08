#include <iostream>
#include <string>
#include "kernel.hpp"
#include <stdexcept>

#define TRYX_SOURCE 1

using namespace Tryx;

int main() {
  try {
    Kernel k;
    std::string s;
    std::cout<<"Enter the path to the shared library: ";
    std::cin>>s; std::cout<<"\n";
    k.loadPlugins(s,true);
    std::cout<<"Size: "<<k.getSize()<<std::endl;
    std::string temp(k.getPluginName(0));
    PluginInterface *p = k.retFuncHandle(temp);
    p->onCommand("Hello world!!");
    delete p;
  }
  catch(std::exception& e) {
    std::cout<<"Caught exception: \n"<<e.what();
  }
  return 0;
}
  
  
