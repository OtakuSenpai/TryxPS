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

using namespace std;

namespace Tryx {
  
  Plugin::Plugin(SharedLib::Handle& handle,std::string& filename) {
    try {
      Plugin_TextFunc text_func;
      setFileName(const_cast<char*>(filename.c_str));
      
      pluginHandle = getNewPlugin(handle,"makePlugin",filename);
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
      throw;
    }
  }
  
  Plugin::Plugin(const Plugin& other)
  {
    setName(other.pluginName);
    setType(other.pluginType);
    setVers(other.pluginVersion);
    setFileName(other.filename);
  }
  
  void Plugin :: clearMembers()
  {
   delete[] pluginName;
   delete[] pluginType;
   delete[] filename;
   delete[] pluginVersion;
    
   pluginType=nullptr;
   pluginName=nullptr;
   filename=nullptr;
   pluginVersion=nullptr;
  } 
  
  Plugin :: ~Plugin() {
      clearMembers();
    }
  }
  
  Plugin_TextFunc* Plugin :: getTextData(SharedLib::Handle handle,
                                         const char* funcname,
                                         std::string& filename)
  {
   Plugin_TextFunc textHandle;
   if(!handle) handle = SharedLib::Load(filename);     
      if(handle != nullptr){
         textHandle = SharedLib::GetFunctionPointer
                      <Plugin_TextFunc>(handle,funcname);
         if(funcHandle != nullptr) return textHandle();             
      }
   return nullptr;
  } 
  
  PluginInterface* Plugin :: getNewPlugin(SharedLib::Handle handle,
                                          const char* funcname,
                                          std::string& filename)
  {
   PluginFactoryFunc funcHandle; 
   if(!handle) handle = SharedLib::Load(filename);     
      if(handle != nullptr){
         funcHandle = SharedLib::GetFunctionPointer
                      <PluginFactoryFunc>(handle,funcname);
         if(funcHandle != nullptr) return funcHandle();             
      }
   return nullptr;
  } 
  
  void Plugin :: setName(char * nm)
  {
   pluginName=new char[strlen(nm)+1];
   strcpy(pluginName,nm);
  }
  
  void Plugin :: setType(char * nm)
  {
   pluginType=new char[strlen(nm)+1];
   strcpy(pluginType,nm);
  }
  
  void Plugin :: setFileName(char * nm)
  {
   filename=new char[strlen(nm)+1];
   strcpy(filename,nm);
  }
  
  void Plugin :: setVers(char* v)
  {
     pluginVersion = new char[strlen(v)+1];   
     strcpy(pluginVersion,v);
  }
} // namespace Tryx
