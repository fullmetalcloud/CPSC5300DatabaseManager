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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/stormregalia/Desktop/DBProject/Milestone2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/stormregalia/Desktop/DBProject/Milestone2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HLIB.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HLIB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HLIB.dir/flags.make

CMakeFiles/HLIB.dir/heap_storage.cpp.o: CMakeFiles/HLIB.dir/flags.make
CMakeFiles/HLIB.dir/heap_storage.cpp.o: ../heap_storage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stormregalia/Desktop/DBProject/Milestone2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HLIB.dir/heap_storage.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HLIB.dir/heap_storage.cpp.o -c /Users/stormregalia/Desktop/DBProject/Milestone2/heap_storage.cpp

CMakeFiles/HLIB.dir/heap_storage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HLIB.dir/heap_storage.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stormregalia/Desktop/DBProject/Milestone2/heap_storage.cpp > CMakeFiles/HLIB.dir/heap_storage.cpp.i

CMakeFiles/HLIB.dir/heap_storage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HLIB.dir/heap_storage.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stormregalia/Desktop/DBProject/Milestone2/heap_storage.cpp -o CMakeFiles/HLIB.dir/heap_storage.cpp.s

CMakeFiles/HLIB.dir/heap_storage.cpp.o.requires:

.PHONY : CMakeFiles/HLIB.dir/heap_storage.cpp.o.requires

CMakeFiles/HLIB.dir/heap_storage.cpp.o.provides: CMakeFiles/HLIB.dir/heap_storage.cpp.o.requires
	$(MAKE) -f CMakeFiles/HLIB.dir/build.make CMakeFiles/HLIB.dir/heap_storage.cpp.o.provides.build
.PHONY : CMakeFiles/HLIB.dir/heap_storage.cpp.o.provides

CMakeFiles/HLIB.dir/heap_storage.cpp.o.provides.build: CMakeFiles/HLIB.dir/heap_storage.cpp.o


# Object files for target HLIB
HLIB_OBJECTS = \
"CMakeFiles/HLIB.dir/heap_storage.cpp.o"

# External object files for target HLIB
HLIB_EXTERNAL_OBJECTS =

libHLIB.a: CMakeFiles/HLIB.dir/heap_storage.cpp.o
libHLIB.a: CMakeFiles/HLIB.dir/build.make
libHLIB.a: CMakeFiles/HLIB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/stormregalia/Desktop/DBProject/Milestone2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libHLIB.a"
	$(CMAKE_COMMAND) -P CMakeFiles/HLIB.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HLIB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HLIB.dir/build: libHLIB.a

.PHONY : CMakeFiles/HLIB.dir/build

CMakeFiles/HLIB.dir/requires: CMakeFiles/HLIB.dir/heap_storage.cpp.o.requires

.PHONY : CMakeFiles/HLIB.dir/requires

CMakeFiles/HLIB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HLIB.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HLIB.dir/clean

CMakeFiles/HLIB.dir/depend:
	cd /Users/stormregalia/Desktop/DBProject/Milestone2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/stormregalia/Desktop/DBProject/Milestone2 /Users/stormregalia/Desktop/DBProject/Milestone2 /Users/stormregalia/Desktop/DBProject/Milestone2/cmake-build-debug /Users/stormregalia/Desktop/DBProject/Milestone2/cmake-build-debug /Users/stormregalia/Desktop/DBProject/Milestone2/cmake-build-debug/CMakeFiles/HLIB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HLIB.dir/depend

