///////////////////////////////////////////////////////////////////////////////////
// Tryx Plugin System made by Avra Neel Chakraborty                              //
//                                                                               //
// Copyright (c) 2017 Avra Neel Chakraborty                                      // 
//                                                                               //
// Permission is hereby granted, free of charge, to any person obtaining a copy  //
// of this software and associated documentation files (the "Software"), to deal //
// in the Software without restriction, including without limitation the rights  //
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell     //
// copies of the Software, and to permit persons to whom the Software is         //
// furnished to do so, subject to the following conditions:                      //
//                                                                               //
// The above copyright notice and this permission notice shall be included in    // 
// all copies or substantial portions of the Software.                           // 
///////////////////////////////////////////////////////////////////////////////////

#ifndef KERNEL_HPP
#define KERNEL_HPP

#include "plugin.hpp"
#include "tryxlist.hpp"
#include <string>

namespace Tryx {

  //The engine's core
  class Kernel {

    //Map of plugins by their associated file names
    typedef TryxList<std::string,Plugin*> PluginMap;

    public: 
       
       Kernel() : loadedPlugins{}
       ~Kernel() { unloadPlugins(); }
         
       // Loads all plugins present in a directory.
       void loadPlugins(const std::string& path,bool addIt);
       
       // Unloads all plugins 
       void unloadPlugins();
       
       Plugin::PluginFactoryFunc retFuncHandle(std::string& identifier);
       
    private:
       //All plugins currently loaded
       PluginMap loadedPlugins;
  };

} // namespace Tryx

#endif //KERNEL_HPP
