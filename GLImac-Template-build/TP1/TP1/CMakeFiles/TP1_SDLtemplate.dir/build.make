# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1

# Include any dependencies generated for this target.
include TP1/CMakeFiles/TP1_SDLtemplate.dir/depend.make

# Include the progress variables for this target.
include TP1/CMakeFiles/TP1_SDLtemplate.dir/progress.make

# Include the compile flags for this target's objects.
include TP1/CMakeFiles/TP1_SDLtemplate.dir/flags.make

TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o: TP1/CMakeFiles/TP1_SDLtemplate.dir/flags.make
TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o: /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP1/SDLtemplate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o"
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/TP1 && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o -c /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP1/SDLtemplate.cpp

TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.i"
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/TP1 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP1/SDLtemplate.cpp > CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.i

TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.s"
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/TP1 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP1/SDLtemplate.cpp -o CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.s

TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o.requires:

.PHONY : TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o.requires

TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o.provides: TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o.requires
	$(MAKE) -f TP1/CMakeFiles/TP1_SDLtemplate.dir/build.make TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o.provides.build
.PHONY : TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o.provides

TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o.provides.build: TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o


# Object files for target TP1_SDLtemplate
TP1_SDLtemplate_OBJECTS = \
"CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o"

# External object files for target TP1_SDLtemplate
TP1_SDLtemplate_EXTERNAL_OBJECTS =

TP1/TP1_SDLtemplate: TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o
TP1/TP1_SDLtemplate: TP1/CMakeFiles/TP1_SDLtemplate.dir/build.make
TP1/TP1_SDLtemplate: glimac/libglimac.a
TP1/TP1_SDLtemplate: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP1/TP1_SDLtemplate: /usr/lib/x86_64-linux-gnu/libSDL.so
TP1/TP1_SDLtemplate: /usr/lib/x86_64-linux-gnu/libGL.so.1
TP1/TP1_SDLtemplate: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP1/TP1_SDLtemplate: TP1/CMakeFiles/TP1_SDLtemplate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP1_SDLtemplate"
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/TP1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP1_SDLtemplate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP1/CMakeFiles/TP1_SDLtemplate.dir/build: TP1/TP1_SDLtemplate

.PHONY : TP1/CMakeFiles/TP1_SDLtemplate.dir/build

TP1/CMakeFiles/TP1_SDLtemplate.dir/requires: TP1/CMakeFiles/TP1_SDLtemplate.dir/SDLtemplate.cpp.o.requires

.PHONY : TP1/CMakeFiles/TP1_SDLtemplate.dir/requires

TP1/CMakeFiles/TP1_SDLtemplate.dir/clean:
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/TP1 && $(CMAKE_COMMAND) -P CMakeFiles/TP1_SDLtemplate.dir/cmake_clean.cmake
.PHONY : TP1/CMakeFiles/TP1_SDLtemplate.dir/clean

TP1/CMakeFiles/TP1_SDLtemplate.dir/depend:
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP1 /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1 /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/TP1 /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/TP1/CMakeFiles/TP1_SDLtemplate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP1/CMakeFiles/TP1_SDLtemplate.dir/depend
