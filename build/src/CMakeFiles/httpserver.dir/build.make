# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/build

# Include any dependencies generated for this target.
include src/CMakeFiles/httpserver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/httpserver.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/httpserver.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/httpserver.dir/flags.make

src/CMakeFiles/httpserver.dir/Server.cpp.o: src/CMakeFiles/httpserver.dir/flags.make
src/CMakeFiles/httpserver.dir/Server.cpp.o: /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/src/Server.cpp
src/CMakeFiles/httpserver.dir/Server.cpp.o: src/CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/httpserver.dir/Server.cpp.o"
	cd /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/httpserver.dir/Server.cpp.o -MF CMakeFiles/httpserver.dir/Server.cpp.o.d -o CMakeFiles/httpserver.dir/Server.cpp.o -c /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/src/Server.cpp

src/CMakeFiles/httpserver.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/Server.cpp.i"
	cd /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/src/Server.cpp > CMakeFiles/httpserver.dir/Server.cpp.i

src/CMakeFiles/httpserver.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/Server.cpp.s"
	cd /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/src/Server.cpp -o CMakeFiles/httpserver.dir/Server.cpp.s

# Object files for target httpserver
httpserver_OBJECTS = \
"CMakeFiles/httpserver.dir/Server.cpp.o"

# External object files for target httpserver
httpserver_EXTERNAL_OBJECTS =

src/libhttpserver.a: src/CMakeFiles/httpserver.dir/Server.cpp.o
src/libhttpserver.a: src/CMakeFiles/httpserver.dir/build.make
src/libhttpserver.a: src/CMakeFiles/httpserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhttpserver.a"
	cd /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/build/src && $(CMAKE_COMMAND) -P CMakeFiles/httpserver.dir/cmake_clean_target.cmake
	cd /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/httpserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/httpserver.dir/build: src/libhttpserver.a
.PHONY : src/CMakeFiles/httpserver.dir/build

src/CMakeFiles/httpserver.dir/clean:
	cd /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/build/src && $(CMAKE_COMMAND) -P CMakeFiles/httpserver.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/httpserver.dir/clean

src/CMakeFiles/httpserver.dir/depend:
	cd /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/src /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/build /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/build/src /Users/dimasputraanugerah/Documents/Dimas/Projects/HTTP-Server/build/src/CMakeFiles/httpserver.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/httpserver.dir/depend

