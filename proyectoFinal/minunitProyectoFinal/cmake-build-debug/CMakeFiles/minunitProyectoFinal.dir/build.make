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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\grego\CLionProjects\proyectoFinal\minunitProyectoFinal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\grego\CLionProjects\proyectoFinal\minunitProyectoFinal\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/minunitProyectoFinal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minunitProyectoFinal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minunitProyectoFinal.dir/flags.make

CMakeFiles/minunitProyectoFinal.dir/main.c.obj: CMakeFiles/minunitProyectoFinal.dir/flags.make
CMakeFiles/minunitProyectoFinal.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\grego\CLionProjects\proyectoFinal\minunitProyectoFinal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/minunitProyectoFinal.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\minunitProyectoFinal.dir\main.c.obj   -c C:\Users\grego\CLionProjects\proyectoFinal\minunitProyectoFinal\main.c

CMakeFiles/minunitProyectoFinal.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minunitProyectoFinal.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\grego\CLionProjects\proyectoFinal\minunitProyectoFinal\main.c > CMakeFiles\minunitProyectoFinal.dir\main.c.i

CMakeFiles/minunitProyectoFinal.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minunitProyectoFinal.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\grego\CLionProjects\proyectoFinal\minunitProyectoFinal\main.c -o CMakeFiles\minunitProyectoFinal.dir\main.c.s

# Object files for target minunitProyectoFinal
minunitProyectoFinal_OBJECTS = \
"CMakeFiles/minunitProyectoFinal.dir/main.c.obj"

# External object files for target minunitProyectoFinal
minunitProyectoFinal_EXTERNAL_OBJECTS =

minunitProyectoFinal.exe: CMakeFiles/minunitProyectoFinal.dir/main.c.obj
minunitProyectoFinal.exe: CMakeFiles/minunitProyectoFinal.dir/build.make
minunitProyectoFinal.exe: CMakeFiles/minunitProyectoFinal.dir/linklibs.rsp
minunitProyectoFinal.exe: CMakeFiles/minunitProyectoFinal.dir/objects1.rsp
minunitProyectoFinal.exe: CMakeFiles/minunitProyectoFinal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\grego\CLionProjects\proyectoFinal\minunitProyectoFinal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable minunitProyectoFinal.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\minunitProyectoFinal.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minunitProyectoFinal.dir/build: minunitProyectoFinal.exe

.PHONY : CMakeFiles/minunitProyectoFinal.dir/build

CMakeFiles/minunitProyectoFinal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\minunitProyectoFinal.dir\cmake_clean.cmake
.PHONY : CMakeFiles/minunitProyectoFinal.dir/clean

CMakeFiles/minunitProyectoFinal.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\grego\CLionProjects\proyectoFinal\minunitProyectoFinal C:\Users\grego\CLionProjects\proyectoFinal\minunitProyectoFinal C:\Users\grego\CLionProjects\proyectoFinal\minunitProyectoFinal\cmake-build-debug C:\Users\grego\CLionProjects\proyectoFinal\minunitProyectoFinal\cmake-build-debug C:\Users\grego\CLionProjects\proyectoFinal\minunitProyectoFinal\cmake-build-debug\CMakeFiles\minunitProyectoFinal.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minunitProyectoFinal.dir/depend

