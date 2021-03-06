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

#ifndef PLUGININTERFACE_HPP
#define PLUGININTERFACE_HPP

#if defined _WIN32
  #define TRYX_API_EXP __declspec(dllexport)
#elif defined __GNUC__
  #define TRYX_API_EXP __attribute__((visibility("default")))
#endif

// This is a very basic plugin interface,made for my IRC bot.
// If you want to make your own bot then change this class 
// according to your needs. 

namespace Tryx{
   
   class PluginInterface 
   {
      public:
        TRYX_API_EXP PluginInterface() {}
        TRYX_API_EXP virtual ~PluginInterface() {}

        TRYX_API_EXP virtual char* onCommand(const char* word,const char* data)=0;
   };
} //namespace Tryx

#endif //define PLUGININTERFACE_HPP
   
