# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Software\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Software\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/aeda2021_p02.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aeda2021_p02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aeda2021_p02.dir/flags.make

CMakeFiles/aeda2021_p02.dir/main.cpp.obj: CMakeFiles/aeda2021_p02.dir/flags.make
CMakeFiles/aeda2021_p02.dir/main.cpp.obj: CMakeFiles/aeda2021_p02.dir/includes_CXX.rsp
CMakeFiles/aeda2021_p02.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aeda2021_p02.dir/main.cpp.obj"
	D:\Development\mingw\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\aeda2021_p02.dir\main.cpp.obj -c D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\main.cpp

CMakeFiles/aeda2021_p02.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda2021_p02.dir/main.cpp.i"
	D:\Development\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\main.cpp > CMakeFiles\aeda2021_p02.dir\main.cpp.i

CMakeFiles/aeda2021_p02.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda2021_p02.dir/main.cpp.s"
	D:\Development\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\main.cpp -o CMakeFiles\aeda2021_p02.dir\main.cpp.s

CMakeFiles/aeda2021_p02.dir/Tests/tests.cpp.obj: CMakeFiles/aeda2021_p02.dir/flags.make
CMakeFiles/aeda2021_p02.dir/Tests/tests.cpp.obj: CMakeFiles/aeda2021_p02.dir/includes_CXX.rsp
CMakeFiles/aeda2021_p02.dir/Tests/tests.cpp.obj: ../Tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/aeda2021_p02.dir/Tests/tests.cpp.obj"
	D:\Development\mingw\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\aeda2021_p02.dir\Tests\tests.cpp.obj -c D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\Tests\tests.cpp

CMakeFiles/aeda2021_p02.dir/Tests/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda2021_p02.dir/Tests/tests.cpp.i"
	D:\Development\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\Tests\tests.cpp > CMakeFiles\aeda2021_p02.dir\Tests\tests.cpp.i

CMakeFiles/aeda2021_p02.dir/Tests/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda2021_p02.dir/Tests/tests.cpp.s"
	D:\Development\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\Tests\tests.cpp -o CMakeFiles\aeda2021_p02.dir\Tests\tests.cpp.s

CMakeFiles/aeda2021_p02.dir/Tests/fleet.cpp.obj: CMakeFiles/aeda2021_p02.dir/flags.make
CMakeFiles/aeda2021_p02.dir/Tests/fleet.cpp.obj: CMakeFiles/aeda2021_p02.dir/includes_CXX.rsp
CMakeFiles/aeda2021_p02.dir/Tests/fleet.cpp.obj: ../Tests/fleet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/aeda2021_p02.dir/Tests/fleet.cpp.obj"
	D:\Development\mingw\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\aeda2021_p02.dir\Tests\fleet.cpp.obj -c D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\Tests\fleet.cpp

CMakeFiles/aeda2021_p02.dir/Tests/fleet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda2021_p02.dir/Tests/fleet.cpp.i"
	D:\Development\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\Tests\fleet.cpp > CMakeFiles\aeda2021_p02.dir\Tests\fleet.cpp.i

CMakeFiles/aeda2021_p02.dir/Tests/fleet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda2021_p02.dir/Tests/fleet.cpp.s"
	D:\Development\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\Tests\fleet.cpp -o CMakeFiles\aeda2021_p02.dir\Tests\fleet.cpp.s

CMakeFiles/aeda2021_p02.dir/Tests/vehicle.cpp.obj: CMakeFiles/aeda2021_p02.dir/flags.make
CMakeFiles/aeda2021_p02.dir/Tests/vehicle.cpp.obj: CMakeFiles/aeda2021_p02.dir/includes_CXX.rsp
CMakeFiles/aeda2021_p02.dir/Tests/vehicle.cpp.obj: ../Tests/vehicle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/aeda2021_p02.dir/Tests/vehicle.cpp.obj"
	D:\Development\mingw\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\aeda2021_p02.dir\Tests\vehicle.cpp.obj -c D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\Tests\vehicle.cpp

CMakeFiles/aeda2021_p02.dir/Tests/vehicle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aeda2021_p02.dir/Tests/vehicle.cpp.i"
	D:\Development\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\Tests\vehicle.cpp > CMakeFiles\aeda2021_p02.dir\Tests\vehicle.cpp.i

CMakeFiles/aeda2021_p02.dir/Tests/vehicle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aeda2021_p02.dir/Tests/vehicle.cpp.s"
	D:\Development\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\Tests\vehicle.cpp -o CMakeFiles\aeda2021_p02.dir\Tests\vehicle.cpp.s

# Object files for target aeda2021_p02
aeda2021_p02_OBJECTS = \
"CMakeFiles/aeda2021_p02.dir/main.cpp.obj" \
"CMakeFiles/aeda2021_p02.dir/Tests/tests.cpp.obj" \
"CMakeFiles/aeda2021_p02.dir/Tests/fleet.cpp.obj" \
"CMakeFiles/aeda2021_p02.dir/Tests/vehicle.cpp.obj"

# External object files for target aeda2021_p02
aeda2021_p02_EXTERNAL_OBJECTS =

aeda2021_p02.exe: CMakeFiles/aeda2021_p02.dir/main.cpp.obj
aeda2021_p02.exe: CMakeFiles/aeda2021_p02.dir/Tests/tests.cpp.obj
aeda2021_p02.exe: CMakeFiles/aeda2021_p02.dir/Tests/fleet.cpp.obj
aeda2021_p02.exe: CMakeFiles/aeda2021_p02.dir/Tests/vehicle.cpp.obj
aeda2021_p02.exe: CMakeFiles/aeda2021_p02.dir/build.make
aeda2021_p02.exe: lib/libgtestd.a
aeda2021_p02.exe: lib/libgtest_maind.a
aeda2021_p02.exe: lib/libgtestd.a
aeda2021_p02.exe: CMakeFiles/aeda2021_p02.dir/linklibs.rsp
aeda2021_p02.exe: CMakeFiles/aeda2021_p02.dir/objects1.rsp
aeda2021_p02.exe: CMakeFiles/aeda2021_p02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable aeda2021_p02.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\aeda2021_p02.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aeda2021_p02.dir/build: aeda2021_p02.exe

.PHONY : CMakeFiles/aeda2021_p02.dir/build

CMakeFiles/aeda2021_p02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\aeda2021_p02.dir\cmake_clean.cmake
.PHONY : CMakeFiles/aeda2021_p02.dir/clean

CMakeFiles/aeda2021_p02.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2 D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2 D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\cmake-build-debug D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\cmake-build-debug D:\Documents\University\AEDA\FEUP-AEDA\TP\TP2\cmake-build-debug\CMakeFiles\aeda2021_p02.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aeda2021_p02.dir/depend

