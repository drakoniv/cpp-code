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
CMAKE_SOURCE_DIR = /mnt/d/cpp-code/pa3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/cpp-code/pa3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pa3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pa3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pa3.dir/flags.make

CMakeFiles/pa3.dir/canvas.cpp.o: CMakeFiles/pa3.dir/flags.make
CMakeFiles/pa3.dir/canvas.cpp.o: ../canvas.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cpp-code/pa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pa3.dir/canvas.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa3.dir/canvas.cpp.o -c /mnt/d/cpp-code/pa3/canvas.cpp

CMakeFiles/pa3.dir/canvas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa3.dir/canvas.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cpp-code/pa3/canvas.cpp > CMakeFiles/pa3.dir/canvas.cpp.i

CMakeFiles/pa3.dir/canvas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa3.dir/canvas.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cpp-code/pa3/canvas.cpp -o CMakeFiles/pa3.dir/canvas.cpp.s

CMakeFiles/pa3.dir/canvas.cpp.o.requires:

.PHONY : CMakeFiles/pa3.dir/canvas.cpp.o.requires

CMakeFiles/pa3.dir/canvas.cpp.o.provides: CMakeFiles/pa3.dir/canvas.cpp.o.requires
	$(MAKE) -f CMakeFiles/pa3.dir/build.make CMakeFiles/pa3.dir/canvas.cpp.o.provides.build
.PHONY : CMakeFiles/pa3.dir/canvas.cpp.o.provides

CMakeFiles/pa3.dir/canvas.cpp.o.provides.build: CMakeFiles/pa3.dir/canvas.cpp.o


CMakeFiles/pa3.dir/main.cpp.o: CMakeFiles/pa3.dir/flags.make
CMakeFiles/pa3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cpp-code/pa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pa3.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa3.dir/main.cpp.o -c /mnt/d/cpp-code/pa3/main.cpp

CMakeFiles/pa3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cpp-code/pa3/main.cpp > CMakeFiles/pa3.dir/main.cpp.i

CMakeFiles/pa3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cpp-code/pa3/main.cpp -o CMakeFiles/pa3.dir/main.cpp.s

CMakeFiles/pa3.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/pa3.dir/main.cpp.o.requires

CMakeFiles/pa3.dir/main.cpp.o.provides: CMakeFiles/pa3.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/pa3.dir/build.make CMakeFiles/pa3.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/pa3.dir/main.cpp.o.provides

CMakeFiles/pa3.dir/main.cpp.o.provides.build: CMakeFiles/pa3.dir/main.cpp.o


CMakeFiles/pa3.dir/patch.cpp.o: CMakeFiles/pa3.dir/flags.make
CMakeFiles/pa3.dir/patch.cpp.o: ../patch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cpp-code/pa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pa3.dir/patch.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa3.dir/patch.cpp.o -c /mnt/d/cpp-code/pa3/patch.cpp

CMakeFiles/pa3.dir/patch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa3.dir/patch.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cpp-code/pa3/patch.cpp > CMakeFiles/pa3.dir/patch.cpp.i

CMakeFiles/pa3.dir/patch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa3.dir/patch.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cpp-code/pa3/patch.cpp -o CMakeFiles/pa3.dir/patch.cpp.s

CMakeFiles/pa3.dir/patch.cpp.o.requires:

.PHONY : CMakeFiles/pa3.dir/patch.cpp.o.requires

CMakeFiles/pa3.dir/patch.cpp.o.provides: CMakeFiles/pa3.dir/patch.cpp.o.requires
	$(MAKE) -f CMakeFiles/pa3.dir/build.make CMakeFiles/pa3.dir/patch.cpp.o.provides.build
.PHONY : CMakeFiles/pa3.dir/patch.cpp.o.provides

CMakeFiles/pa3.dir/patch.cpp.o.provides.build: CMakeFiles/pa3.dir/patch.cpp.o


CMakeFiles/pa3.dir/repl.cpp.o: CMakeFiles/pa3.dir/flags.make
CMakeFiles/pa3.dir/repl.cpp.o: ../repl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cpp-code/pa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pa3.dir/repl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa3.dir/repl.cpp.o -c /mnt/d/cpp-code/pa3/repl.cpp

CMakeFiles/pa3.dir/repl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa3.dir/repl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cpp-code/pa3/repl.cpp > CMakeFiles/pa3.dir/repl.cpp.i

CMakeFiles/pa3.dir/repl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa3.dir/repl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cpp-code/pa3/repl.cpp -o CMakeFiles/pa3.dir/repl.cpp.s

CMakeFiles/pa3.dir/repl.cpp.o.requires:

.PHONY : CMakeFiles/pa3.dir/repl.cpp.o.requires

CMakeFiles/pa3.dir/repl.cpp.o.provides: CMakeFiles/pa3.dir/repl.cpp.o.requires
	$(MAKE) -f CMakeFiles/pa3.dir/build.make CMakeFiles/pa3.dir/repl.cpp.o.provides.build
.PHONY : CMakeFiles/pa3.dir/repl.cpp.o.provides

CMakeFiles/pa3.dir/repl.cpp.o.provides.build: CMakeFiles/pa3.dir/repl.cpp.o


CMakeFiles/pa3.dir/utils.cpp.o: CMakeFiles/pa3.dir/flags.make
CMakeFiles/pa3.dir/utils.cpp.o: ../utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cpp-code/pa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pa3.dir/utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa3.dir/utils.cpp.o -c /mnt/d/cpp-code/pa3/utils.cpp

CMakeFiles/pa3.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa3.dir/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cpp-code/pa3/utils.cpp > CMakeFiles/pa3.dir/utils.cpp.i

CMakeFiles/pa3.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa3.dir/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cpp-code/pa3/utils.cpp -o CMakeFiles/pa3.dir/utils.cpp.s

CMakeFiles/pa3.dir/utils.cpp.o.requires:

.PHONY : CMakeFiles/pa3.dir/utils.cpp.o.requires

CMakeFiles/pa3.dir/utils.cpp.o.provides: CMakeFiles/pa3.dir/utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/pa3.dir/build.make CMakeFiles/pa3.dir/utils.cpp.o.provides.build
.PHONY : CMakeFiles/pa3.dir/utils.cpp.o.provides

CMakeFiles/pa3.dir/utils.cpp.o.provides.build: CMakeFiles/pa3.dir/utils.cpp.o


# Object files for target pa3
pa3_OBJECTS = \
"CMakeFiles/pa3.dir/canvas.cpp.o" \
"CMakeFiles/pa3.dir/main.cpp.o" \
"CMakeFiles/pa3.dir/patch.cpp.o" \
"CMakeFiles/pa3.dir/repl.cpp.o" \
"CMakeFiles/pa3.dir/utils.cpp.o"

# External object files for target pa3
pa3_EXTERNAL_OBJECTS =

pa3: CMakeFiles/pa3.dir/canvas.cpp.o
pa3: CMakeFiles/pa3.dir/main.cpp.o
pa3: CMakeFiles/pa3.dir/patch.cpp.o
pa3: CMakeFiles/pa3.dir/repl.cpp.o
pa3: CMakeFiles/pa3.dir/utils.cpp.o
pa3: CMakeFiles/pa3.dir/build.make
pa3: CMakeFiles/pa3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/cpp-code/pa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable pa3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pa3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pa3.dir/build: pa3

.PHONY : CMakeFiles/pa3.dir/build

CMakeFiles/pa3.dir/requires: CMakeFiles/pa3.dir/canvas.cpp.o.requires
CMakeFiles/pa3.dir/requires: CMakeFiles/pa3.dir/main.cpp.o.requires
CMakeFiles/pa3.dir/requires: CMakeFiles/pa3.dir/patch.cpp.o.requires
CMakeFiles/pa3.dir/requires: CMakeFiles/pa3.dir/repl.cpp.o.requires
CMakeFiles/pa3.dir/requires: CMakeFiles/pa3.dir/utils.cpp.o.requires

.PHONY : CMakeFiles/pa3.dir/requires

CMakeFiles/pa3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pa3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pa3.dir/clean

CMakeFiles/pa3.dir/depend:
	cd /mnt/d/cpp-code/pa3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/cpp-code/pa3 /mnt/d/cpp-code/pa3 /mnt/d/cpp-code/pa3/cmake-build-debug /mnt/d/cpp-code/pa3/cmake-build-debug /mnt/d/cpp-code/pa3/cmake-build-debug/CMakeFiles/pa3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pa3.dir/depend
