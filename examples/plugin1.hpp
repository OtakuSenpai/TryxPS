#include "plugininterface.hpp"
#include <iostream>

using namespace Tryx;

class Plugin1 : public PluginInterface
{
  Plugin1();
  virtual ~Plugin1();
  char* onCommand(const char* data);
};