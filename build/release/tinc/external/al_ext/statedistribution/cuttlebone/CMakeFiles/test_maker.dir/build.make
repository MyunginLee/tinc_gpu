# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ben/Desktop/Projects/tinc_gpu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ben/Desktop/Projects/tinc_gpu/build/release

# Include any dependencies generated for this target.
include tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/compiler_depend.make

# Include the progress variables for this target.
include tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/progress.make

# Include the compile flags for this target's objects.
include tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/flags.make

tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/test/maker.cpp.o: tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/flags.make
tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/test/maker.cpp.o: ../../tinc/external/al_ext/statedistribution/cuttlebone/test/maker.cpp
tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/test/maker.cpp.o: tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/Desktop/Projects/tinc_gpu/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/test/maker.cpp.o"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/al_ext/statedistribution/cuttlebone && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/test/maker.cpp.o -MF CMakeFiles/test_maker.dir/test/maker.cpp.o.d -o CMakeFiles/test_maker.dir/test/maker.cpp.o -c /home/ben/Desktop/Projects/tinc_gpu/tinc/external/al_ext/statedistribution/cuttlebone/test/maker.cpp

tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/test/maker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_maker.dir/test/maker.cpp.i"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/al_ext/statedistribution/cuttlebone && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/Desktop/Projects/tinc_gpu/tinc/external/al_ext/statedistribution/cuttlebone/test/maker.cpp > CMakeFiles/test_maker.dir/test/maker.cpp.i

tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/test/maker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_maker.dir/test/maker.cpp.s"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/al_ext/statedistribution/cuttlebone && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/Desktop/Projects/tinc_gpu/tinc/external/al_ext/statedistribution/cuttlebone/test/maker.cpp -o CMakeFiles/test_maker.dir/test/maker.cpp.s

# Object files for target test_maker
test_maker_OBJECTS = \
"CMakeFiles/test_maker.dir/test/maker.cpp.o"

# External object files for target test_maker
test_maker_EXTERNAL_OBJECTS =

tinc/external/al_ext/statedistribution/cuttlebone/test_maker: tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/test/maker.cpp.o
tinc/external/al_ext/statedistribution/cuttlebone/test_maker: tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/build.make
tinc/external/al_ext/statedistribution/cuttlebone/test_maker: tinc/external/al_ext/statedistribution/cuttlebone/libcuttlebone.so
tinc/external/al_ext/statedistribution/cuttlebone/test_maker: tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ben/Desktop/Projects/tinc_gpu/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_maker"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/al_ext/statedistribution/cuttlebone && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_maker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/build: tinc/external/al_ext/statedistribution/cuttlebone/test_maker
.PHONY : tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/build

tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/clean:
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/al_ext/statedistribution/cuttlebone && $(CMAKE_COMMAND) -P CMakeFiles/test_maker.dir/cmake_clean.cmake
.PHONY : tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/clean

tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/depend:
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ben/Desktop/Projects/tinc_gpu /home/ben/Desktop/Projects/tinc_gpu/tinc/external/al_ext/statedistribution/cuttlebone /home/ben/Desktop/Projects/tinc_gpu/build/release /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/al_ext/statedistribution/cuttlebone /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/test_maker.dir/depend

