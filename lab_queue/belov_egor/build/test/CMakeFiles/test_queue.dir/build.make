# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build

# Include any dependencies generated for this target.
include test/CMakeFiles/test_queue.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/test_queue.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_queue.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_queue.dir/flags.make

test/CMakeFiles/test_queue.dir/test_main.cpp.o: test/CMakeFiles/test_queue.dir/flags.make
test/CMakeFiles/test_queue.dir/test_main.cpp.o: /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_main.cpp
test/CMakeFiles/test_queue.dir/test_main.cpp.o: test/CMakeFiles/test_queue.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_queue.dir/test_main.cpp.o"
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test_queue.dir/test_main.cpp.o -MF CMakeFiles/test_queue.dir/test_main.cpp.o.d -o CMakeFiles/test_queue.dir/test_main.cpp.o -c /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_main.cpp

test/CMakeFiles/test_queue.dir/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_queue.dir/test_main.cpp.i"
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_main.cpp > CMakeFiles/test_queue.dir/test_main.cpp.i

test/CMakeFiles/test_queue.dir/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_queue.dir/test_main.cpp.s"
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_main.cpp -o CMakeFiles/test_queue.dir/test_main.cpp.s

test/CMakeFiles/test_queue.dir/test_queuecycle.cpp.o: test/CMakeFiles/test_queue.dir/flags.make
test/CMakeFiles/test_queue.dir/test_queuecycle.cpp.o: /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_queuecycle.cpp
test/CMakeFiles/test_queue.dir/test_queuecycle.cpp.o: test/CMakeFiles/test_queue.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/test_queue.dir/test_queuecycle.cpp.o"
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test_queue.dir/test_queuecycle.cpp.o -MF CMakeFiles/test_queue.dir/test_queuecycle.cpp.o.d -o CMakeFiles/test_queue.dir/test_queuecycle.cpp.o -c /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_queuecycle.cpp

test/CMakeFiles/test_queue.dir/test_queuecycle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_queue.dir/test_queuecycle.cpp.i"
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_queuecycle.cpp > CMakeFiles/test_queue.dir/test_queuecycle.cpp.i

test/CMakeFiles/test_queue.dir/test_queuecycle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_queue.dir/test_queuecycle.cpp.s"
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_queuecycle.cpp -o CMakeFiles/test_queue.dir/test_queuecycle.cpp.s

test/CMakeFiles/test_queue.dir/test_queuepriority.cpp.o: test/CMakeFiles/test_queue.dir/flags.make
test/CMakeFiles/test_queue.dir/test_queuepriority.cpp.o: /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_queuepriority.cpp
test/CMakeFiles/test_queue.dir/test_queuepriority.cpp.o: test/CMakeFiles/test_queue.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/test_queue.dir/test_queuepriority.cpp.o"
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test_queue.dir/test_queuepriority.cpp.o -MF CMakeFiles/test_queue.dir/test_queuepriority.cpp.o.d -o CMakeFiles/test_queue.dir/test_queuepriority.cpp.o -c /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_queuepriority.cpp

test/CMakeFiles/test_queue.dir/test_queuepriority.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_queue.dir/test_queuepriority.cpp.i"
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_queuepriority.cpp > CMakeFiles/test_queue.dir/test_queuepriority.cpp.i

test/CMakeFiles/test_queue.dir/test_queuepriority.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_queue.dir/test_queuepriority.cpp.s"
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_queuepriority.cpp -o CMakeFiles/test_queue.dir/test_queuepriority.cpp.s

test/CMakeFiles/test_queue.dir/test_queuestack.cpp.o: test/CMakeFiles/test_queue.dir/flags.make
test/CMakeFiles/test_queue.dir/test_queuestack.cpp.o: /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_queuestack.cpp
test/CMakeFiles/test_queue.dir/test_queuestack.cpp.o: test/CMakeFiles/test_queue.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/CMakeFiles/test_queue.dir/test_queuestack.cpp.o"
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test_queue.dir/test_queuestack.cpp.o -MF CMakeFiles/test_queue.dir/test_queuestack.cpp.o.d -o CMakeFiles/test_queue.dir/test_queuestack.cpp.o -c /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_queuestack.cpp

test/CMakeFiles/test_queue.dir/test_queuestack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_queue.dir/test_queuestack.cpp.i"
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_queuestack.cpp > CMakeFiles/test_queue.dir/test_queuestack.cpp.i

test/CMakeFiles/test_queue.dir/test_queuestack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_queue.dir/test_queuestack.cpp.s"
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test/test_queuestack.cpp -o CMakeFiles/test_queue.dir/test_queuestack.cpp.s

# Object files for target test_queue
test_queue_OBJECTS = \
"CMakeFiles/test_queue.dir/test_main.cpp.o" \
"CMakeFiles/test_queue.dir/test_queuecycle.cpp.o" \
"CMakeFiles/test_queue.dir/test_queuepriority.cpp.o" \
"CMakeFiles/test_queue.dir/test_queuestack.cpp.o"

# External object files for target test_queue
test_queue_EXTERNAL_OBJECTS =

bin/test_queue: test/CMakeFiles/test_queue.dir/test_main.cpp.o
bin/test_queue: test/CMakeFiles/test_queue.dir/test_queuecycle.cpp.o
bin/test_queue: test/CMakeFiles/test_queue.dir/test_queuepriority.cpp.o
bin/test_queue: test/CMakeFiles/test_queue.dir/test_queuestack.cpp.o
bin/test_queue: test/CMakeFiles/test_queue.dir/build.make
bin/test_queue: lib/libgtest.a
bin/test_queue: lib/libqueue.a
bin/test_queue: test/CMakeFiles/test_queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../bin/test_queue"
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_queue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_queue.dir/build: bin/test_queue
.PHONY : test/CMakeFiles/test_queue.dir/build

test/CMakeFiles/test_queue.dir/clean:
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test && $(CMAKE_COMMAND) -P CMakeFiles/test_queue.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_queue.dir/clean

test/CMakeFiles/test_queue.dir/depend:
	cd /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/test /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test /Users/belovegor/Documents/belov_egor/lab_queue/belov_egor/build/test/CMakeFiles/test_queue.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/test_queue.dir/depend

