# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /mnt/d/cpp-code/a

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/cpp-code/a/cmake-build-wsl_profile

# Include any dependencies generated for this target.
include CMakeFiles/a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a.dir/flags.make

CMakeFiles/a.dir/lab10.cpp.o: CMakeFiles/a.dir/flags.make
CMakeFiles/a.dir/lab10.cpp.o: ../lab10.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cpp-code/a/cmake-build-wsl_profile/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a.dir/lab10.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.dir/lab10.cpp.o -c /mnt/d/cpp-code/a/lab10.cpp

CMakeFiles/a.dir/lab10.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.dir/lab10.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cpp-code/a/lab10.cpp > CMakeFiles/a.dir/lab10.cpp.i

CMakeFiles/a.dir/lab10.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.dir/lab10.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cpp-code/a/lab10.cpp -o CMakeFiles/a.dir/lab10.cpp.s

CMakeFiles/a.dir/lab10.cpp.o.requires:

.PHONY : CMakeFiles/a.dir/lab10.cpp.o.requires

CMakeFiles/a.dir/lab10.cpp.o.provides: CMakeFiles/a.dir/lab10.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.dir/build.make CMakeFiles/a.dir/lab10.cpp.o.provides.build
.PHONY : CMakeFiles/a.dir/lab10.cpp.o.provides

CMakeFiles/a.dir/lab10.cpp.o.provides.build: CMakeFiles/a.dir/lab10.cpp.o


# Object files for target a
a_OBJECTS = \
"CMakeFiles/a.dir/lab10.cpp.o"

# External object files for target a
a_EXTERNAL_OBJECTS =

a : CMakeFiles/a.dir/lab10.cpp.o
a : CMakeFiles/a.dir/build.make
a : CMakeFiles/a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/cpp-code/a/cmake-build-wsl_profile/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable a"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a.dir/build: a

.PHONY : CMakeFiles/a.dir/build

CMakeFiles/a.dir/requires: CMakeFiles/a.dir/lab10.cpp.o.requires

.PHONY : CMakeFiles/a.dir/requires

CMakeFiles/a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a.dir/clean

CMakeFiles/a.dir/depend:
	cd /mnt/d/cpp-code/a/cmake-build-wsl_profile && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/cpp-code/a /mnt/d/cpp-code/a /mnt/d/cpp-code/a/cmake-build-wsl_profile /mnt/d/cpp-code/a/cmake-build-wsl_profile /mnt/d/cpp-code/a/cmake-build-wsl_profile/CMakeFiles/a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a.dir/depend

