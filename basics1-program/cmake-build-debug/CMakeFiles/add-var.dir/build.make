# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\drako\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6262.62\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\drako\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6262.62\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\cpp code\basics1-program"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\cpp code\basics1-program\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/add-var.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/add-var.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/add-var.dir/flags.make

CMakeFiles/add-var.dir/add-var.cpp.obj: CMakeFiles/add-var.dir/flags.make
CMakeFiles/add-var.dir/add-var.cpp.obj: ../add-var.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\cpp code\basics1-program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/add-var.dir/add-var.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\add-var.dir\add-var.cpp.obj -c "D:\cpp code\basics1-program\add-var.cpp"

CMakeFiles/add-var.dir/add-var.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/add-var.dir/add-var.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\cpp code\basics1-program\add-var.cpp" > CMakeFiles\add-var.dir\add-var.cpp.i

CMakeFiles/add-var.dir/add-var.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/add-var.dir/add-var.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\cpp code\basics1-program\add-var.cpp" -o CMakeFiles\add-var.dir\add-var.cpp.s

# Object files for target add-var
add__var_OBJECTS = \
"CMakeFiles/add-var.dir/add-var.cpp.obj"

# External object files for target add-var
add__var_EXTERNAL_OBJECTS =

add-var.exe: CMakeFiles/add-var.dir/add-var.cpp.obj
add-var.exe: CMakeFiles/add-var.dir/build.make
add-var.exe: CMakeFiles/add-var.dir/linklibs.rsp
add-var.exe: CMakeFiles/add-var.dir/objects1.rsp
add-var.exe: CMakeFiles/add-var.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\cpp code\basics1-program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable add-var.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\add-var.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/add-var.dir/build: add-var.exe

.PHONY : CMakeFiles/add-var.dir/build

CMakeFiles/add-var.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\add-var.dir\cmake_clean.cmake
.PHONY : CMakeFiles/add-var.dir/clean

CMakeFiles/add-var.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\cpp code\basics1-program" "D:\cpp code\basics1-program" "D:\cpp code\basics1-program\cmake-build-debug" "D:\cpp code\basics1-program\cmake-build-debug" "D:\cpp code\basics1-program\cmake-build-debug\CMakeFiles\add-var.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/add-var.dir/depend

