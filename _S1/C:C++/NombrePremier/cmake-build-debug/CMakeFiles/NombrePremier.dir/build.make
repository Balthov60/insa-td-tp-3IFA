# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/JetBrains/apps/CLion/ch-0/183.4588.63/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/JetBrains/apps/CLion/ch-0/183.4588.63/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/balthazarfrolin/Documents/INSA/Repositories/C:C++/NombrePremier

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/balthazarfrolin/Documents/INSA/Repositories/C:C++/NombrePremier/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NombrePremier.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NombrePremier.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NombrePremier.dir/flags.make

CMakeFiles/NombrePremier.dir/main.cpp.o: CMakeFiles/NombrePremier.dir/flags.make
CMakeFiles/NombrePremier.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/balthazarfrolin/Documents/INSA/Repositories/C:C++/NombrePremier/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NombrePremier.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NombrePremier.dir/main.cpp.o -c /Users/balthazarfrolin/Documents/INSA/Repositories/C:C++/NombrePremier/main.cpp

CMakeFiles/NombrePremier.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NombrePremier.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/balthazarfrolin/Documents/INSA/Repositories/C:C++/NombrePremier/main.cpp > CMakeFiles/NombrePremier.dir/main.cpp.i

CMakeFiles/NombrePremier.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NombrePremier.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/balthazarfrolin/Documents/INSA/Repositories/C:C++/NombrePremier/main.cpp -o CMakeFiles/NombrePremier.dir/main.cpp.s

# Object files for target NombrePremier
NombrePremier_OBJECTS = \
"CMakeFiles/NombrePremier.dir/main.cpp.o"

# External object files for target NombrePremier
NombrePremier_EXTERNAL_OBJECTS =

NombrePremier: CMakeFiles/NombrePremier.dir/main.cpp.o
NombrePremier: CMakeFiles/NombrePremier.dir/build.make
NombrePremier: CMakeFiles/NombrePremier.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/balthazarfrolin/Documents/INSA/Repositories/C:C++/NombrePremier/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NombrePremier"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NombrePremier.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NombrePremier.dir/build: NombrePremier

.PHONY : CMakeFiles/NombrePremier.dir/build

CMakeFiles/NombrePremier.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NombrePremier.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NombrePremier.dir/clean

CMakeFiles/NombrePremier.dir/depend:
	cd /Users/balthazarfrolin/Documents/INSA/Repositories/C:C++/NombrePremier/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/balthazarfrolin/Documents/INSA/Repositories/C:C++/NombrePremier /Users/balthazarfrolin/Documents/INSA/Repositories/C:C++/NombrePremier /Users/balthazarfrolin/Documents/INSA/Repositories/C:C++/NombrePremier/cmake-build-debug /Users/balthazarfrolin/Documents/INSA/Repositories/C:C++/NombrePremier/cmake-build-debug /Users/balthazarfrolin/Documents/INSA/Repositories/C:C++/NombrePremier/cmake-build-debug/CMakeFiles/NombrePremier.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NombrePremier.dir/depend

