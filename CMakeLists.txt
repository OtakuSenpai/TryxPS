cmake_minimum_required (VERSION 2.6)
project (TryxPS)
set (TryxPS_VERSION_MAJOR 1)
set (My_IRCBot_VERSION_MINOR 0)

include_directories(include)

set(HEADERS "include/config.hpp"
            "include/sharedlib.hpp"
	    "include/tryxlist.hpp"
	    "include/kernel.hpp"
	    "include/plugin.hpp"
            "include/plugininterface.hpp")
                       
      

set(SOURCES "src/plugin.cpp"
            "src/kernel.cpp")

if(MSVC) 
	source_group("Header Files" FILES ${HEADERS})
endif()

add_executable(a.out ${SOURCES} ${HEADERS})
