# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zirer/zirerfile/fileC++/testMongo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zirer/zirerfile/fileC++/testMongo/build

# Include any dependencies generated for this target.
include CMakeFiles/testMongo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/testMongo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/testMongo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testMongo.dir/flags.make

CMakeFiles/testMongo.dir/main.cpp.o: CMakeFiles/testMongo.dir/flags.make
CMakeFiles/testMongo.dir/main.cpp.o: /home/zirer/zirerfile/fileC++/testMongo/main.cpp
CMakeFiles/testMongo.dir/main.cpp.o: CMakeFiles/testMongo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zirer/zirerfile/fileC++/testMongo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testMongo.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testMongo.dir/main.cpp.o -MF CMakeFiles/testMongo.dir/main.cpp.o.d -o CMakeFiles/testMongo.dir/main.cpp.o -c /home/zirer/zirerfile/fileC++/testMongo/main.cpp

CMakeFiles/testMongo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testMongo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zirer/zirerfile/fileC++/testMongo/main.cpp > CMakeFiles/testMongo.dir/main.cpp.i

CMakeFiles/testMongo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testMongo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zirer/zirerfile/fileC++/testMongo/main.cpp -o CMakeFiles/testMongo.dir/main.cpp.s

CMakeFiles/testMongo.dir/timer.cpp.o: CMakeFiles/testMongo.dir/flags.make
CMakeFiles/testMongo.dir/timer.cpp.o: /home/zirer/zirerfile/fileC++/testMongo/timer.cpp
CMakeFiles/testMongo.dir/timer.cpp.o: CMakeFiles/testMongo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zirer/zirerfile/fileC++/testMongo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testMongo.dir/timer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testMongo.dir/timer.cpp.o -MF CMakeFiles/testMongo.dir/timer.cpp.o.d -o CMakeFiles/testMongo.dir/timer.cpp.o -c /home/zirer/zirerfile/fileC++/testMongo/timer.cpp

CMakeFiles/testMongo.dir/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testMongo.dir/timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zirer/zirerfile/fileC++/testMongo/timer.cpp > CMakeFiles/testMongo.dir/timer.cpp.i

CMakeFiles/testMongo.dir/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testMongo.dir/timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zirer/zirerfile/fileC++/testMongo/timer.cpp -o CMakeFiles/testMongo.dir/timer.cpp.s

# Object files for target testMongo
testMongo_OBJECTS = \
"CMakeFiles/testMongo.dir/main.cpp.o" \
"CMakeFiles/testMongo.dir/timer.cpp.o"

# External object files for target testMongo
testMongo_EXTERNAL_OBJECTS =

testMongo: CMakeFiles/testMongo.dir/main.cpp.o
testMongo: CMakeFiles/testMongo.dir/timer.cpp.o
testMongo: CMakeFiles/testMongo.dir/build.make
testMongo: /usr/local/lib/libbcrypt.a
testMongo: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.83.0
testMongo: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.83.0
testMongo: /usr/local/lib/libbcrypt.a
testMongo: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.83.0
testMongo: CMakeFiles/testMongo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/zirer/zirerfile/fileC++/testMongo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable testMongo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testMongo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testMongo.dir/build: testMongo
.PHONY : CMakeFiles/testMongo.dir/build

CMakeFiles/testMongo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testMongo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testMongo.dir/clean

CMakeFiles/testMongo.dir/depend:
	cd /home/zirer/zirerfile/fileC++/testMongo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zirer/zirerfile/fileC++/testMongo /home/zirer/zirerfile/fileC++/testMongo /home/zirer/zirerfile/fileC++/testMongo/build /home/zirer/zirerfile/fileC++/testMongo/build /home/zirer/zirerfile/fileC++/testMongo/build/CMakeFiles/testMongo.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/testMongo.dir/depend

