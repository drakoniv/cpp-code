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
include CMakeFiles/product.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/product.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/product.dir/flags.make

CMakeFiles/product.dir/product.cpp.obj: CMakeFiles/product.dir/flags.make
CMakeFiles/product.dir/product.cpp.obj: ../product.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\cpp code\basics1-program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/product.dir/product.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\product.dir\product.cpp.obj -c "D:\cpp code\basics1-program\product.cpp"

CMakeFiles/product.dir/product.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/product.dir/product.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\cpp code\basics1-program\product.cpp" > CMakeFiles\product.dir\product.cpp.i

CMakeFiles/product.dir/product.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/product.dir/product.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\cpp code\basics1-program\product.cpp" -o CMakeFiles\product.dir\product.cpp.s

# Object files for target product
product_OBJECTS = \
"CMakeFiles/product.dir/product.cpp.obj"

# External object files for target product
product_EXTERNAL_OBJECTS =

product.exe: CMakeFiles/product.dir/product.cpp.obj
product.exe: CMakeFiles/product.dir/build.make
product.exe: CMakeFiles/product.dir/linklibs.rsp
product.exe: CMakeFiles/product.dir/objects1.rsp
product.exe: CMakeFiles/product.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\cpp code\basics1-program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable product.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\product.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/product.dir/build: product.exe

.PHONY : CMakeFiles/product.dir/build

CMakeFiles/product.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\product.dir\cmake_clean.cmake
.PHONY : CMakeFiles/product.dir/clean

CMakeFiles/product.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\cpp code\basics1-program" "D:\cpp code\basics1-program" "D:\cpp code\basics1-program\cmake-build-debug" "D:\cpp code\basics1-program\cmake-build-debug" "D:\cpp code\basics1-program\cmake-build-debug\CMakeFiles\product.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/product.dir/depend

