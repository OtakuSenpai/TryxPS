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

#ifndef KERNEL_HPP
#define KERNEL_HPP

#include "plugin.hpp"
#include "config.hpp"
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

namespace Tryx {

  //The engine's core
  class Kernel {
    private:
      
      class Node {
        public:
          Node() : _name(), _data() {}
          Node(std::string& name,Plugin* data) : _name(name), _data(new Plugin(data)) {}
          Node(const Node& other) {
            try {
              _name = other.getName();
              _data = other.getData();
            }
            catch(std::exception& e) {
              std::cerr<<"Caught exception: \n"<<e.what();
            }
          }
          Node& operator=(const Node& other) {
            try {
              _name = other.getName();
              _data = other.getData();
            }
            catch(std::exception& e) {
              std::cerr<<"Caught exception: \n"<<e.what(); 
            }
            return *this;
          }
          ~Node() {}
          std::string getName() const{ return _name; }
          std::shared_ptr<Plugin> getData() const{ return _data; }    
        
        private:
          std::string _name;
          std::shared_ptr<Plugin> _data;
      };
        
      //Map of plugins by their associated file names
      std::vector<Kernel::Node*> loadedPlugins;

    public: 
       
       Kernel() : loadedPlugins() {}
       ~Kernel() { unloadPlugins(); }
       Kernel(const std::string& path,bool& doIt) : loadedPlugins() { loadPlugins(path,doIt); }
       
       void loadPlugin(const std::string& path);
         
       // Loads all plugins present in a directory.
       void loadPlugins(const std::string& path,bool addIt);
       
       // Unloads all plugins 
       void unloadPlugins();
       
       //Helper functions
       PluginInterface* getFuncHandle(const std::string& identifier);
       std::string getPluginName (const int& index) const;
       int getFuncPos (const std::string& identifier) const;
       int getFuncPos (const char* identifier) const;
       
       std::vector<Kernel::Node*> getPlugins() { return loadedPlugins; }
       int getSize() const{ return loadedPlugins.size(); }
  };

} // namespace Tryx

#endif //KERNEL_HPP
