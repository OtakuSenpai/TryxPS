#define TRYX_SOURCE 1

#include "config.hpp"
#include <iostream>

using namespace Tryx;

class Plugin1 : public PluginInterface
{
  public:
    TRYX_API_EXP Plugin1();
    TRYX_API_EXP virtual ~Plugin1();
    TRYX_API_EXP char* onCommand(const char* word,const char* data);
};
