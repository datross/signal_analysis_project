# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_SOURCE_DIR = /home/6im3/mcrespin/Documents/Signal/signal_analysis_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/build

# Include any dependencies generated for this target.
include CMakeFiles/proj_exec.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proj_exec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj_exec.dir/flags.make

CMakeFiles/proj_exec.dir/src/buffer.cpp.o: CMakeFiles/proj_exec.dir/flags.make
CMakeFiles/proj_exec.dir/src/buffer.cpp.o: ../src/buffer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/proj_exec.dir/src/buffer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/proj_exec.dir/src/buffer.cpp.o -c /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/src/buffer.cpp

CMakeFiles/proj_exec.dir/src/buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj_exec.dir/src/buffer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/src/buffer.cpp > CMakeFiles/proj_exec.dir/src/buffer.cpp.i

CMakeFiles/proj_exec.dir/src/buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj_exec.dir/src/buffer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/src/buffer.cpp -o CMakeFiles/proj_exec.dir/src/buffer.cpp.s

CMakeFiles/proj_exec.dir/src/buffer.cpp.o.requires:
.PHONY : CMakeFiles/proj_exec.dir/src/buffer.cpp.o.requires

CMakeFiles/proj_exec.dir/src/buffer.cpp.o.provides: CMakeFiles/proj_exec.dir/src/buffer.cpp.o.requires
	$(MAKE) -f CMakeFiles/proj_exec.dir/build.make CMakeFiles/proj_exec.dir/src/buffer.cpp.o.provides.build
.PHONY : CMakeFiles/proj_exec.dir/src/buffer.cpp.o.provides

CMakeFiles/proj_exec.dir/src/buffer.cpp.o.provides.build: CMakeFiles/proj_exec.dir/src/buffer.cpp.o

CMakeFiles/proj_exec.dir/src/main.cpp.o: CMakeFiles/proj_exec.dir/flags.make
CMakeFiles/proj_exec.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/proj_exec.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/proj_exec.dir/src/main.cpp.o -c /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/src/main.cpp

CMakeFiles/proj_exec.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj_exec.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/src/main.cpp > CMakeFiles/proj_exec.dir/src/main.cpp.i

CMakeFiles/proj_exec.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj_exec.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/src/main.cpp -o CMakeFiles/proj_exec.dir/src/main.cpp.s

CMakeFiles/proj_exec.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/proj_exec.dir/src/main.cpp.o.requires

CMakeFiles/proj_exec.dir/src/main.cpp.o.provides: CMakeFiles/proj_exec.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/proj_exec.dir/build.make CMakeFiles/proj_exec.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/proj_exec.dir/src/main.cpp.o.provides

CMakeFiles/proj_exec.dir/src/main.cpp.o.provides.build: CMakeFiles/proj_exec.dir/src/main.cpp.o

CMakeFiles/proj_exec.dir/src/tests.cpp.o: CMakeFiles/proj_exec.dir/flags.make
CMakeFiles/proj_exec.dir/src/tests.cpp.o: ../src/tests.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/proj_exec.dir/src/tests.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/proj_exec.dir/src/tests.cpp.o -c /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/src/tests.cpp

CMakeFiles/proj_exec.dir/src/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj_exec.dir/src/tests.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/src/tests.cpp > CMakeFiles/proj_exec.dir/src/tests.cpp.i

CMakeFiles/proj_exec.dir/src/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj_exec.dir/src/tests.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/src/tests.cpp -o CMakeFiles/proj_exec.dir/src/tests.cpp.s

CMakeFiles/proj_exec.dir/src/tests.cpp.o.requires:
.PHONY : CMakeFiles/proj_exec.dir/src/tests.cpp.o.requires

CMakeFiles/proj_exec.dir/src/tests.cpp.o.provides: CMakeFiles/proj_exec.dir/src/tests.cpp.o.requires
	$(MAKE) -f CMakeFiles/proj_exec.dir/build.make CMakeFiles/proj_exec.dir/src/tests.cpp.o.provides.build
.PHONY : CMakeFiles/proj_exec.dir/src/tests.cpp.o.provides

CMakeFiles/proj_exec.dir/src/tests.cpp.o.provides.build: CMakeFiles/proj_exec.dir/src/tests.cpp.o

CMakeFiles/proj_exec.dir/src/ops.cpp.o: CMakeFiles/proj_exec.dir/flags.make
CMakeFiles/proj_exec.dir/src/ops.cpp.o: ../src/ops.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/proj_exec.dir/src/ops.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/proj_exec.dir/src/ops.cpp.o -c /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/src/ops.cpp

CMakeFiles/proj_exec.dir/src/ops.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj_exec.dir/src/ops.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/src/ops.cpp > CMakeFiles/proj_exec.dir/src/ops.cpp.i

CMakeFiles/proj_exec.dir/src/ops.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj_exec.dir/src/ops.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/src/ops.cpp -o CMakeFiles/proj_exec.dir/src/ops.cpp.s

CMakeFiles/proj_exec.dir/src/ops.cpp.o.requires:
.PHONY : CMakeFiles/proj_exec.dir/src/ops.cpp.o.requires

CMakeFiles/proj_exec.dir/src/ops.cpp.o.provides: CMakeFiles/proj_exec.dir/src/ops.cpp.o.requires
	$(MAKE) -f CMakeFiles/proj_exec.dir/build.make CMakeFiles/proj_exec.dir/src/ops.cpp.o.provides.build
.PHONY : CMakeFiles/proj_exec.dir/src/ops.cpp.o.provides

CMakeFiles/proj_exec.dir/src/ops.cpp.o.provides.build: CMakeFiles/proj_exec.dir/src/ops.cpp.o

# Object files for target proj_exec
proj_exec_OBJECTS = \
"CMakeFiles/proj_exec.dir/src/buffer.cpp.o" \
"CMakeFiles/proj_exec.dir/src/main.cpp.o" \
"CMakeFiles/proj_exec.dir/src/tests.cpp.o" \
"CMakeFiles/proj_exec.dir/src/ops.cpp.o"

# External object files for target proj_exec
proj_exec_EXTERNAL_OBJECTS =

proj_exec: CMakeFiles/proj_exec.dir/src/buffer.cpp.o
proj_exec: CMakeFiles/proj_exec.dir/src/main.cpp.o
proj_exec: CMakeFiles/proj_exec.dir/src/tests.cpp.o
proj_exec: CMakeFiles/proj_exec.dir/src/ops.cpp.o
proj_exec: CMakeFiles/proj_exec.dir/build.make
proj_exec: CMakeFiles/proj_exec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable proj_exec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proj_exec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj_exec.dir/build: proj_exec
.PHONY : CMakeFiles/proj_exec.dir/build

CMakeFiles/proj_exec.dir/requires: CMakeFiles/proj_exec.dir/src/buffer.cpp.o.requires
CMakeFiles/proj_exec.dir/requires: CMakeFiles/proj_exec.dir/src/main.cpp.o.requires
CMakeFiles/proj_exec.dir/requires: CMakeFiles/proj_exec.dir/src/tests.cpp.o.requires
CMakeFiles/proj_exec.dir/requires: CMakeFiles/proj_exec.dir/src/ops.cpp.o.requires
.PHONY : CMakeFiles/proj_exec.dir/requires

CMakeFiles/proj_exec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proj_exec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proj_exec.dir/clean

CMakeFiles/proj_exec.dir/depend:
	cd /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/6im3/mcrespin/Documents/Signal/signal_analysis_project /home/6im3/mcrespin/Documents/Signal/signal_analysis_project /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/build /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/build /home/6im3/mcrespin/Documents/Signal/signal_analysis_project/build/CMakeFiles/proj_exec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proj_exec.dir/depend
