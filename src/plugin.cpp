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

#define TRYX_SOURCE 1

#include "plugin.hpp"

#include <stdexcept>
#include <cstring>
#include <iostream>

using namespace std;

namespace Tryx {
  
  Plugin::Plugin(SharedLib::Handle& handle,const std::string& filename) {
    try {
      Plugin_TextFunc text_func;
      setFileName(filename);
      
      funcHandle = getNewPlugin(handle,"makePlugin",filename);
      if(funcHandle != nullptr) { 
        
        // Get plugin name from the dynamic library
        text_func = getTextData(handle,"getPluginName",filename);
        setName(text_func()); // Set plugin name
        
        // Get plugin type from the dynamic library 
        text_func = getTextData(handle,"getPluginType",filename);
        setType(text_func()); //Set plugin type
        
        // Get plugin version from the dynamic library
        text_func = getTextData(handle,"getPluginVers",filename);
        setVers(text_func()); // Set plugin version 
      }
    }
    catch(std::exception& e) {
      std::cout<<"Caught exception: \n"<<e.what()<<std::endl;
    }
  }
  
  Plugin::Plugin(const Plugin& other)
  {
    try { 
      pluginName = other.getName();
      pluginType = other.getType();
      pluginVersion = other.getVers();
      filename = other.getFilename();
      funcHandle = other.getFuncHandle();
    }
    catch(std::exception& e) {
      std::cerr<<"Caught exception: \n"<<e.what();
    }
  }
  
  Plugin::Plugin(const Plugin* other)
  {
    try { 
      pluginName = other->getName();
      pluginType = other->getType();
      pluginVersion = other->getVers();
      filename = other->getFilename();
      funcHandle = other->getFuncHandle();
    }
    catch(std::exception& e) {
      std::cerr<<"Caught exception: \n"<<e.what();
    }
  }
  
  Plugin& Plugin :: operator= (const Plugin& other) {
    try {
      pluginName = other.pluginName;
      pluginType = other.pluginType;
      pluginVersion = other.pluginVersion;
      filename = other.filename;
      funcHandle = other.getFuncHandle();
    }
    catch(std::exception& e) {
      std::cerr<<"Caught exception: \n"<<e.what();
    }
    return *this;
  }
  
  Plugin::Plugin_TextFunc Plugin :: getTextData(SharedLib::Handle handle,
                                         const char* funcname,
                                         const std::string& filename)
  {
    Plugin_TextFunc textHandle;
    if(!handle) handle = SharedLib::Load(filename);     
      if(handle != nullptr){
        textHandle = SharedLib::GetFunctionPointer
                     <Plugin::Plugin_TextFunc>(handle,funcname);
        if(funcHandle != nullptr) return textHandle;             
      }
    return nullptr;
  } 
  
  Plugin::PluginFactoryFunc Plugin :: getNewPlugin(SharedLib::Handle handle,
                                          const char* funcname,
                                          const std::string& filename)
  {
    PluginFactoryFunc funcHandle; 
    if(!handle) handle = SharedLib::Load(filename);     
      if(handle != nullptr){
        funcHandle = SharedLib::GetFunctionPointer
                     <Plugin::PluginFactoryFunc>(handle,funcname);
          if(funcHandle != nullptr) return funcHandle;             
      }
    return nullptr;
  } 
  
  void Plugin :: setName(const char* name) {
    pluginName.assign(name);
  }
  
  void Plugin :: setName(const std::string& name) {
    pluginName = name;
  }
  
  void Plugin :: setType(const char* type) {
    pluginType.assign(type);
  }
  
  void Plugin :: setType(const std::string& type) {
    pluginType = type;
  }
  
  void Plugin :: setFileName(const char* fname) {
    filename.assign(fname);
  }
  
  void Plugin :: setFileName(const std::string& fname) {
    filename = fname; 
  }

  void Plugin :: setVers(const char* vers) {
     pluginVersion.assign(vers);
  }
  
  void Plugin :: setVers(const std::string& vers) {
    pluginVersion = vers;
  }
} // namespace Tryx
