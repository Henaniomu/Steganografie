# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /mnt/c/Users/oleh1/Desktop/PC/Semestralka

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/oleh1/Desktop/PC/Semestralka/build

# Include any dependencies generated for this target.
include CMakeFiles/stegim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/stegim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/stegim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stegim.dir/flags.make

CMakeFiles/stegim.dir/src/main.c.o: CMakeFiles/stegim.dir/flags.make
CMakeFiles/stegim.dir/src/main.c.o: /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/main.c
CMakeFiles/stegim.dir/src/main.c.o: CMakeFiles/stegim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/oleh1/Desktop/PC/Semestralka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/stegim.dir/src/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/stegim.dir/src/main.c.o -MF CMakeFiles/stegim.dir/src/main.c.o.d -o CMakeFiles/stegim.dir/src/main.c.o -c /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/main.c

CMakeFiles/stegim.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stegim.dir/src/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/main.c > CMakeFiles/stegim.dir/src/main.c.i

CMakeFiles/stegim.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stegim.dir/src/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/main.c -o CMakeFiles/stegim.dir/src/main.c.s

CMakeFiles/stegim.dir/src/bmp.c.o: CMakeFiles/stegim.dir/flags.make
CMakeFiles/stegim.dir/src/bmp.c.o: /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/bmp.c
CMakeFiles/stegim.dir/src/bmp.c.o: CMakeFiles/stegim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/oleh1/Desktop/PC/Semestralka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/stegim.dir/src/bmp.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/stegim.dir/src/bmp.c.o -MF CMakeFiles/stegim.dir/src/bmp.c.o.d -o CMakeFiles/stegim.dir/src/bmp.c.o -c /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/bmp.c

CMakeFiles/stegim.dir/src/bmp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stegim.dir/src/bmp.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/bmp.c > CMakeFiles/stegim.dir/src/bmp.c.i

CMakeFiles/stegim.dir/src/bmp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stegim.dir/src/bmp.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/bmp.c -o CMakeFiles/stegim.dir/src/bmp.c.s

CMakeFiles/stegim.dir/src/lzw.c.o: CMakeFiles/stegim.dir/flags.make
CMakeFiles/stegim.dir/src/lzw.c.o: /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/lzw.c
CMakeFiles/stegim.dir/src/lzw.c.o: CMakeFiles/stegim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/oleh1/Desktop/PC/Semestralka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/stegim.dir/src/lzw.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/stegim.dir/src/lzw.c.o -MF CMakeFiles/stegim.dir/src/lzw.c.o.d -o CMakeFiles/stegim.dir/src/lzw.c.o -c /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/lzw.c

CMakeFiles/stegim.dir/src/lzw.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stegim.dir/src/lzw.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/lzw.c > CMakeFiles/stegim.dir/src/lzw.c.i

CMakeFiles/stegim.dir/src/lzw.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stegim.dir/src/lzw.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/lzw.c -o CMakeFiles/stegim.dir/src/lzw.c.s

CMakeFiles/stegim.dir/src/coder.c.o: CMakeFiles/stegim.dir/flags.make
CMakeFiles/stegim.dir/src/coder.c.o: /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/coder.c
CMakeFiles/stegim.dir/src/coder.c.o: CMakeFiles/stegim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/oleh1/Desktop/PC/Semestralka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/stegim.dir/src/coder.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/stegim.dir/src/coder.c.o -MF CMakeFiles/stegim.dir/src/coder.c.o.d -o CMakeFiles/stegim.dir/src/coder.c.o -c /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/coder.c

CMakeFiles/stegim.dir/src/coder.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stegim.dir/src/coder.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/coder.c > CMakeFiles/stegim.dir/src/coder.c.i

CMakeFiles/stegim.dir/src/coder.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stegim.dir/src/coder.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/coder.c -o CMakeFiles/stegim.dir/src/coder.c.s

CMakeFiles/stegim.dir/src/png_process.c.o: CMakeFiles/stegim.dir/flags.make
CMakeFiles/stegim.dir/src/png_process.c.o: /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/png_process.c
CMakeFiles/stegim.dir/src/png_process.c.o: CMakeFiles/stegim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/oleh1/Desktop/PC/Semestralka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/stegim.dir/src/png_process.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/stegim.dir/src/png_process.c.o -MF CMakeFiles/stegim.dir/src/png_process.c.o.d -o CMakeFiles/stegim.dir/src/png_process.c.o -c /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/png_process.c

CMakeFiles/stegim.dir/src/png_process.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stegim.dir/src/png_process.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/png_process.c > CMakeFiles/stegim.dir/src/png_process.c.i

CMakeFiles/stegim.dir/src/png_process.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stegim.dir/src/png_process.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/oleh1/Desktop/PC/Semestralka/src/png_process.c -o CMakeFiles/stegim.dir/src/png_process.c.s

# Object files for target stegim
stegim_OBJECTS = \
"CMakeFiles/stegim.dir/src/main.c.o" \
"CMakeFiles/stegim.dir/src/bmp.c.o" \
"CMakeFiles/stegim.dir/src/lzw.c.o" \
"CMakeFiles/stegim.dir/src/coder.c.o" \
"CMakeFiles/stegim.dir/src/png_process.c.o"

# External object files for target stegim
stegim_EXTERNAL_OBJECTS =

stegim: CMakeFiles/stegim.dir/src/main.c.o
stegim: CMakeFiles/stegim.dir/src/bmp.c.o
stegim: CMakeFiles/stegim.dir/src/lzw.c.o
stegim: CMakeFiles/stegim.dir/src/coder.c.o
stegim: CMakeFiles/stegim.dir/src/png_process.c.o
stegim: CMakeFiles/stegim.dir/build.make
stegim: /usr/lib/x86_64-linux-gnu/libpng.so
stegim: /usr/local/lib/libz.so
stegim: CMakeFiles/stegim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/oleh1/Desktop/PC/Semestralka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable stegim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stegim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stegim.dir/build: stegim
.PHONY : CMakeFiles/stegim.dir/build

CMakeFiles/stegim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stegim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stegim.dir/clean

CMakeFiles/stegim.dir/depend:
	cd /mnt/c/Users/oleh1/Desktop/PC/Semestralka/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/oleh1/Desktop/PC/Semestralka /mnt/c/Users/oleh1/Desktop/PC/Semestralka /mnt/c/Users/oleh1/Desktop/PC/Semestralka/build /mnt/c/Users/oleh1/Desktop/PC/Semestralka/build /mnt/c/Users/oleh1/Desktop/PC/Semestralka/build/CMakeFiles/stegim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stegim.dir/depend

