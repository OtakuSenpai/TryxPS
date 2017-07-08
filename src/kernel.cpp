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

void Tryx::Kernel::loadPlugins(const std::string& path,bool addIt) {
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
    
    std::string filepath,temp;
    Plugin* curPlugin;
    SharedLib::Handle dllHandle; 
    while((dirp = readdir(dp)) != nullptr) {
      try {
        if(strcmp(dirp->d_name,".") == 0 || strcmp(dirp->d_name,"..") == 0) continue;
        else { 
          temp = dirp->d_name;
          std::cout<<"Contents: "<<dirp->d_name<<std::endl;
          filepath = path + std::string("/") + temp;
        }     
        if(stat( filepath.c_str(), &sb ) && (S_ISDIR( sb.st_mode ))) continue;              
        else if(stat(filepath.c_str(), &sb) == 0 && S_ISREG(sb.st_mode))
        { 
          dllHandle = SharedLib::Load(dirp->d_name);
          curPlugin = new Plugin(static_cast<SharedLib::Handle&>
                            (dllHandle),temp);
          loadedPlugins.pushBack(temp,curPlugin);
          delete curPLugin; curPlugin = nullptr;                  
        }
        SharedLib::Unload(dllHandle);
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

void Tryx::Kernel::loadPlugin(const std::string& path) {
  SharedLib::Handle dllHandle;
  Plugin* curPlugin;
  dllHandle = SharedLib::Load(path);
  curPlugin = new Plugin(static_cast<SharedLib::Handle&>
                         (dllHandle),const_cast<std::string&>(path));
  loadedPlugins.pushBack(std::string(curPlugin->getName()),curPlugin);
}

void Tryx::Kernel::unloadPlugins() {
  loadedPlugins.deleteList();
}  

Tryx::PluginInterface* Tryx::Kernel::retFuncHandle(const std::string& iden) {
  Plugin::PluginFactoryFunc temp = loadedPlugins.retDataAtPos(iden)->getFuncHandle();
  return temp();
}
    
char* Tryx::Kernel::getPluginName(const int& index) {
  return loadedPlugins.at(index)->getName();
}  
