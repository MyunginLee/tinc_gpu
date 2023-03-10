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
include tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/compiler_depend.make

# Include the progress variables for this target.
include tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/progress.make

# Include the compile flags for this target's objects.
include tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/flags.make

tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.o: tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/flags.make
tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.o: ../../tinc/external/al_ext/statedistribution/cuttlebone/scratch/sendto.cpp
tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.o: tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/Desktop/Projects/tinc_gpu/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.o"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/al_ext/statedistribution/cuttlebone && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.o -MF CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.o.d -o CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.o -c /home/ben/Desktop/Projects/tinc_gpu/tinc/external/al_ext/statedistribution/cuttlebone/scratch/sendto.cpp

tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.i"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/al_ext/statedistribution/cuttlebone && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/Desktop/Projects/tinc_gpu/tinc/external/al_ext/statedistribution/cuttlebone/scratch/sendto.cpp > CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.i

tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.s"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/al_ext/statedistribution/cuttlebone && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/Desktop/Projects/tinc_gpu/tinc/external/al_ext/statedistribution/cuttlebone/scratch/sendto.cpp -o CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.s

# Object files for target scratch_sendto
scratch_sendto_OBJECTS = \
"CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.o"

# External object files for target scratch_sendto
scratch_sendto_EXTERNAL_OBJECTS =

tinc/external/al_ext/statedistribution/cuttlebone/scratch_sendto: tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/scratch/sendto.cpp.o
tinc/external/al_ext/statedistribution/cuttlebone/scratch_sendto: tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/build.make
tinc/external/al_ext/statedistribution/cuttlebone/scratch_sendto: tinc/external/al_ext/statedistribution/cuttlebone/libcuttlebone.so
tinc/external/al_ext/statedistribution/cuttlebone/scratch_sendto: tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ben/Desktop/Projects/tinc_gpu/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable scratch_sendto"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/al_ext/statedistribution/cuttlebone && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scratch_sendto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/build: tinc/external/al_ext/statedistribution/cuttlebone/scratch_sendto
.PHONY : tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/build

tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/clean:
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/al_ext/statedistribution/cuttlebone && $(CMAKE_COMMAND) -P CMakeFiles/scratch_sendto.dir/cmake_clean.cmake
.PHONY : tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/clean

tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/depend:
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ben/Desktop/Projects/tinc_gpu /home/ben/Desktop/Projects/tinc_gpu/tinc/external/al_ext/statedistribution/cuttlebone /home/ben/Desktop/Projects/tinc_gpu/build/release /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/al_ext/statedistribution/cuttlebone /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tinc/external/al_ext/statedistribution/cuttlebone/CMakeFiles/scratch_sendto.dir/depend

