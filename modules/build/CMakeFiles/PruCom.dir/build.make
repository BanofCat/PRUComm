# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/ban/Ban/PRUComm/modules

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ban/Ban/PRUComm/modules/build

# Include any dependencies generated for this target.
include CMakeFiles/PruCom.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PruCom.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PruCom.dir/flags.make

CMakeFiles/PruCom.dir/Main_test.cpp.o: CMakeFiles/PruCom.dir/flags.make
CMakeFiles/PruCom.dir/Main_test.cpp.o: ../Main_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ban/Ban/PRUComm/modules/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PruCom.dir/Main_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PruCom.dir/Main_test.cpp.o -c /home/ban/Ban/PRUComm/modules/Main_test.cpp

CMakeFiles/PruCom.dir/Main_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PruCom.dir/Main_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ban/Ban/PRUComm/modules/Main_test.cpp > CMakeFiles/PruCom.dir/Main_test.cpp.i

CMakeFiles/PruCom.dir/Main_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PruCom.dir/Main_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ban/Ban/PRUComm/modules/Main_test.cpp -o CMakeFiles/PruCom.dir/Main_test.cpp.s

CMakeFiles/PruCom.dir/Main_test.cpp.o.requires:

.PHONY : CMakeFiles/PruCom.dir/Main_test.cpp.o.requires

CMakeFiles/PruCom.dir/Main_test.cpp.o.provides: CMakeFiles/PruCom.dir/Main_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/PruCom.dir/build.make CMakeFiles/PruCom.dir/Main_test.cpp.o.provides.build
.PHONY : CMakeFiles/PruCom.dir/Main_test.cpp.o.provides

CMakeFiles/PruCom.dir/Main_test.cpp.o.provides.build: CMakeFiles/PruCom.dir/Main_test.cpp.o


CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o: CMakeFiles/PruCom.dir/flags.make
CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o: ../Communicator/src/rcs_comm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ban/Ban/PRUComm/modules/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o -c /home/ban/Ban/PRUComm/modules/Communicator/src/rcs_comm.cpp

CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ban/Ban/PRUComm/modules/Communicator/src/rcs_comm.cpp > CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.i

CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ban/Ban/PRUComm/modules/Communicator/src/rcs_comm.cpp -o CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.s

CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o.requires:

.PHONY : CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o.requires

CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o.provides: CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o.requires
	$(MAKE) -f CMakeFiles/PruCom.dir/build.make CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o.provides.build
.PHONY : CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o.provides

CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o.provides.build: CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o


CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o: CMakeFiles/PruCom.dir/flags.make
CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o: ../Communicator/src/uart_comm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ban/Ban/PRUComm/modules/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o -c /home/ban/Ban/PRUComm/modules/Communicator/src/uart_comm.cpp

CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ban/Ban/PRUComm/modules/Communicator/src/uart_comm.cpp > CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.i

CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ban/Ban/PRUComm/modules/Communicator/src/uart_comm.cpp -o CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.s

CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o.requires:

.PHONY : CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o.requires

CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o.provides: CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o.requires
	$(MAKE) -f CMakeFiles/PruCom.dir/build.make CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o.provides.build
.PHONY : CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o.provides

CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o.provides.build: CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o


CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o: CMakeFiles/PruCom.dir/flags.make
CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o: ../Parser/src/buffer_from_dsp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ban/Ban/PRUComm/modules/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o -c /home/ban/Ban/PRUComm/modules/Parser/src/buffer_from_dsp.cpp

CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ban/Ban/PRUComm/modules/Parser/src/buffer_from_dsp.cpp > CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.i

CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ban/Ban/PRUComm/modules/Parser/src/buffer_from_dsp.cpp -o CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.s

CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o.requires:

.PHONY : CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o.requires

CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o.provides: CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o.requires
	$(MAKE) -f CMakeFiles/PruCom.dir/build.make CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o.provides.build
.PHONY : CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o.provides

CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o.provides.build: CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o


CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o: CMakeFiles/PruCom.dir/flags.make
CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o: ../Parser/src/buffer_from_rcs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ban/Ban/PRUComm/modules/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o -c /home/ban/Ban/PRUComm/modules/Parser/src/buffer_from_rcs.cpp

CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ban/Ban/PRUComm/modules/Parser/src/buffer_from_rcs.cpp > CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.i

CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ban/Ban/PRUComm/modules/Parser/src/buffer_from_rcs.cpp -o CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.s

CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o.requires:

.PHONY : CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o.requires

CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o.provides: CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o.requires
	$(MAKE) -f CMakeFiles/PruCom.dir/build.make CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o.provides.build
.PHONY : CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o.provides

CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o.provides.build: CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o


CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o: CMakeFiles/PruCom.dir/flags.make
CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o: ../Parser/src/buffer_to_dsp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ban/Ban/PRUComm/modules/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o -c /home/ban/Ban/PRUComm/modules/Parser/src/buffer_to_dsp.cpp

CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ban/Ban/PRUComm/modules/Parser/src/buffer_to_dsp.cpp > CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.i

CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ban/Ban/PRUComm/modules/Parser/src/buffer_to_dsp.cpp -o CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.s

CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o.requires:

.PHONY : CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o.requires

CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o.provides: CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o.requires
	$(MAKE) -f CMakeFiles/PruCom.dir/build.make CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o.provides.build
.PHONY : CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o.provides

CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o.provides.build: CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o


CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o: CMakeFiles/PruCom.dir/flags.make
CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o: ../Parser/src/buffer_to_rcs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ban/Ban/PRUComm/modules/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o -c /home/ban/Ban/PRUComm/modules/Parser/src/buffer_to_rcs.cpp

CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ban/Ban/PRUComm/modules/Parser/src/buffer_to_rcs.cpp > CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.i

CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ban/Ban/PRUComm/modules/Parser/src/buffer_to_rcs.cpp -o CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.s

CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o.requires:

.PHONY : CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o.requires

CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o.provides: CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o.requires
	$(MAKE) -f CMakeFiles/PruCom.dir/build.make CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o.provides.build
.PHONY : CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o.provides

CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o.provides.build: CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o


CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o: CMakeFiles/PruCom.dir/flags.make
CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o: ../Utils/src/route_list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ban/Ban/PRUComm/modules/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o -c /home/ban/Ban/PRUComm/modules/Utils/src/route_list.cpp

CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ban/Ban/PRUComm/modules/Utils/src/route_list.cpp > CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.i

CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ban/Ban/PRUComm/modules/Utils/src/route_list.cpp -o CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.s

CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o.requires:

.PHONY : CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o.requires

CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o.provides: CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o.requires
	$(MAKE) -f CMakeFiles/PruCom.dir/build.make CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o.provides.build
.PHONY : CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o.provides

CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o.provides.build: CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o


# Object files for target PruCom
PruCom_OBJECTS = \
"CMakeFiles/PruCom.dir/Main_test.cpp.o" \
"CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o" \
"CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o" \
"CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o" \
"CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o" \
"CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o" \
"CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o" \
"CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o"

# External object files for target PruCom
PruCom_EXTERNAL_OBJECTS =

PruCom: CMakeFiles/PruCom.dir/Main_test.cpp.o
PruCom: CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o
PruCom: CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o
PruCom: CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o
PruCom: CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o
PruCom: CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o
PruCom: CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o
PruCom: CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o
PruCom: CMakeFiles/PruCom.dir/build.make
PruCom: CMakeFiles/PruCom.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ban/Ban/PRUComm/modules/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable PruCom"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PruCom.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PruCom.dir/build: PruCom

.PHONY : CMakeFiles/PruCom.dir/build

CMakeFiles/PruCom.dir/requires: CMakeFiles/PruCom.dir/Main_test.cpp.o.requires
CMakeFiles/PruCom.dir/requires: CMakeFiles/PruCom.dir/Communicator/src/rcs_comm.cpp.o.requires
CMakeFiles/PruCom.dir/requires: CMakeFiles/PruCom.dir/Communicator/src/uart_comm.cpp.o.requires
CMakeFiles/PruCom.dir/requires: CMakeFiles/PruCom.dir/Parser/src/buffer_from_dsp.cpp.o.requires
CMakeFiles/PruCom.dir/requires: CMakeFiles/PruCom.dir/Parser/src/buffer_from_rcs.cpp.o.requires
CMakeFiles/PruCom.dir/requires: CMakeFiles/PruCom.dir/Parser/src/buffer_to_dsp.cpp.o.requires
CMakeFiles/PruCom.dir/requires: CMakeFiles/PruCom.dir/Parser/src/buffer_to_rcs.cpp.o.requires
CMakeFiles/PruCom.dir/requires: CMakeFiles/PruCom.dir/Utils/src/route_list.cpp.o.requires

.PHONY : CMakeFiles/PruCom.dir/requires

CMakeFiles/PruCom.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PruCom.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PruCom.dir/clean

CMakeFiles/PruCom.dir/depend:
	cd /home/ban/Ban/PRUComm/modules/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ban/Ban/PRUComm/modules /home/ban/Ban/PRUComm/modules /home/ban/Ban/PRUComm/modules/build /home/ban/Ban/PRUComm/modules/build /home/ban/Ban/PRUComm/modules/build/CMakeFiles/PruCom.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PruCom.dir/depend

