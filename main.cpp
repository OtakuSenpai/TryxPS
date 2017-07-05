#include <iostream>
#include <string>
#include "kernel.hpp"

#define TRYX_SOURCE 1

using namespace Tryx;

int main() {
  Kernel k;
  std::string s;
  std::cout<<"Enter the path to the shared library: ";
  std::cin>>s; std::cout<<"\n";
  k.loadPlugin(s);
  std::string temp(k.getPluginName(0));
  PluginInterface *p = k.retFuncHandle(temp);
  p->onCommand("Hello world!!");
  delete p;
  return 0;
}
  
  
