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
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Pengzhihui\Desktop\SerialChart

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Pengzhihui\Desktop\SerialChart\cmake-build-release-mingw-qt

# Utility rule file for SerialChart_autogen.

# Include the progress variables for this target.
include CMakeFiles/SerialChart_autogen.dir/progress.make

CMakeFiles/SerialChart_autogen: qrc_resources.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\Pengzhihui\Desktop\SerialChart\cmake-build-release-mingw-qt\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target SerialChart"
	"D:\Program Files\JetBrains\CLion\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E cmake_autogen C:/Users/Pengzhihui/Desktop/SerialChart/cmake-build-release-mingw-qt/CMakeFiles/SerialChart_autogen.dir/AutogenInfo.json Release

qrc_resources.cpp: ../images/new.png
qrc_resources.cpp: ../images/open.png
qrc_resources.cpp: ../images/save.png
qrc_resources.cpp: ../images/run.png
qrc_resources.cpp: ../images/stop.png
qrc_resources.cpp: ../resources.qrc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\Pengzhihui\Desktop\SerialChart\cmake-build-release-mingw-qt\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating qrc_resources.cpp"
	D:\Libraries\Qt\_Legacy\5.5.1\5.5\mingw492_32\bin\rcc.exe --name resources --output C:/Users/Pengzhihui/Desktop/SerialChart/cmake-build-release-mingw-qt/qrc_resources.cpp C:/Users/Pengzhihui/Desktop/SerialChart/resources.qrc

SerialChart_autogen: CMakeFiles/SerialChart_autogen
SerialChart_autogen: qrc_resources.cpp
SerialChart_autogen: CMakeFiles/SerialChart_autogen.dir/build.make

.PHONY : SerialChart_autogen

# Rule to build all files generated by this target.
CMakeFiles/SerialChart_autogen.dir/build: SerialChart_autogen

.PHONY : CMakeFiles/SerialChart_autogen.dir/build

CMakeFiles/SerialChart_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SerialChart_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SerialChart_autogen.dir/clean

CMakeFiles/SerialChart_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Pengzhihui\Desktop\SerialChart C:\Users\Pengzhihui\Desktop\SerialChart C:\Users\Pengzhihui\Desktop\SerialChart\cmake-build-release-mingw-qt C:\Users\Pengzhihui\Desktop\SerialChart\cmake-build-release-mingw-qt C:\Users\Pengzhihui\Desktop\SerialChart\cmake-build-release-mingw-qt\CMakeFiles\SerialChart_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SerialChart_autogen.dir/depend

