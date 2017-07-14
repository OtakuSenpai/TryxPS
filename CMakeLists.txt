cmake_minimum_required (VERSION 3.0)

# Project's name
project (TryxPS)

# Versioning !!
set (TryxPS_VERSION_MAJOR 1)
set (My_IRCBot_VERSION_MINOR 0)

#set standard
set(CMAKE_CXX_EXTENSIONS 14)

# set ouput dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# set executable path

# set library path
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# set include directory
include_directories("${PROJECT_SOURCE_DIR}/include")

# set sources
set(SOURCES "src/plugin.cpp"
            "src/kernel.cpp")   

# set headers
set(HEADERS "include/config.hpp"
                  "include/sharedlib.hpp"
                  "include/plugininterface.hpp"
                  "include/plugin.hpp"
                  "include/kernel.hpp") 

# compile flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic ")

# linker flags
add_library(plugin1 SHARED examples/plugin1.cpp ${HEADERS})

# static flags
add_library(tryxps STATIC ${SOURCES})

# execute
add_executable(pmain "main.cpp" ${SOURCES} ${HEADERS})

target_link_libraries(pmain ${CMAKE_DL_LIBS})

