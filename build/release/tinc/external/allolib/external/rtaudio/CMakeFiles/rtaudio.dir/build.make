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
include tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/compiler_depend.make

# Include the progress variables for this target.
include tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/progress.make

# Include the compile flags for this target's objects.
include tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/flags.make

tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.o: tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/flags.make
tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.o: ../../tinc/external/allolib/external/rtaudio/RtAudio.cpp
tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.o: tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/Desktop/Projects/tinc_gpu/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.o"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/allolib/external/rtaudio && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.o -MF CMakeFiles/rtaudio.dir/RtAudio.cpp.o.d -o CMakeFiles/rtaudio.dir/RtAudio.cpp.o -c /home/ben/Desktop/Projects/tinc_gpu/tinc/external/allolib/external/rtaudio/RtAudio.cpp

tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rtaudio.dir/RtAudio.cpp.i"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/allolib/external/rtaudio && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/Desktop/Projects/tinc_gpu/tinc/external/allolib/external/rtaudio/RtAudio.cpp > CMakeFiles/rtaudio.dir/RtAudio.cpp.i

tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rtaudio.dir/RtAudio.cpp.s"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/allolib/external/rtaudio && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/Desktop/Projects/tinc_gpu/tinc/external/allolib/external/rtaudio/RtAudio.cpp -o CMakeFiles/rtaudio.dir/RtAudio.cpp.s

tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.o: tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/flags.make
tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.o: ../../tinc/external/allolib/external/rtaudio/rtaudio_c.cpp
tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.o: tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/Desktop/Projects/tinc_gpu/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.o"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/allolib/external/rtaudio && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.o -MF CMakeFiles/rtaudio.dir/rtaudio_c.cpp.o.d -o CMakeFiles/rtaudio.dir/rtaudio_c.cpp.o -c /home/ben/Desktop/Projects/tinc_gpu/tinc/external/allolib/external/rtaudio/rtaudio_c.cpp

tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rtaudio.dir/rtaudio_c.cpp.i"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/allolib/external/rtaudio && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/Desktop/Projects/tinc_gpu/tinc/external/allolib/external/rtaudio/rtaudio_c.cpp > CMakeFiles/rtaudio.dir/rtaudio_c.cpp.i

tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rtaudio.dir/rtaudio_c.cpp.s"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/allolib/external/rtaudio && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/Desktop/Projects/tinc_gpu/tinc/external/allolib/external/rtaudio/rtaudio_c.cpp -o CMakeFiles/rtaudio.dir/rtaudio_c.cpp.s

# Object files for target rtaudio
rtaudio_OBJECTS = \
"CMakeFiles/rtaudio.dir/RtAudio.cpp.o" \
"CMakeFiles/rtaudio.dir/rtaudio_c.cpp.o"

# External object files for target rtaudio
rtaudio_EXTERNAL_OBJECTS =

tinc/external/allolib/external/rtaudio/librtaudio.a: tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/RtAudio.cpp.o
tinc/external/allolib/external/rtaudio/librtaudio.a: tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/rtaudio_c.cpp.o
tinc/external/allolib/external/rtaudio/librtaudio.a: tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/build.make
tinc/external/allolib/external/rtaudio/librtaudio.a: tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ben/Desktop/Projects/tinc_gpu/build/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library librtaudio.a"
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/allolib/external/rtaudio && $(CMAKE_COMMAND) -P CMakeFiles/rtaudio.dir/cmake_clean_target.cmake
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/allolib/external/rtaudio && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rtaudio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/build: tinc/external/allolib/external/rtaudio/librtaudio.a
.PHONY : tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/build

tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/clean:
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/allolib/external/rtaudio && $(CMAKE_COMMAND) -P CMakeFiles/rtaudio.dir/cmake_clean.cmake
.PHONY : tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/clean

tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/depend:
	cd /home/ben/Desktop/Projects/tinc_gpu/build/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ben/Desktop/Projects/tinc_gpu /home/ben/Desktop/Projects/tinc_gpu/tinc/external/allolib/external/rtaudio /home/ben/Desktop/Projects/tinc_gpu/build/release /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/allolib/external/rtaudio /home/ben/Desktop/Projects/tinc_gpu/build/release/tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tinc/external/allolib/external/rtaudio/CMakeFiles/rtaudio.dir/depend

