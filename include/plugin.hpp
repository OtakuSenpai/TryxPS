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
       typedef PluginInterface* (*PluginFactoryFunc)();
       //Signature to query for plugin texts
       typedef char * (*Plugin_TextFunc)();
       
       char* filename;
       char* pluginType;
       char* pluginName;
       char* pluginVersion;
       PluginFactoryFunc pluginHandle;
       
       TRYX_API_EXP void setName(char* name);
       TRYX_API_EXP void setType(char* type);
       TRYX_API_EXP void setVers(char* vers);
       TRYX_API_EXP void setFileName(char* name);
       
       TRYX_API_EXP Plugin_TextFunc* getTextData(SharedLib::Handle handle,
                                                 const char* funcname,
                                                 const std::string& filename);
       TRYX_API_EXP PluginInterface* getNewPlugin(SharedLib::Handle handle,
                                                  const char* funcname,
                                                  const std::string& filename);
       void clearMembers();
       
    public: 
       //Initializes and loads a plugin
       //Parameter is filename of the plugin to load
       TRYX_API_EXP Plugin(SharedLib::Handle handle,const std::string &filename);
       //Copies an existing plugin instance
       TRYX_API_EXP Plugin(const Plugin &other);
       //Unloads the plugin
       TRYX_API_EXP ~Plugin();
       
       TRYX_API_EXP char* getName() { return pluginName; }
       TRYX_API_EXP char* getType() { return pluginType; }
       TRYX_API_EXP char* getVers() { return pluginVersion; }
         
       //Creates a copy of the plugin instance
       Plugin &operator =(const Plugin &other);
    
  };

  // ----------------------------------------------------------------------- //

} // namespace MyEngine

#endif // MYENGINE_PLUGIN_H









