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
CMAKE_SOURCE_DIR = "D:\cpp code\wscgame"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\cpp code\wscgame\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/wscgame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wscgame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wscgame.dir/flags.make

CMakeFiles/wscgame.dir/main.cpp.obj: CMakeFiles/wscgame.dir/flags.make
CMakeFiles/wscgame.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\cpp code\wscgame\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wscgame.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\wscgame.dir\main.cpp.obj -c "D:\cpp code\wscgame\main.cpp"

CMakeFiles/wscgame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wscgame.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\cpp code\wscgame\main.cpp" > CMakeFiles\wscgame.dir\main.cpp.i

CMakeFiles/wscgame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wscgame.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\cpp code\wscgame\main.cpp" -o CMakeFiles\wscgame.dir\main.cpp.s

# Object files for target wscgame
wscgame_OBJECTS = \
"CMakeFiles/wscgame.dir/main.cpp.obj"

# External object files for target wscgame
wscgame_EXTERNAL_OBJECTS =

wscgame.exe: CMakeFiles/wscgame.dir/main.cpp.obj
wscgame.exe: CMakeFiles/wscgame.dir/build.make
wscgame.exe: CMakeFiles/wscgame.dir/linklibs.rsp
wscgame.exe: CMakeFiles/wscgame.dir/objects1.rsp
wscgame.exe: CMakeFiles/wscgame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\cpp code\wscgame\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable wscgame.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\wscgame.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wscgame.dir/build: wscgame.exe

.PHONY : CMakeFiles/wscgame.dir/build

CMakeFiles/wscgame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\wscgame.dir\cmake_clean.cmake
.PHONY : CMakeFiles/wscgame.dir/clean

CMakeFiles/wscgame.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\cpp code\wscgame" "D:\cpp code\wscgame" "D:\cpp code\wscgame\cmake-build-debug" "D:\cpp code\wscgame\cmake-build-debug" "D:\cpp code\wscgame\cmake-build-debug\CMakeFiles\wscgame.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/wscgame.dir/depend
