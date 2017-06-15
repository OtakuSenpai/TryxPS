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

#pragma once
#ifndef CONFIG_HPP
#define CONFIG_HPP

//Platform recognition

#ifdef WIN32 || defined _WIN32 
   #define TRYX_WIN32 1
#else
   #define TRYX_LINUX 1
#endif

//----------------------------------------------------------------------------//

//Decides whether to import symbols from a dll or export to a dll.
//TRYX_SOURCE and TRYX_STATICLIB must be defined in the source files to make
//the actual exporting or importing work.                                     

//The macro code is basically checking whether you statically linked
//the library or not. Otherwise, it checks whether to import or
//export functions for usage.

#ifdef _MSC_VER
   #ifdef TRYX_STATICLIB
      #define TRYX_API_EXP
   #else
      //Define this in the derived plugin 
      #ifdef TRYX_SOURCE 
         //If we are building the DLL,export the symbols tagged like this
         //Add this before a symbol to be exported
         #define TRYX_API_EXP __declspec(dllexport)
         //Add this in the source file of the derived plugin
         #define SET_PLUGIN_VERS(x) extern "C"{__declspec(dllexport) 
            const char * getPluginVers(){ return x;}}
         //Add this in the source file of the derived plugin
         #define SET_PLUGIN_NAME(x) extern "C"{__declspec(dllexport) 
            const char * getPluginName(){ return x;}}
      #else
      // If we are consuming the DLL, import the symbols tagged like this
         #define TRYX_API_IMP __declspec(dllimport)
      #endif
   #endif
#elif defined __GNUC__ 
   #if defined TRYX_STATICLIB
      #define TRYX_API  
   #else
      #if defined TRYX_SOURCE
         #define TRYX_API_EXP __attribute__((visibility("default")))
         #define SET_PLUGIN_Vers(x) extern "C"{__attribute__ ((dllexport))
             const char * getPluginVers(){ return x;}}
         #define SET_PLUGIN_NAME(x) extern "C"{__attribute__ ((dllexport))
             const char * getPluginName(){ return x;}}
      #else
         #define TRYX_API_IMP __attribute__ ((visibility ("default")))
      #endif
   #endif
 #else
   #error Unknown compiler, please implement shared library macros!!!             
#endif   
      
//----------------------------------------------------------------------------//

#endif // CONFIG_HPP
