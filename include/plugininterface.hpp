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

#include "sharedlib.hpp"
#include "config.hpp"

// This is a very basic plugin interface,made for my IRC bot.
// If you want to make your own bot then change this class 
// according to your needs. 

namespace Tryx{
   class PluginInterface 
   {
      public:
         PluginInterface(){}
         virtual ~PluginInterface(){}

         virtual char* onCommand(const char* data)=default;
   };
} //namespace Tryx

#endif //define PLUGININTERFACE_HPP
   
