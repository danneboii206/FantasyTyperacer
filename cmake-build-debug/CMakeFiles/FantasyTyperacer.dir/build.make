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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/daab24/FantasyTyperacer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/daab24/FantasyTyperacer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FantasyTyperacer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FantasyTyperacer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FantasyTyperacer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FantasyTyperacer.dir/flags.make

CMakeFiles/FantasyTyperacer.dir/main.cpp.o: CMakeFiles/FantasyTyperacer.dir/flags.make
CMakeFiles/FantasyTyperacer.dir/main.cpp.o: /Users/daab24/FantasyTyperacer/main.cpp
CMakeFiles/FantasyTyperacer.dir/main.cpp.o: CMakeFiles/FantasyTyperacer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/daab24/FantasyTyperacer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FantasyTyperacer.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FantasyTyperacer.dir/main.cpp.o -MF CMakeFiles/FantasyTyperacer.dir/main.cpp.o.d -o CMakeFiles/FantasyTyperacer.dir/main.cpp.o -c /Users/daab24/FantasyTyperacer/main.cpp

CMakeFiles/FantasyTyperacer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FantasyTyperacer.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/daab24/FantasyTyperacer/main.cpp > CMakeFiles/FantasyTyperacer.dir/main.cpp.i

CMakeFiles/FantasyTyperacer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FantasyTyperacer.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/daab24/FantasyTyperacer/main.cpp -o CMakeFiles/FantasyTyperacer.dir/main.cpp.s

CMakeFiles/FantasyTyperacer.dir/combat.cpp.o: CMakeFiles/FantasyTyperacer.dir/flags.make
CMakeFiles/FantasyTyperacer.dir/combat.cpp.o: /Users/daab24/FantasyTyperacer/combat.cpp
CMakeFiles/FantasyTyperacer.dir/combat.cpp.o: CMakeFiles/FantasyTyperacer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/daab24/FantasyTyperacer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FantasyTyperacer.dir/combat.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FantasyTyperacer.dir/combat.cpp.o -MF CMakeFiles/FantasyTyperacer.dir/combat.cpp.o.d -o CMakeFiles/FantasyTyperacer.dir/combat.cpp.o -c /Users/daab24/FantasyTyperacer/combat.cpp

CMakeFiles/FantasyTyperacer.dir/combat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FantasyTyperacer.dir/combat.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/daab24/FantasyTyperacer/combat.cpp > CMakeFiles/FantasyTyperacer.dir/combat.cpp.i

CMakeFiles/FantasyTyperacer.dir/combat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FantasyTyperacer.dir/combat.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/daab24/FantasyTyperacer/combat.cpp -o CMakeFiles/FantasyTyperacer.dir/combat.cpp.s

CMakeFiles/FantasyTyperacer.dir/menus.cpp.o: CMakeFiles/FantasyTyperacer.dir/flags.make
CMakeFiles/FantasyTyperacer.dir/menus.cpp.o: /Users/daab24/FantasyTyperacer/menus.cpp
CMakeFiles/FantasyTyperacer.dir/menus.cpp.o: CMakeFiles/FantasyTyperacer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/daab24/FantasyTyperacer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FantasyTyperacer.dir/menus.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FantasyTyperacer.dir/menus.cpp.o -MF CMakeFiles/FantasyTyperacer.dir/menus.cpp.o.d -o CMakeFiles/FantasyTyperacer.dir/menus.cpp.o -c /Users/daab24/FantasyTyperacer/menus.cpp

CMakeFiles/FantasyTyperacer.dir/menus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FantasyTyperacer.dir/menus.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/daab24/FantasyTyperacer/menus.cpp > CMakeFiles/FantasyTyperacer.dir/menus.cpp.i

CMakeFiles/FantasyTyperacer.dir/menus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FantasyTyperacer.dir/menus.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/daab24/FantasyTyperacer/menus.cpp -o CMakeFiles/FantasyTyperacer.dir/menus.cpp.s

CMakeFiles/FantasyTyperacer.dir/rooms.cpp.o: CMakeFiles/FantasyTyperacer.dir/flags.make
CMakeFiles/FantasyTyperacer.dir/rooms.cpp.o: /Users/daab24/FantasyTyperacer/rooms.cpp
CMakeFiles/FantasyTyperacer.dir/rooms.cpp.o: CMakeFiles/FantasyTyperacer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/daab24/FantasyTyperacer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/FantasyTyperacer.dir/rooms.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FantasyTyperacer.dir/rooms.cpp.o -MF CMakeFiles/FantasyTyperacer.dir/rooms.cpp.o.d -o CMakeFiles/FantasyTyperacer.dir/rooms.cpp.o -c /Users/daab24/FantasyTyperacer/rooms.cpp

CMakeFiles/FantasyTyperacer.dir/rooms.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FantasyTyperacer.dir/rooms.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/daab24/FantasyTyperacer/rooms.cpp > CMakeFiles/FantasyTyperacer.dir/rooms.cpp.i

CMakeFiles/FantasyTyperacer.dir/rooms.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FantasyTyperacer.dir/rooms.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/daab24/FantasyTyperacer/rooms.cpp -o CMakeFiles/FantasyTyperacer.dir/rooms.cpp.s

# Object files for target FantasyTyperacer
FantasyTyperacer_OBJECTS = \
"CMakeFiles/FantasyTyperacer.dir/main.cpp.o" \
"CMakeFiles/FantasyTyperacer.dir/combat.cpp.o" \
"CMakeFiles/FantasyTyperacer.dir/menus.cpp.o" \
"CMakeFiles/FantasyTyperacer.dir/rooms.cpp.o"

# External object files for target FantasyTyperacer
FantasyTyperacer_EXTERNAL_OBJECTS =

FantasyTyperacer: CMakeFiles/FantasyTyperacer.dir/main.cpp.o
FantasyTyperacer: CMakeFiles/FantasyTyperacer.dir/combat.cpp.o
FantasyTyperacer: CMakeFiles/FantasyTyperacer.dir/menus.cpp.o
FantasyTyperacer: CMakeFiles/FantasyTyperacer.dir/rooms.cpp.o
FantasyTyperacer: CMakeFiles/FantasyTyperacer.dir/build.make
FantasyTyperacer: CMakeFiles/FantasyTyperacer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/daab24/FantasyTyperacer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable FantasyTyperacer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FantasyTyperacer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FantasyTyperacer.dir/build: FantasyTyperacer
.PHONY : CMakeFiles/FantasyTyperacer.dir/build

CMakeFiles/FantasyTyperacer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FantasyTyperacer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FantasyTyperacer.dir/clean

CMakeFiles/FantasyTyperacer.dir/depend:
	cd /Users/daab24/FantasyTyperacer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/daab24/FantasyTyperacer /Users/daab24/FantasyTyperacer /Users/daab24/FantasyTyperacer/cmake-build-debug /Users/daab24/FantasyTyperacer/cmake-build-debug /Users/daab24/FantasyTyperacer/cmake-build-debug/CMakeFiles/FantasyTyperacer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/FantasyTyperacer.dir/depend

