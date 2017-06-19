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

#include "config.hpp"
#include "sharedlib.hpp"

#include <string>

namespace Tryx {

  // Representation of a plugin
  class Plugin {
    private:
       //Signature for the plugin's registration function
       typedef PluginInterface* *(*PluginFactoryFunc)();
       //Signature to query for plugin texts
       typedef char * (*Plugin_TextFunc)();
       
       char* pluginName;
       char* pluginType;
       char* pluginVersion;
       char* filename;
       PluginFactoryFunc funcHandle;
       
       // Handy function to clear the data members of a plugin object.
       // Used in the dtor only.
       void clearMembers();
       
    public: 
       // Parameterized ctor to load a plugin dll and initiate it inside
       // the class object.Used as the primary way of loading plugins
       // Parameters are:-
       // SharedLib::Handle handle - A handle which is passed from the 
       // Kernal class.It helps in loading the function pointers.
       // std::string& filename - The filename to the dynamic library.
       TRYX_API_EXP Plugin(SharedLib::Handle& handle,std::string &filename);
       
       // Copy ctor for constructing a plugin from one that has already 
       // been loaded.Required to provide correct semantics for storing 
       // plugins in an STL map container.
       TRYX_API_EXP Plugin(const Plugin &other);
       
       // Unloads the plugin, unloading its library when no more 
       // references to it exist.
       TRYX_API_EXP ~Plugin();

       // Gets a text function handle from the dynamic library and 
       // returns it. If found then returns it,else returns nullptr.
       TRYX_API_EXP Plugin_TextFunc* getTextData(SharedLib::Handle handle,
                                         const char* funcname,
                                         std::string& filename);
       
       // Gets a PluginInterface object from the dynamic library.
       // If found,then returns it,else returns nullptr.
       TRYX_API_EXP PluginInterface* getNewPlugin(SharedLib::Handle handle,
                                          const char* funcname,
                                          std::string& filename);
                                          
       TRYX_API_EXP char* getName() const { return pluginName; } // Get name.
       TRYX_API_EXP char* getType() const { return pluginType; } // Get type.
       TRYX_API_EXP char* getVers() const { return pluginVersion; } // Get version.
       TRYX_API_EXP char* getFilename() const { return filename; } // Get filename. 
       
       TRYX_API_EXP void setName(char* name); // Set name.
       TRYX_API_EXP void setType(char* type); // Set type.
       TRYX_API_EXP void setVers(char* vers); // Set version 
       TRYX_API_EXP void setFileName(char* name); // Set filename
         
       //Creates a copy of the plugin instance.
       TRYX_API_EXP Plugin &operator =(const Plugin &other);
     
  };
 
} // namespace MyEngine

#endif // MYENGINE_PLUGIN_H









