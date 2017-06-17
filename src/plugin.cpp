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
  
  // Parameterized ctor to load a plugin dll and initiate it inside
  // the class object.Used as the primary way of loading plugins
  // Parameters are:-
  // SharedLib::Handle handle - A 
  
  Plugin::Plugin(SharedLib::Handle handle,const std::string &filename) :
    referenceCount(0) {
    try {
      Plugin_TextFunc text_func;
      
      pluginHandle = getNewPlugin(handle,"makePlugin",filename);
      if(funcHandle != nullptr) { 
         text_func = getTextData(handle,"getPluginName",filename);
         setName(text_func());
      
         text_func = getTextData(handle,"getPluginType",filename);
         setType(text_func());
      
         text_func = getTextData(handle,"getPluginVers",filename);
         setVers(text_func());
         
         // Initialize a new shared library reference counter
         this->referenceCount = new size_t(1);
       }
    }
    catch(std::exception& e) {
      throw;
    }
  }

  // Creates a copy of a plugin that has already been loaded.
  // Required to provide correct semantics for storing plugins in
  // an STL map container.
  // Other plugin instance to copy
  
  Plugin::Plugin(const Plugin &other) :
    referenceCount(other.referenceCount) {

    // Increase DLL reference counter
    if(this->referenceCount) {
      ++(*this->referenceCount);
    }
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
   size_t remainingReferences = --*(this->referenceCount);
   if(remainingReferences == 0) {
      delete this->referenceCount;
      referenceCount = nullptr;
     }
  } 

  // Destroys the plugin, unloading its library when no more references
  // to it exist.
  
  Plugin :: ~Plugin() {
      clearMembers();
    }
  }

  Plugin_TextFunc* Plugin :: getTextData(SharedLib::Handle handle,
                                         const char* funcname,
                                         const std::string& filename)
  {
   Plugin_TextFunc textHandle;
   if(!handle) handle = SharedLib::Load(filename);     
      if(handle != nullptr){
         textHandle = SharedLib::GetFunctionPointer
                      <Plugin_TextFunc>(this->sharedLibraryHandle,funcname);
         if(funcHandle != nullptr) return textHandle();             
      }
   return nullptr;
  } 
  
  PluginInterface* Plugin :: getNewPlugin(SharedLib::Handle handle,
                                          const char* funcname,
                                          const std::string& filename)
  {
   PluginFactoryFunc funcHandle; 
   if(!handle) handle = SharedLib::Load(filename);     
      if(handle != nullptr){
         funcHandle = SharedLib::GetFunctionPointer
                      <PluginFactoryFunc>(this->sharedLibraryHandle,funcname);
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