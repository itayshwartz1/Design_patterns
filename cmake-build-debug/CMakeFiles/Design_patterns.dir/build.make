# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Design-patterns

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Design-patterns\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Design_patterns.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\Design_patterns.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Design_patterns.dir\flags.make

CMakeFiles\Design_patterns.dir\Structural_Patterns\Flyweight.cpp.obj: CMakeFiles\Design_patterns.dir\flags.make
CMakeFiles\Design_patterns.dir\Structural_Patterns\Flyweight.cpp.obj: "..\Structural Patterns\Flyweight.cpp"
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Design-patterns\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Design_patterns.dir/Structural_Patterns/Flyweight.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Design_patterns.dir\Structural_Patterns\Flyweight.cpp.obj /FdCMakeFiles\Design_patterns.dir\ /FS -c "D:\Design-patterns\Structural Patterns\Flyweight.cpp"
<<

CMakeFiles\Design_patterns.dir\Structural_Patterns\Flyweight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Design_patterns.dir/Structural_Patterns/Flyweight.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\Design_patterns.dir\Structural_Patterns\Flyweight.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Design-patterns\Structural Patterns\Flyweight.cpp"
<<

CMakeFiles\Design_patterns.dir\Structural_Patterns\Flyweight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Design_patterns.dir/Structural_Patterns/Flyweight.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Design_patterns.dir\Structural_Patterns\Flyweight.cpp.s /c "D:\Design-patterns\Structural Patterns\Flyweight.cpp"
<<

# Object files for target Design_patterns
Design_patterns_OBJECTS = \
"CMakeFiles\Design_patterns.dir\Structural_Patterns\Flyweight.cpp.obj"

# External object files for target Design_patterns
Design_patterns_EXTERNAL_OBJECTS =

Design_patterns.exe: CMakeFiles\Design_patterns.dir\Structural_Patterns\Flyweight.cpp.obj
Design_patterns.exe: CMakeFiles\Design_patterns.dir\build.make
Design_patterns.exe: CMakeFiles\Design_patterns.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Design-patterns\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Design_patterns.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Design_patterns.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Design_patterns.dir\objects1.rsp @<<
 /out:Design_patterns.exe /implib:Design_patterns.lib /pdb:D:\Design-patterns\cmake-build-debug\Design_patterns.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Design_patterns.dir\build: Design_patterns.exe
.PHONY : CMakeFiles\Design_patterns.dir\build

CMakeFiles\Design_patterns.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Design_patterns.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Design_patterns.dir\clean

CMakeFiles\Design_patterns.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Design-patterns D:\Design-patterns D:\Design-patterns\cmake-build-debug D:\Design-patterns\cmake-build-debug D:\Design-patterns\cmake-build-debug\CMakeFiles\Design_patterns.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Design_patterns.dir\depend

