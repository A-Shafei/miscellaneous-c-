# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aes/CLionProjects/InheritanceTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aes/CLionProjects/InheritanceTest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/InheritanceTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/InheritanceTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/InheritanceTest.dir/flags.make

CMakeFiles/InheritanceTest.dir/main.cpp.o: CMakeFiles/InheritanceTest.dir/flags.make
CMakeFiles/InheritanceTest.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aes/CLionProjects/InheritanceTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/InheritanceTest.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/InheritanceTest.dir/main.cpp.o -c /home/aes/CLionProjects/InheritanceTest/main.cpp

CMakeFiles/InheritanceTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/InheritanceTest.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aes/CLionProjects/InheritanceTest/main.cpp > CMakeFiles/InheritanceTest.dir/main.cpp.i

CMakeFiles/InheritanceTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/InheritanceTest.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aes/CLionProjects/InheritanceTest/main.cpp -o CMakeFiles/InheritanceTest.dir/main.cpp.s

CMakeFiles/InheritanceTest.dir/InheritanceFunk.cpp.o: CMakeFiles/InheritanceTest.dir/flags.make
CMakeFiles/InheritanceTest.dir/InheritanceFunk.cpp.o: ../InheritanceFunk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aes/CLionProjects/InheritanceTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/InheritanceTest.dir/InheritanceFunk.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/InheritanceTest.dir/InheritanceFunk.cpp.o -c /home/aes/CLionProjects/InheritanceTest/InheritanceFunk.cpp

CMakeFiles/InheritanceTest.dir/InheritanceFunk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/InheritanceTest.dir/InheritanceFunk.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aes/CLionProjects/InheritanceTest/InheritanceFunk.cpp > CMakeFiles/InheritanceTest.dir/InheritanceFunk.cpp.i

CMakeFiles/InheritanceTest.dir/InheritanceFunk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/InheritanceTest.dir/InheritanceFunk.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aes/CLionProjects/InheritanceTest/InheritanceFunk.cpp -o CMakeFiles/InheritanceTest.dir/InheritanceFunk.cpp.s

# Object files for target InheritanceTest
InheritanceTest_OBJECTS = \
"CMakeFiles/InheritanceTest.dir/main.cpp.o" \
"CMakeFiles/InheritanceTest.dir/InheritanceFunk.cpp.o"

# External object files for target InheritanceTest
InheritanceTest_EXTERNAL_OBJECTS =

InheritanceTest: CMakeFiles/InheritanceTest.dir/main.cpp.o
InheritanceTest: CMakeFiles/InheritanceTest.dir/InheritanceFunk.cpp.o
InheritanceTest: CMakeFiles/InheritanceTest.dir/build.make
InheritanceTest: CMakeFiles/InheritanceTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aes/CLionProjects/InheritanceTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable InheritanceTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/InheritanceTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/InheritanceTest.dir/build: InheritanceTest

.PHONY : CMakeFiles/InheritanceTest.dir/build

CMakeFiles/InheritanceTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/InheritanceTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/InheritanceTest.dir/clean

CMakeFiles/InheritanceTest.dir/depend:
	cd /home/aes/CLionProjects/InheritanceTest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aes/CLionProjects/InheritanceTest /home/aes/CLionProjects/InheritanceTest /home/aes/CLionProjects/InheritanceTest/cmake-build-debug /home/aes/CLionProjects/InheritanceTest/cmake-build-debug /home/aes/CLionProjects/InheritanceTest/cmake-build-debug/CMakeFiles/InheritanceTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/InheritanceTest.dir/depend

