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
CMAKE_BINARY_DIR = /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build

# Include any dependencies generated for this target.
include TP7/CMakeFiles/TP7_04_cloud_textures.dir/depend.make

# Include the progress variables for this target.
include TP7/CMakeFiles/TP7_04_cloud_textures.dir/progress.make

# Include the compile flags for this target's objects.
include TP7/CMakeFiles/TP7_04_cloud_textures.dir/flags.make

TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o: TP7/CMakeFiles/TP7_04_cloud_textures.dir/flags.make
TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o: /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP7/04_cloud_textures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o"
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP7 && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o -c /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP7/04_cloud_textures.cpp

TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.i"
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP7 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP7/04_cloud_textures.cpp > CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.i

TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.s"
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP7 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP7/04_cloud_textures.cpp -o CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.s

TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o.requires:

.PHONY : TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o.requires

TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o.provides: TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o.requires
	$(MAKE) -f TP7/CMakeFiles/TP7_04_cloud_textures.dir/build.make TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o.provides.build
.PHONY : TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o.provides

TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o.provides.build: TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o


# Object files for target TP7_04_cloud_textures
TP7_04_cloud_textures_OBJECTS = \
"CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o"

# External object files for target TP7_04_cloud_textures
TP7_04_cloud_textures_EXTERNAL_OBJECTS =

TP7/TP7_04_cloud_textures: TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o
TP7/TP7_04_cloud_textures: TP7/CMakeFiles/TP7_04_cloud_textures.dir/build.make
TP7/TP7_04_cloud_textures: glimac/libglimac.a
TP7/TP7_04_cloud_textures: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP7/TP7_04_cloud_textures: /usr/lib/x86_64-linux-gnu/libSDL.so
TP7/TP7_04_cloud_textures: /usr/lib/x86_64-linux-gnu/libGL.so.1
TP7/TP7_04_cloud_textures: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP7/TP7_04_cloud_textures: TP7/CMakeFiles/TP7_04_cloud_textures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP7_04_cloud_textures"
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP7 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP7_04_cloud_textures.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP7/CMakeFiles/TP7_04_cloud_textures.dir/build: TP7/TP7_04_cloud_textures

.PHONY : TP7/CMakeFiles/TP7_04_cloud_textures.dir/build

TP7/CMakeFiles/TP7_04_cloud_textures.dir/requires: TP7/CMakeFiles/TP7_04_cloud_textures.dir/04_cloud_textures.cpp.o.requires

.PHONY : TP7/CMakeFiles/TP7_04_cloud_textures.dir/requires

TP7/CMakeFiles/TP7_04_cloud_textures.dir/clean:
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP7 && $(CMAKE_COMMAND) -P CMakeFiles/TP7_04_cloud_textures.dir/cmake_clean.cmake
.PHONY : TP7/CMakeFiles/TP7_04_cloud_textures.dir/clean

TP7/CMakeFiles/TP7_04_cloud_textures.dir/depend:
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP7 /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP7 /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP7/CMakeFiles/TP7_04_cloud_textures.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP7/CMakeFiles/TP7_04_cloud_textures.dir/depend
