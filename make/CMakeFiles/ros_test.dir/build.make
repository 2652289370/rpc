# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/w/code/ros

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/w/code/ros/make

# Include any dependencies generated for this target.
include CMakeFiles/ros_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ros_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ros_test.dir/flags.make

CMakeFiles/ros_test.dir/serialize/src/DataStream.cpp.o: CMakeFiles/ros_test.dir/flags.make
CMakeFiles/ros_test.dir/serialize/src/DataStream.cpp.o: ../serialize/src/DataStream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/w/code/ros/make/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ros_test.dir/serialize/src/DataStream.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ros_test.dir/serialize/src/DataStream.cpp.o -c /home/w/code/ros/serialize/src/DataStream.cpp

CMakeFiles/ros_test.dir/serialize/src/DataStream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ros_test.dir/serialize/src/DataStream.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/w/code/ros/serialize/src/DataStream.cpp > CMakeFiles/ros_test.dir/serialize/src/DataStream.cpp.i

CMakeFiles/ros_test.dir/serialize/src/DataStream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ros_test.dir/serialize/src/DataStream.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/w/code/ros/serialize/src/DataStream.cpp -o CMakeFiles/ros_test.dir/serialize/src/DataStream.cpp.s

CMakeFiles/ros_test.dir/src/main.cpp.o: CMakeFiles/ros_test.dir/flags.make
CMakeFiles/ros_test.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/w/code/ros/make/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ros_test.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ros_test.dir/src/main.cpp.o -c /home/w/code/ros/src/main.cpp

CMakeFiles/ros_test.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ros_test.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/w/code/ros/src/main.cpp > CMakeFiles/ros_test.dir/src/main.cpp.i

CMakeFiles/ros_test.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ros_test.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/w/code/ros/src/main.cpp -o CMakeFiles/ros_test.dir/src/main.cpp.s

# Object files for target ros_test
ros_test_OBJECTS = \
"CMakeFiles/ros_test.dir/serialize/src/DataStream.cpp.o" \
"CMakeFiles/ros_test.dir/src/main.cpp.o"

# External object files for target ros_test
ros_test_EXTERNAL_OBJECTS =

../bin/ros_test: CMakeFiles/ros_test.dir/serialize/src/DataStream.cpp.o
../bin/ros_test: CMakeFiles/ros_test.dir/src/main.cpp.o
../bin/ros_test: CMakeFiles/ros_test.dir/build.make
../bin/ros_test: CMakeFiles/ros_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/w/code/ros/make/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/ros_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ros_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ros_test.dir/build: ../bin/ros_test

.PHONY : CMakeFiles/ros_test.dir/build

CMakeFiles/ros_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ros_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ros_test.dir/clean

CMakeFiles/ros_test.dir/depend:
	cd /home/w/code/ros/make && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/w/code/ros /home/w/code/ros /home/w/code/ros/make /home/w/code/ros/make /home/w/code/ros/make/CMakeFiles/ros_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ros_test.dir/depend

