# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\libs\glfw-3.3.9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\libs\glfw-3.3.9\build

# Include any dependencies generated for this target.
include examples/CMakeFiles/offscreen.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/offscreen.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/offscreen.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/offscreen.dir/flags.make

examples/CMakeFiles/offscreen.dir/offscreen.c.obj: examples/CMakeFiles/offscreen.dir/flags.make
examples/CMakeFiles/offscreen.dir/offscreen.c.obj: examples/CMakeFiles/offscreen.dir/includes_C.rsp
examples/CMakeFiles/offscreen.dir/offscreen.c.obj: F:/libs/glfw-3.3.9/examples/offscreen.c
examples/CMakeFiles/offscreen.dir/offscreen.c.obj: examples/CMakeFiles/offscreen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\libs\glfw-3.3.9\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/offscreen.dir/offscreen.c.obj"
	cd /d F:\libs\glfw-3.3.9\build\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/offscreen.dir/offscreen.c.obj -MF CMakeFiles\offscreen.dir\offscreen.c.obj.d -o CMakeFiles\offscreen.dir\offscreen.c.obj -c F:\libs\glfw-3.3.9\examples\offscreen.c

examples/CMakeFiles/offscreen.dir/offscreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/offscreen.dir/offscreen.c.i"
	cd /d F:\libs\glfw-3.3.9\build\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\libs\glfw-3.3.9\examples\offscreen.c > CMakeFiles\offscreen.dir\offscreen.c.i

examples/CMakeFiles/offscreen.dir/offscreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/offscreen.dir/offscreen.c.s"
	cd /d F:\libs\glfw-3.3.9\build\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\libs\glfw-3.3.9\examples\offscreen.c -o CMakeFiles\offscreen.dir\offscreen.c.s

examples/CMakeFiles/offscreen.dir/glfw.rc.obj: examples/CMakeFiles/offscreen.dir/flags.make
examples/CMakeFiles/offscreen.dir/glfw.rc.obj: F:/libs/glfw-3.3.9/examples/glfw.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\libs\glfw-3.3.9\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object examples/CMakeFiles/offscreen.dir/glfw.rc.obj"
	cd /d F:\libs\glfw-3.3.9\build\examples && C:\MinGW\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) F:\libs\glfw-3.3.9\examples\glfw.rc CMakeFiles\offscreen.dir\glfw.rc.obj

examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj: examples/CMakeFiles/offscreen.dir/flags.make
examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj: examples/CMakeFiles/offscreen.dir/includes_C.rsp
examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj: F:/libs/glfw-3.3.9/deps/glad_gl.c
examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj: examples/CMakeFiles/offscreen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\libs\glfw-3.3.9\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj"
	cd /d F:\libs\glfw-3.3.9\build\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj -MF CMakeFiles\offscreen.dir\__\deps\glad_gl.c.obj.d -o CMakeFiles\offscreen.dir\__\deps\glad_gl.c.obj -c F:\libs\glfw-3.3.9\deps\glad_gl.c

examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i"
	cd /d F:\libs\glfw-3.3.9\build\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\libs\glfw-3.3.9\deps\glad_gl.c > CMakeFiles\offscreen.dir\__\deps\glad_gl.c.i

examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s"
	cd /d F:\libs\glfw-3.3.9\build\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\libs\glfw-3.3.9\deps\glad_gl.c -o CMakeFiles\offscreen.dir\__\deps\glad_gl.c.s

# Object files for target offscreen
offscreen_OBJECTS = \
"CMakeFiles/offscreen.dir/offscreen.c.obj" \
"CMakeFiles/offscreen.dir/glfw.rc.obj" \
"CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj"

# External object files for target offscreen
offscreen_EXTERNAL_OBJECTS =

examples/offscreen.exe: examples/CMakeFiles/offscreen.dir/offscreen.c.obj
examples/offscreen.exe: examples/CMakeFiles/offscreen.dir/glfw.rc.obj
examples/offscreen.exe: examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj
examples/offscreen.exe: examples/CMakeFiles/offscreen.dir/build.make
examples/offscreen.exe: src/libglfw3.a
examples/offscreen.exe: examples/CMakeFiles/offscreen.dir/linkLibs.rsp
examples/offscreen.exe: examples/CMakeFiles/offscreen.dir/objects1.rsp
examples/offscreen.exe: examples/CMakeFiles/offscreen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=F:\libs\glfw-3.3.9\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable offscreen.exe"
	cd /d F:\libs\glfw-3.3.9\build\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\offscreen.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/offscreen.dir/build: examples/offscreen.exe
.PHONY : examples/CMakeFiles/offscreen.dir/build

examples/CMakeFiles/offscreen.dir/clean:
	cd /d F:\libs\glfw-3.3.9\build\examples && $(CMAKE_COMMAND) -P CMakeFiles\offscreen.dir\cmake_clean.cmake
.PHONY : examples/CMakeFiles/offscreen.dir/clean

examples/CMakeFiles/offscreen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\libs\glfw-3.3.9 F:\libs\glfw-3.3.9\examples F:\libs\glfw-3.3.9\build F:\libs\glfw-3.3.9\build\examples F:\libs\glfw-3.3.9\build\examples\CMakeFiles\offscreen.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : examples/CMakeFiles/offscreen.dir/depend

