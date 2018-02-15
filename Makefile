# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/neelz/Programming_Workspace/C++_Workspace/Ma_Projects/CLI_Projects/TryxPS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/neelz/Programming_Workspace/C++_Workspace/Ma_Projects/CLI_Projects/TryxPS

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip

.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local

.PHONY : install/local/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Devel\" \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/neelz/Programming_Workspace/C++_Workspace/Ma_Projects/CLI_Projects/TryxPS/CMakeFiles /home/neelz/Programming_Workspace/C++_Workspace/Ma_Projects/CLI_Projects/TryxPS/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/neelz/Programming_Workspace/C++_Workspace/Ma_Projects/CLI_Projects/TryxPS/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named plugin1

# Build rule for target.
plugin1: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 plugin1
.PHONY : plugin1

# fast build rule for target.
plugin1/fast:
	$(MAKE) -f CMakeFiles/plugin1.dir/build.make CMakeFiles/plugin1.dir/build
.PHONY : plugin1/fast

#=============================================================================
# Target rules for targets named tryxps

# Build rule for target.
tryxps: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 tryxps
.PHONY : tryxps

# fast build rule for target.
tryxps/fast:
	$(MAKE) -f CMakeFiles/tryxps.dir/build.make CMakeFiles/tryxps.dir/build
.PHONY : tryxps/fast

#=============================================================================
# Target rules for targets named pmain

# Build rule for target.
pmain: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 pmain
.PHONY : pmain

# fast build rule for target.
pmain/fast:
	$(MAKE) -f CMakeFiles/pmain.dir/build.make CMakeFiles/pmain.dir/build
.PHONY : pmain/fast

examples/plugin1.o: examples/plugin1.cpp.o

.PHONY : examples/plugin1.o

# target to build an object file
examples/plugin1.cpp.o:
	$(MAKE) -f CMakeFiles/plugin1.dir/build.make CMakeFiles/plugin1.dir/examples/plugin1.cpp.o
.PHONY : examples/plugin1.cpp.o

examples/plugin1.i: examples/plugin1.cpp.i

.PHONY : examples/plugin1.i

# target to preprocess a source file
examples/plugin1.cpp.i:
	$(MAKE) -f CMakeFiles/plugin1.dir/build.make CMakeFiles/plugin1.dir/examples/plugin1.cpp.i
.PHONY : examples/plugin1.cpp.i

examples/plugin1.s: examples/plugin1.cpp.s

.PHONY : examples/plugin1.s

# target to generate assembly for a file
examples/plugin1.cpp.s:
	$(MAKE) -f CMakeFiles/plugin1.dir/build.make CMakeFiles/plugin1.dir/examples/plugin1.cpp.s
.PHONY : examples/plugin1.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/pmain.dir/build.make CMakeFiles/pmain.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/pmain.dir/build.make CMakeFiles/pmain.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/pmain.dir/build.make CMakeFiles/pmain.dir/main.cpp.s
.PHONY : main.cpp.s

src/kernel.o: src/kernel.cpp.o

.PHONY : src/kernel.o

# target to build an object file
src/kernel.cpp.o:
	$(MAKE) -f CMakeFiles/tryxps.dir/build.make CMakeFiles/tryxps.dir/src/kernel.cpp.o
	$(MAKE) -f CMakeFiles/pmain.dir/build.make CMakeFiles/pmain.dir/src/kernel.cpp.o
.PHONY : src/kernel.cpp.o

src/kernel.i: src/kernel.cpp.i

.PHONY : src/kernel.i

# target to preprocess a source file
src/kernel.cpp.i:
	$(MAKE) -f CMakeFiles/tryxps.dir/build.make CMakeFiles/tryxps.dir/src/kernel.cpp.i
	$(MAKE) -f CMakeFiles/pmain.dir/build.make CMakeFiles/pmain.dir/src/kernel.cpp.i
.PHONY : src/kernel.cpp.i

src/kernel.s: src/kernel.cpp.s

.PHONY : src/kernel.s

# target to generate assembly for a file
src/kernel.cpp.s:
	$(MAKE) -f CMakeFiles/tryxps.dir/build.make CMakeFiles/tryxps.dir/src/kernel.cpp.s
	$(MAKE) -f CMakeFiles/pmain.dir/build.make CMakeFiles/pmain.dir/src/kernel.cpp.s
.PHONY : src/kernel.cpp.s

src/plugin.o: src/plugin.cpp.o

.PHONY : src/plugin.o

# target to build an object file
src/plugin.cpp.o:
	$(MAKE) -f CMakeFiles/tryxps.dir/build.make CMakeFiles/tryxps.dir/src/plugin.cpp.o
	$(MAKE) -f CMakeFiles/pmain.dir/build.make CMakeFiles/pmain.dir/src/plugin.cpp.o
.PHONY : src/plugin.cpp.o

src/plugin.i: src/plugin.cpp.i

.PHONY : src/plugin.i

# target to preprocess a source file
src/plugin.cpp.i:
	$(MAKE) -f CMakeFiles/tryxps.dir/build.make CMakeFiles/tryxps.dir/src/plugin.cpp.i
	$(MAKE) -f CMakeFiles/pmain.dir/build.make CMakeFiles/pmain.dir/src/plugin.cpp.i
.PHONY : src/plugin.cpp.i

src/plugin.s: src/plugin.cpp.s

.PHONY : src/plugin.s

# target to generate assembly for a file
src/plugin.cpp.s:
	$(MAKE) -f CMakeFiles/tryxps.dir/build.make CMakeFiles/tryxps.dir/src/plugin.cpp.s
	$(MAKE) -f CMakeFiles/pmain.dir/build.make CMakeFiles/pmain.dir/src/plugin.cpp.s
.PHONY : src/plugin.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... install/local"
	@echo "... rebuild_cache"
	@echo "... plugin1"
	@echo "... edit_cache"
	@echo "... tryxps"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... pmain"
	@echo "... examples/plugin1.o"
	@echo "... examples/plugin1.i"
	@echo "... examples/plugin1.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/kernel.o"
	@echo "... src/kernel.i"
	@echo "... src/kernel.s"
	@echo "... src/plugin.o"
	@echo "... src/plugin.i"
	@echo "... src/plugin.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

