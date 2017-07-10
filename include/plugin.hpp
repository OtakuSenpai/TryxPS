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

#ifndef PLUGIN_HPP
#define PLUGIN_HPP

#define TRYX_SOURCE 1

#include "config.hpp"
#include "sharedlib.hpp"

#include <string>

namespace Tryx {

  // Representation of a plugin
  class Plugin {
    public: 
       
       //Signature for the plugin's registration function
       typedef PluginInterface* (*PluginFactoryFunc)();
       //Signature to query for plugin texts
       typedef const char* (*Plugin_TextFunc)();
       
       // Parameterized ctor to load a plugin dll and initiate it inside
       // the class object.Used as the primary way of loading plugins
       // Parameters are:-
       // SharedLib::Handle handle - A handle which is passed from the 
       // Kernal class.It helps in loading the function pointers.
       // std::string& filename - The filename to the dynamic library.
       Plugin(SharedLib::Handle& handle,const std::string &filename);
       
       // Copy ctor for constructing a plugin from one that has already 
       // been loaded.Required to provide correct semantics for storing 
       // plugins in an STL map container.
       Plugin(const Plugin &other);
       
       // Unloads the plugin, unloading its library when no more 
       // references to it exist.
       ~Plugin() {}

       // Gets a text function handle from the dynamic library and 
       // returns it. If found then returns it,else returns nullptr.
       Plugin::Plugin_TextFunc getTextData(SharedLib::Handle handle,
                                          const char* funcname,
                                          const std::string& filename);
       
       // Gets a PluginInterface object from the dynamic library.
       // If found,then returns it,else returns nullptr.
       Plugin::PluginFactoryFunc getNewPlugin(SharedLib::Handle handle,
                                              const char* funcname,
                                              const std::string& filename);
                                          
       std::string getName() const { return pluginName; } // Get name.
       std::string getType() const { return pluginType; } // Get type.
       std::string getVers() const { return pluginVersion; } // Get version.
       std::string getFilename() const { return filename; } // Get filename. 
       PluginFactoryFunc getFuncHandle() const { // Get the function handle
         return funcHandle;
       }
       
       void setName(const char* name); // Set name.
       void setName(const std::string& name);
       void setType(const char* type); // Set type.
       void setType(const std::string& type);
       void setVers(const char* vers); // Set version 
       void setVers(const std::string& vers);
       void setFileName(const char* fname); // Set filename
       void setFileName(const std::string& fname);
         
       //Creates a copy of the plugin instance.
       TRYX_API_EXP Plugin &operator =(const Plugin &other);
       
    private:
       
       std::string pluginName;
       std::string pluginType;
       std::string pluginVersion;
       std::string filename;
       PluginFactoryFunc funcHandle;
     
  };
 
} // namespace MyEngine

#endif // MYENGINE_PLUGIN_H









