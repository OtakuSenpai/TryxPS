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

#include "kernel.hpp"
#include <cstring> 

#ifdef TRYX_LINUX
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

#elif TRYX_WIN32
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <windows.h>
#else
#error Shared library system supported for Windows and Linux only!!!
#endif

namespace Tryx {
  
  void Kernel :: loadPlugins(const std::string& path,bool addIt) {
    #ifdef TRYX_WIN32
      if(!addIt)
        return;
      WIN32_FIND_DATA fd;
      char fname[256];
      strcpy(fname,const_cast<char*>(path.c_str()));
      size_t len=strlen(fname);
      if(fname[len-1]=='/' || fname[len-1]=='\\')  strcat(fname,"*.dll");
      else strcat(fname,"\\*.dll");
      HANDLE hFind = FindFirstFile(fname, &fd); 
      if (hFind == INVALID_HANDLE_VALUE) 
      {
        FindClose(hFind); return;
      } 
      Plugin* curPlugin;
      HINSTANCE dllHandle = nullptr;  
      do 
      { 
        try
        {
          if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
          {                                       
            dllHandle = SharedLib::Load(fd.cFileName);
            if (dllHandle != nullptr) 
            {
              curPlugin = new Plugin(static_cast<SharedLib::Handle>
                                    (dllHandle),std::string(fd.cFileName));
              loadedPlugins.pushBack(std::string(curPlugin->getName()),curPlugin);
              delete curPlugin; curPlugin = nullptr;
            }
            FreeLibrary(dllHandle);
          }
        }
        catch(...)
        {
          if (dllHandle != NULL) FreeLibrary(dllHandle);
          throw std::runtime_error("kernel.cpp : Line 34, \
                 error in finding .dlls in the directory.");
        }
      } while (FindNextFile(hFind, &fd));
      FindClose(hFind);
    #endif
   
    #ifdef TRYX_LINUX
      if(!addIt)
        return;
      DIR *dp;
      struct stat sb;
      struct dirent *dirp;
     
      try {   
        if((dp  = opendir(path.c_str())) == nullptr) {
          throw std::runtime_error("kernel.cpp : Line 79,error in the operation.");
        }
      }
      catch(std::exception& e) {
        std::cout<<"Caught exception: "<<e.what(); 
      }
    
      std::string filepath,temp,temp2;
      Plugin* curPlugin;
      SharedLib::Handle dllHandle; 
      while((dirp = readdir(dp)) != nullptr) {
        try {
          if(strcmp(dirp->d_name,".") == 0 || strcmp(dirp->d_name,"..") == 0) continue;
          else { 
            temp.assign(dirp->d_name);
            filepath = path + std::string("/") + temp;
          }     
          if(stat( filepath.c_str(), &sb ) && (S_ISDIR( sb.st_mode ))) continue;              
          else if(stat(filepath.c_str(), &sb) == 0 && S_ISREG(sb.st_mode))
          { 
            dllHandle = SharedLib::Load(filepath);
            if(dllHandle != nullptr) {
              curPlugin = new Plugin(static_cast<SharedLib::Handle&>
                                  (dllHandle),filepath);
              temp2 = curPlugin->getName();
              loadedPlugins.push_back(new Node(temp2,curPlugin));
              delete curPlugin; curPlugin = nullptr;
            }
          }
          filepath.clear();
        } 
        catch(std::exception& e)
        {
          if (dllHandle != nullptr) SharedLib::Unload(dllHandle);
          std::cerr<<"Caught exception: "<<e.what();
        } 
      }     
      closedir(dp);
    #endif
  }    

  void Kernel :: loadPlugin(const std::string& path) {
    try {
      SharedLib::Handle dllHandle;
      Plugin* curPlugin;
      dllHandle = SharedLib::Load(path);
      if(dllHandle !=nullptr) {
        curPlugin = new Plugin(static_cast<SharedLib::Handle&>
                            (dllHandle),path);
        std::string temp = curPlugin->getName();
        loadedPlugins.push_back(new Node(temp,curPlugin));
      }
    }
    catch(std::exception& e) {
      std::cout<<"Caught exception: \n"<<e.what();
    }
  }

  void Kernel :: unloadPlugins() {
    try {
      loadedPlugins.clear();
    }
    catch(std::exception& e) {
      std::cout<<"Caught exception: \n"<<e.what();
    }
  }  

  PluginInterface* Kernel :: getFuncHandle(const std::string& iden) {
    PluginInterface* p_plugin;
    try {
      for(auto* i : loadedPlugins) {
        if(i->getName() == iden) {
          Plugin::PluginFactoryFunc temp = i->getData().get()->getFuncHandle();
          p_plugin = temp();
        }
      }
    }
    catch(std::exception& e) {
      std::cout<<"Caught exception: \n"<<e.what();
    }
    if(p_plugin != nullptr)
      return p_plugin;
    else return nullptr;
  }
  
  int Kernel :: getFuncPos (const std::string& iden) const {
    int pos = -1;
    std::string tempRet;
    for(size_t i = 0; i < loadedPlugins.size(); i++) {
      tempRet.clear();
      tempRet = loadedPlugins[i]->getName();
      if(tempRet == iden) {
        pos = i;
      }
    }
    
    return pos;
  }
  
  int Kernel :: getFuncPos (const char* iden) const {
    int pos = -1;
    std::string tempRet,identifier;
    identifier.assign(iden); 
    for(size_t i = 0; i < loadedPlugins.size(); i++) {
      tempRet.clear();
      tempRet = loadedPlugins[i]->getName();
      if(tempRet == identifier) {
        pos = i;
      }
    }
    
    return pos;
  }  
    
  std::string Kernel :: getPluginName (const int& index) const {
    std::string s;
    try {
      s = loadedPlugins.at(index)->getName();
    }
    catch(std::exception& e) {
      std::cout<<"Caught exception: \n"<<e.what();
    }
    return s;
  }
} //namespace Tryx
