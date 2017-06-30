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

#ifndef SHAREDLIB_HPP
#define SHAREDLIB_HPP

#include "config.hpp"

#include <string>
#include <stdexcept>

#ifdef TRYX_WIN32

#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <windows.h>

#elif defined TRYX_LINUX
#include <sys/stat.h>
#include <dlfcn.h>
#else

#error Shared library system supported for Windows and Linux only!!!
#endif

namespace Tryx{

#ifdef TRYX_WIN32
   class SharedLib{
      public:
          typedef HMODULE Handle;
      
          TRYX_API_EXP static Handle Load(const std::string& path){
             std::string pathWithExtension = path + std::string(".dll");
             HMODULE mHandle = LoadLibraryA(pathWithExtension.c_str());
             if(mHandle == nullptr){
                throw std::runtime_error("sharedlib.hpp : Line 40, couldn't load dll.");
             }
             return mHandle;
          }
          
          TRYX_API_EXP static Handle Load(const char* path){
           
             std::string pathWithExtension; pathWithExtension.assign(path);
             pathWithExtension = pathWithExtension + std::string(".dll");
             HMODULE mHandle = LoadLibraryA(pathWithExtension.c_str());
             if(mHandle == nullptr){
                throw std::runtime_error("sharedlib.hpp : Line 51, couldn't load dll.");
             }
             return mHandle;
          }
          
          TRYX_API_EXP static void Unload(Handle sharedLibHandle){
             bool result = FreeLibrary(sharedLibHandle);
             if(result == false){
                throw std::runtime_error("sharedlib.hpp : Line 49,couldn't unload dll.");
             }
          }
          
          //Looks up a function exported by the dll.Parameter is a handle of the dll
          //in which the function will be looked up,plus the name of the function to
          //look up. Return type is a pointer to the specified function.
          
          TRYX_API_EXP template<typename TSignature>
          static TSignature GetFunctionPointer(Handle sharedLibHandle,
                            const char* funcname)
          {
             FARPROC funcAddress = GetProcAddress(sharedLibHandle,funcname);
             if(funcAddress == nullptr){
                throw std::runtime_error("sharedlib.hpp : Line 63,couldn't find exported function.");
             }
             return reinterpret_cast<TSignature>(funcAddress);
          }
   }
   
   #endif
   
//----------------------------------------------------------------------------//

#if defined TRYX_LINUX
   
class SharedLib{
   public:
      typedef void* Handle;
      
      TRYX_API_EXP static Handle Load(const std::string& path){
         std::string pathWithExtension = std::string("./lib") + path + std::string(".so");
         void* sharedObject = dlopen(pathWithExtension.c_str(),RTLD_NOW);
         if(sharedObject == nullptr){
            throw std::runtime_error(
               std::string("sharedlib.hpp : Line 82,couldn't load '") + pathWithExtension + "'");
         }
         return sharedObject;
      }
      
      TRYX_API_EXP static Handle Load(const char* path){
          std::string temp; temp.assign(path);
          temp = std::string("./lib") + temp + std::string(".so");
          void* sharedObject = dlopen(temp.c_str(),RTLD_NOW);
         if(sharedObject == nullptr){
            std::string s = "sharedlib.hpp : Line 93,couldn't load '" + temp + "'";
            throw std::runtime_error(s);
         }
         return sharedObject;
      } 
      
      TRYX_API_EXP static void Unload(Handle sharedLibHandle){
         int result = dlclose(sharedLibHandle);
         if(result != 0){
            throw std::runtime_error("sharedlib.hpp : Line 93,couldn't unload shared object.");
         }
      }
      
      template<typename TSignature>
      TRYX_API_EXP static TSignature GetFunctionPointer(Handle sharedLibHandle,
                        const char* funcname){
         dlerror();
         void* funcAddress = dlsym(sharedLibHandle,funcname);
         const char *error = dlerror();
         if(error != nullptr){
            throw std::runtime_error
            ("sharedlib.hpp : Line 104,couldn't find exported function.");
         } 
         return reinterpret_cast<TSignature>(funcAddress);  
      }
};

#endif
   
// ---------------------------------------------------------------------------//

} // namespace Tryx

#endif // SHAREDLIB_HPP
    










