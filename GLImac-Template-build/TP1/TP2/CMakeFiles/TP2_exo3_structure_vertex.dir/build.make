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
include TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/depend.make

# Include the progress variables for this target.
include TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/progress.make

# Include the compile flags for this target's objects.
include TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/flags.make

TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o: TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/flags.make
TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o: /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP2/exo3_structure_vertex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o"
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/TP2 && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o -c /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP2/exo3_structure_vertex.cpp

TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.i"
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/TP2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP2/exo3_structure_vertex.cpp > CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.i

TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.s"
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/TP2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP2/exo3_structure_vertex.cpp -o CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.s

TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o.requires:

.PHONY : TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o.requires

TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o.provides: TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o.requires
	$(MAKE) -f TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/build.make TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o.provides.build
.PHONY : TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o.provides

TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o.provides.build: TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o


# Object files for target TP2_exo3_structure_vertex
TP2_exo3_structure_vertex_OBJECTS = \
"CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o"

# External object files for target TP2_exo3_structure_vertex
TP2_exo3_structure_vertex_EXTERNAL_OBJECTS =

TP2/TP2_exo3_structure_vertex: TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o
TP2/TP2_exo3_structure_vertex: TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/build.make
TP2/TP2_exo3_structure_vertex: glimac/libglimac.a
TP2/TP2_exo3_structure_vertex: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP2/TP2_exo3_structure_vertex: /usr/lib/x86_64-linux-gnu/libSDL.so
TP2/TP2_exo3_structure_vertex: /usr/lib/x86_64-linux-gnu/libGL.so.1
TP2/TP2_exo3_structure_vertex: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP2/TP2_exo3_structure_vertex: TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP2_exo3_structure_vertex"
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/TP2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP2_exo3_structure_vertex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/build: TP2/TP2_exo3_structure_vertex

.PHONY : TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/build

TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/requires: TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/exo3_structure_vertex.cpp.o.requires

.PHONY : TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/requires

TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/clean:
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/TP2 && $(CMAKE_COMMAND) -P CMakeFiles/TP2_exo3_structure_vertex.dir/cmake_clean.cmake
.PHONY : TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/clean

TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/depend:
	cd /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/TP2 /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1 /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/TP2 /home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template-build/TP1/TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP2/CMakeFiles/TP2_exo3_structure_vertex.dir/depend
