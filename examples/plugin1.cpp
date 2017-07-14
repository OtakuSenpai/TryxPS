#include "plugin1.hpp"
#include <cstring>

TRYX_DECL_PLUGIN(Plugin1)
SET_PLUGIN_NAME("Plugin1")
SET_PLUGIN_TYPE("examples")
SET_PLUGIN_VERS("1.0")

Plugin1 :: Plugin1() 
{
 
}

Plugin1 :: ~Plugin1()
{

}

char* Plugin1 :: onCommand(const char* data) { 
  std::cout<<"Returning data: "<<std::endl;
  char* retValue = new char[std::strlen(data)+1];
  std::strcpy(retValue,data);
  return retValue;
}
