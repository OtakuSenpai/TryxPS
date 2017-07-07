#define TRYX_SOURCE 1

#include "config.hpp"
#include <iostream>

using namespace Tryx;

class Plugin1 : public PluginInterface
{
  public:
    Plugin1();
    virtual ~Plugin1();
    char* onCommand(const char* data);
};
