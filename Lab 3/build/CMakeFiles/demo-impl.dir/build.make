# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3/build"

# Include any dependencies generated for this target.
include CMakeFiles/demo-impl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/demo-impl.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/demo-impl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo-impl.dir/flags.make

CMakeFiles/demo-impl.dir/demo.c.o: CMakeFiles/demo-impl.dir/flags.make
CMakeFiles/demo-impl.dir/demo.c.o: /Users/isaiah/Desktop/Career/Fall\ 2023/ELEC\ 278/Week\ 3/lab3/demo.c
CMakeFiles/demo-impl.dir/demo.c.o: CMakeFiles/demo-impl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/demo-impl.dir/demo.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/demo-impl.dir/demo.c.o -MF CMakeFiles/demo-impl.dir/demo.c.o.d -o CMakeFiles/demo-impl.dir/demo.c.o -c "/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3/demo.c"

CMakeFiles/demo-impl.dir/demo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/demo-impl.dir/demo.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3/demo.c" > CMakeFiles/demo-impl.dir/demo.c.i

CMakeFiles/demo-impl.dir/demo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/demo-impl.dir/demo.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3/demo.c" -o CMakeFiles/demo-impl.dir/demo.c.s

CMakeFiles/demo-impl.dir/main.c.o: CMakeFiles/demo-impl.dir/flags.make
CMakeFiles/demo-impl.dir/main.c.o: /Users/isaiah/Desktop/Career/Fall\ 2023/ELEC\ 278/Week\ 3/lab3/main.c
CMakeFiles/demo-impl.dir/main.c.o: CMakeFiles/demo-impl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/demo-impl.dir/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/demo-impl.dir/main.c.o -MF CMakeFiles/demo-impl.dir/main.c.o.d -o CMakeFiles/demo-impl.dir/main.c.o -c "/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3/main.c"

CMakeFiles/demo-impl.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/demo-impl.dir/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3/main.c" > CMakeFiles/demo-impl.dir/main.c.i

CMakeFiles/demo-impl.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/demo-impl.dir/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3/main.c" -o CMakeFiles/demo-impl.dir/main.c.s

demo-impl: CMakeFiles/demo-impl.dir/demo.c.o
demo-impl: CMakeFiles/demo-impl.dir/main.c.o
demo-impl: CMakeFiles/demo-impl.dir/build.make
.PHONY : demo-impl

# Rule to build all files generated by this target.
CMakeFiles/demo-impl.dir/build: demo-impl
.PHONY : CMakeFiles/demo-impl.dir/build

CMakeFiles/demo-impl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo-impl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo-impl.dir/clean

CMakeFiles/demo-impl.dir/depend:
	cd "/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3" "/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3" "/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3/build" "/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3/build" "/Users/isaiah/Desktop/Career/Fall 2023/ELEC 278/Week 3/lab3/build/CMakeFiles/demo-impl.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/demo-impl.dir/depend

