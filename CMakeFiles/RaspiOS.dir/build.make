# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/filip/workspace/ccpp/raspiOS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/filip/workspace/ccpp/raspiOS

# Include any dependencies generated for this target.
include CMakeFiles/RaspiOS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RaspiOS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RaspiOS.dir/flags.make

CMakeFiles/RaspiOS.dir/src/window.cc.o: CMakeFiles/RaspiOS.dir/flags.make
CMakeFiles/RaspiOS.dir/src/window.cc.o: src/window.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/filip/workspace/ccpp/raspiOS/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RaspiOS.dir/src/window.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RaspiOS.dir/src/window.cc.o -c /home/filip/workspace/ccpp/raspiOS/src/window.cc

CMakeFiles/RaspiOS.dir/src/window.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RaspiOS.dir/src/window.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/filip/workspace/ccpp/raspiOS/src/window.cc > CMakeFiles/RaspiOS.dir/src/window.cc.i

CMakeFiles/RaspiOS.dir/src/window.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RaspiOS.dir/src/window.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/filip/workspace/ccpp/raspiOS/src/window.cc -o CMakeFiles/RaspiOS.dir/src/window.cc.s

CMakeFiles/RaspiOS.dir/src/window.cc.o.requires:
.PHONY : CMakeFiles/RaspiOS.dir/src/window.cc.o.requires

CMakeFiles/RaspiOS.dir/src/window.cc.o.provides: CMakeFiles/RaspiOS.dir/src/window.cc.o.requires
	$(MAKE) -f CMakeFiles/RaspiOS.dir/build.make CMakeFiles/RaspiOS.dir/src/window.cc.o.provides.build
.PHONY : CMakeFiles/RaspiOS.dir/src/window.cc.o.provides

CMakeFiles/RaspiOS.dir/src/window.cc.o.provides.build: CMakeFiles/RaspiOS.dir/src/window.cc.o

CMakeFiles/RaspiOS.dir/src/main.cc.o: CMakeFiles/RaspiOS.dir/flags.make
CMakeFiles/RaspiOS.dir/src/main.cc.o: src/main.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/filip/workspace/ccpp/raspiOS/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RaspiOS.dir/src/main.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RaspiOS.dir/src/main.cc.o -c /home/filip/workspace/ccpp/raspiOS/src/main.cc

CMakeFiles/RaspiOS.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RaspiOS.dir/src/main.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/filip/workspace/ccpp/raspiOS/src/main.cc > CMakeFiles/RaspiOS.dir/src/main.cc.i

CMakeFiles/RaspiOS.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RaspiOS.dir/src/main.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/filip/workspace/ccpp/raspiOS/src/main.cc -o CMakeFiles/RaspiOS.dir/src/main.cc.s

CMakeFiles/RaspiOS.dir/src/main.cc.o.requires:
.PHONY : CMakeFiles/RaspiOS.dir/src/main.cc.o.requires

CMakeFiles/RaspiOS.dir/src/main.cc.o.provides: CMakeFiles/RaspiOS.dir/src/main.cc.o.requires
	$(MAKE) -f CMakeFiles/RaspiOS.dir/build.make CMakeFiles/RaspiOS.dir/src/main.cc.o.provides.build
.PHONY : CMakeFiles/RaspiOS.dir/src/main.cc.o.provides

CMakeFiles/RaspiOS.dir/src/main.cc.o.provides.build: CMakeFiles/RaspiOS.dir/src/main.cc.o

CMakeFiles/RaspiOS.dir/src/pios.cc.o: CMakeFiles/RaspiOS.dir/flags.make
CMakeFiles/RaspiOS.dir/src/pios.cc.o: src/pios.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/filip/workspace/ccpp/raspiOS/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RaspiOS.dir/src/pios.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RaspiOS.dir/src/pios.cc.o -c /home/filip/workspace/ccpp/raspiOS/src/pios.cc

CMakeFiles/RaspiOS.dir/src/pios.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RaspiOS.dir/src/pios.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/filip/workspace/ccpp/raspiOS/src/pios.cc > CMakeFiles/RaspiOS.dir/src/pios.cc.i

CMakeFiles/RaspiOS.dir/src/pios.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RaspiOS.dir/src/pios.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/filip/workspace/ccpp/raspiOS/src/pios.cc -o CMakeFiles/RaspiOS.dir/src/pios.cc.s

CMakeFiles/RaspiOS.dir/src/pios.cc.o.requires:
.PHONY : CMakeFiles/RaspiOS.dir/src/pios.cc.o.requires

CMakeFiles/RaspiOS.dir/src/pios.cc.o.provides: CMakeFiles/RaspiOS.dir/src/pios.cc.o.requires
	$(MAKE) -f CMakeFiles/RaspiOS.dir/build.make CMakeFiles/RaspiOS.dir/src/pios.cc.o.provides.build
.PHONY : CMakeFiles/RaspiOS.dir/src/pios.cc.o.provides

CMakeFiles/RaspiOS.dir/src/pios.cc.o.provides.build: CMakeFiles/RaspiOS.dir/src/pios.cc.o

CMakeFiles/RaspiOS.dir/src/ui.cc.o: CMakeFiles/RaspiOS.dir/flags.make
CMakeFiles/RaspiOS.dir/src/ui.cc.o: src/ui.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/filip/workspace/ccpp/raspiOS/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RaspiOS.dir/src/ui.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RaspiOS.dir/src/ui.cc.o -c /home/filip/workspace/ccpp/raspiOS/src/ui.cc

CMakeFiles/RaspiOS.dir/src/ui.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RaspiOS.dir/src/ui.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/filip/workspace/ccpp/raspiOS/src/ui.cc > CMakeFiles/RaspiOS.dir/src/ui.cc.i

CMakeFiles/RaspiOS.dir/src/ui.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RaspiOS.dir/src/ui.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/filip/workspace/ccpp/raspiOS/src/ui.cc -o CMakeFiles/RaspiOS.dir/src/ui.cc.s

CMakeFiles/RaspiOS.dir/src/ui.cc.o.requires:
.PHONY : CMakeFiles/RaspiOS.dir/src/ui.cc.o.requires

CMakeFiles/RaspiOS.dir/src/ui.cc.o.provides: CMakeFiles/RaspiOS.dir/src/ui.cc.o.requires
	$(MAKE) -f CMakeFiles/RaspiOS.dir/build.make CMakeFiles/RaspiOS.dir/src/ui.cc.o.provides.build
.PHONY : CMakeFiles/RaspiOS.dir/src/ui.cc.o.provides

CMakeFiles/RaspiOS.dir/src/ui.cc.o.provides.build: CMakeFiles/RaspiOS.dir/src/ui.cc.o

CMakeFiles/RaspiOS.dir/src/LPI.cc.o: CMakeFiles/RaspiOS.dir/flags.make
CMakeFiles/RaspiOS.dir/src/LPI.cc.o: src/LPI.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/filip/workspace/ccpp/raspiOS/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RaspiOS.dir/src/LPI.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RaspiOS.dir/src/LPI.cc.o -c /home/filip/workspace/ccpp/raspiOS/src/LPI.cc

CMakeFiles/RaspiOS.dir/src/LPI.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RaspiOS.dir/src/LPI.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/filip/workspace/ccpp/raspiOS/src/LPI.cc > CMakeFiles/RaspiOS.dir/src/LPI.cc.i

CMakeFiles/RaspiOS.dir/src/LPI.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RaspiOS.dir/src/LPI.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/filip/workspace/ccpp/raspiOS/src/LPI.cc -o CMakeFiles/RaspiOS.dir/src/LPI.cc.s

CMakeFiles/RaspiOS.dir/src/LPI.cc.o.requires:
.PHONY : CMakeFiles/RaspiOS.dir/src/LPI.cc.o.requires

CMakeFiles/RaspiOS.dir/src/LPI.cc.o.provides: CMakeFiles/RaspiOS.dir/src/LPI.cc.o.requires
	$(MAKE) -f CMakeFiles/RaspiOS.dir/build.make CMakeFiles/RaspiOS.dir/src/LPI.cc.o.provides.build
.PHONY : CMakeFiles/RaspiOS.dir/src/LPI.cc.o.provides

CMakeFiles/RaspiOS.dir/src/LPI.cc.o.provides.build: CMakeFiles/RaspiOS.dir/src/LPI.cc.o

CMakeFiles/RaspiOS.dir/src/input.cc.o: CMakeFiles/RaspiOS.dir/flags.make
CMakeFiles/RaspiOS.dir/src/input.cc.o: src/input.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/filip/workspace/ccpp/raspiOS/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RaspiOS.dir/src/input.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RaspiOS.dir/src/input.cc.o -c /home/filip/workspace/ccpp/raspiOS/src/input.cc

CMakeFiles/RaspiOS.dir/src/input.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RaspiOS.dir/src/input.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/filip/workspace/ccpp/raspiOS/src/input.cc > CMakeFiles/RaspiOS.dir/src/input.cc.i

CMakeFiles/RaspiOS.dir/src/input.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RaspiOS.dir/src/input.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/filip/workspace/ccpp/raspiOS/src/input.cc -o CMakeFiles/RaspiOS.dir/src/input.cc.s

CMakeFiles/RaspiOS.dir/src/input.cc.o.requires:
.PHONY : CMakeFiles/RaspiOS.dir/src/input.cc.o.requires

CMakeFiles/RaspiOS.dir/src/input.cc.o.provides: CMakeFiles/RaspiOS.dir/src/input.cc.o.requires
	$(MAKE) -f CMakeFiles/RaspiOS.dir/build.make CMakeFiles/RaspiOS.dir/src/input.cc.o.provides.build
.PHONY : CMakeFiles/RaspiOS.dir/src/input.cc.o.provides

CMakeFiles/RaspiOS.dir/src/input.cc.o.provides.build: CMakeFiles/RaspiOS.dir/src/input.cc.o

CMakeFiles/RaspiOS.dir/src/profiling.cc.o: CMakeFiles/RaspiOS.dir/flags.make
CMakeFiles/RaspiOS.dir/src/profiling.cc.o: src/profiling.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/filip/workspace/ccpp/raspiOS/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/RaspiOS.dir/src/profiling.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RaspiOS.dir/src/profiling.cc.o -c /home/filip/workspace/ccpp/raspiOS/src/profiling.cc

CMakeFiles/RaspiOS.dir/src/profiling.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RaspiOS.dir/src/profiling.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/filip/workspace/ccpp/raspiOS/src/profiling.cc > CMakeFiles/RaspiOS.dir/src/profiling.cc.i

CMakeFiles/RaspiOS.dir/src/profiling.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RaspiOS.dir/src/profiling.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/filip/workspace/ccpp/raspiOS/src/profiling.cc -o CMakeFiles/RaspiOS.dir/src/profiling.cc.s

CMakeFiles/RaspiOS.dir/src/profiling.cc.o.requires:
.PHONY : CMakeFiles/RaspiOS.dir/src/profiling.cc.o.requires

CMakeFiles/RaspiOS.dir/src/profiling.cc.o.provides: CMakeFiles/RaspiOS.dir/src/profiling.cc.o.requires
	$(MAKE) -f CMakeFiles/RaspiOS.dir/build.make CMakeFiles/RaspiOS.dir/src/profiling.cc.o.provides.build
.PHONY : CMakeFiles/RaspiOS.dir/src/profiling.cc.o.provides

CMakeFiles/RaspiOS.dir/src/profiling.cc.o.provides.build: CMakeFiles/RaspiOS.dir/src/profiling.cc.o

# Object files for target RaspiOS
RaspiOS_OBJECTS = \
"CMakeFiles/RaspiOS.dir/src/window.cc.o" \
"CMakeFiles/RaspiOS.dir/src/main.cc.o" \
"CMakeFiles/RaspiOS.dir/src/pios.cc.o" \
"CMakeFiles/RaspiOS.dir/src/ui.cc.o" \
"CMakeFiles/RaspiOS.dir/src/LPI.cc.o" \
"CMakeFiles/RaspiOS.dir/src/input.cc.o" \
"CMakeFiles/RaspiOS.dir/src/profiling.cc.o"

# External object files for target RaspiOS
RaspiOS_EXTERNAL_OBJECTS =

RaspiOS: CMakeFiles/RaspiOS.dir/src/window.cc.o
RaspiOS: CMakeFiles/RaspiOS.dir/src/main.cc.o
RaspiOS: CMakeFiles/RaspiOS.dir/src/pios.cc.o
RaspiOS: CMakeFiles/RaspiOS.dir/src/ui.cc.o
RaspiOS: CMakeFiles/RaspiOS.dir/src/LPI.cc.o
RaspiOS: CMakeFiles/RaspiOS.dir/src/input.cc.o
RaspiOS: CMakeFiles/RaspiOS.dir/src/profiling.cc.o
RaspiOS: CMakeFiles/RaspiOS.dir/build.make
RaspiOS: /usr/lib/x86_64-linux-gnu/libSDL2.so
RaspiOS: /usr/lib/libawesomium-1-7.so
RaspiOS: CMakeFiles/RaspiOS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable RaspiOS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RaspiOS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RaspiOS.dir/build: RaspiOS
.PHONY : CMakeFiles/RaspiOS.dir/build

CMakeFiles/RaspiOS.dir/requires: CMakeFiles/RaspiOS.dir/src/window.cc.o.requires
CMakeFiles/RaspiOS.dir/requires: CMakeFiles/RaspiOS.dir/src/main.cc.o.requires
CMakeFiles/RaspiOS.dir/requires: CMakeFiles/RaspiOS.dir/src/pios.cc.o.requires
CMakeFiles/RaspiOS.dir/requires: CMakeFiles/RaspiOS.dir/src/ui.cc.o.requires
CMakeFiles/RaspiOS.dir/requires: CMakeFiles/RaspiOS.dir/src/LPI.cc.o.requires
CMakeFiles/RaspiOS.dir/requires: CMakeFiles/RaspiOS.dir/src/input.cc.o.requires
CMakeFiles/RaspiOS.dir/requires: CMakeFiles/RaspiOS.dir/src/profiling.cc.o.requires
.PHONY : CMakeFiles/RaspiOS.dir/requires

CMakeFiles/RaspiOS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RaspiOS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RaspiOS.dir/clean

CMakeFiles/RaspiOS.dir/depend:
	cd /home/filip/workspace/ccpp/raspiOS && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/filip/workspace/ccpp/raspiOS /home/filip/workspace/ccpp/raspiOS /home/filip/workspace/ccpp/raspiOS /home/filip/workspace/ccpp/raspiOS /home/filip/workspace/ccpp/raspiOS/CMakeFiles/RaspiOS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RaspiOS.dir/depend

