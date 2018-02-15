cmake_minimum_required(VERSION 3.0)

project(TryxPS)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

set(TryxPS_VERSION 0.7)

include(GenerateExportHeader)

set(CMAKE_CXX_EXTENSIONS 14)

include_directories("${PROJECT_SOURCE_DIR}/include")

set(SOURCES "src/plugin.cpp"
            "src/kernel.cpp")

set(HEADERS "include/config.hpp"
            "include/sharedlib.hpp"
            "include/plugininterface.hpp"
            "include/plugin.hpp"
            "include/kernel.hpp")

if(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 6.3)
    message(FATAL_ERROR "g++ version must be at least 6.3!")
 endif() 
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -O2")
endif()

add_library(plugin1 SHARED examples/plugin1.cpp ${HEADERS})

add_library(tryxps STATIC ${SOURCES})
target_link_libraries(tryxps ${CMAKE_DL_LIBS})

generate_export_header(tryxps)
target_include_directories(tryxps PUBLIC
       $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
       $<INSTALL_INTERFACE:include>)

#generate_export_header(${HEADERS})

install(TARGETS tryxps EXPORT TryxPSTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)

install(
  FILES
    kernel.h
    "${CMAKE_CURRENT_BINARY_DIR}/tryxps_export.h"
  DESTINATION
    include
  COMPONENT
    Devel
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/TryxPSConfigVersion.cmake"
  VERSION ${TryxPS_VERSION}
  COMPATIBILITY AnyNewerVersion)

export(EXPORT TryxPSTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/TryxPSTargets.cmake"
  NAMESPACE TryxPS::)

configure_file(cmake/TryxPSConfig.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/TryxPSConfig.cmake"
  COPYONLY
)

set(ConfigPackageLocation lib/TryxPS)
install(EXPORT TryxPSTargets
  FILE
    TryxPSTargets.cmake
  NAMESPACE
    TryxPS::
  DESTINATION
    ${ConfigPackageLocation}
)
install(
  FILES
    cmake/TryxPSConfig.cmake
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/TryxPSConfigVersion.cmake"
  DESTINATION
    ${ConfigPackageLocation}
  COMPONENT
    Devel
)

add_executable(pmain "main.cpp" ${SOURCES} ${HEADERS})
target_link_libraries(pmain ${CMAKE_DL_LIBS})
