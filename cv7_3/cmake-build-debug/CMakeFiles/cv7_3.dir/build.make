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
CMAKE_SOURCE_DIR = /tmp/tmp.CWJiPmfxT5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.CWJiPmfxT5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cv7_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cv7_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cv7_3.dir/flags.make

CMakeFiles/cv7_3.dir/main.cu.o: CMakeFiles/cv7_3.dir/flags.make
CMakeFiles/cv7_3.dir/main.cu.o: ../main.cu
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.CWJiPmfxT5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CUDA object CMakeFiles/cv7_3.dir/main.cu.o"
	/usr/local/cuda/bin/nvcc  $(CUDA_DEFINES) $(CUDA_INCLUDES) $(CUDA_FLAGS) -x cu -dc /tmp/tmp.CWJiPmfxT5/main.cu -o CMakeFiles/cv7_3.dir/main.cu.o

CMakeFiles/cv7_3.dir/main.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CUDA source to CMakeFiles/cv7_3.dir/main.cu.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_PREPROCESSED_SOURCE

CMakeFiles/cv7_3.dir/main.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CUDA source to assembly CMakeFiles/cv7_3.dir/main.cu.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_ASSEMBLY_SOURCE

CMakeFiles/cv7_3.dir/main.cu.o.requires:

.PHONY : CMakeFiles/cv7_3.dir/main.cu.o.requires

CMakeFiles/cv7_3.dir/main.cu.o.provides: CMakeFiles/cv7_3.dir/main.cu.o.requires
	$(MAKE) -f CMakeFiles/cv7_3.dir/build.make CMakeFiles/cv7_3.dir/main.cu.o.provides.build
.PHONY : CMakeFiles/cv7_3.dir/main.cu.o.provides

CMakeFiles/cv7_3.dir/main.cu.o.provides.build: CMakeFiles/cv7_3.dir/main.cu.o


CMakeFiles/cv7_3.dir/sauce.cu.o: CMakeFiles/cv7_3.dir/flags.make
CMakeFiles/cv7_3.dir/sauce.cu.o: ../sauce.cu
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.CWJiPmfxT5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CUDA object CMakeFiles/cv7_3.dir/sauce.cu.o"
	/usr/local/cuda/bin/nvcc  $(CUDA_DEFINES) $(CUDA_INCLUDES) $(CUDA_FLAGS) -x cu -dc /tmp/tmp.CWJiPmfxT5/sauce.cu -o CMakeFiles/cv7_3.dir/sauce.cu.o

CMakeFiles/cv7_3.dir/sauce.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CUDA source to CMakeFiles/cv7_3.dir/sauce.cu.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_PREPROCESSED_SOURCE

CMakeFiles/cv7_3.dir/sauce.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CUDA source to assembly CMakeFiles/cv7_3.dir/sauce.cu.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_ASSEMBLY_SOURCE

CMakeFiles/cv7_3.dir/sauce.cu.o.requires:

.PHONY : CMakeFiles/cv7_3.dir/sauce.cu.o.requires

CMakeFiles/cv7_3.dir/sauce.cu.o.provides: CMakeFiles/cv7_3.dir/sauce.cu.o.requires
	$(MAKE) -f CMakeFiles/cv7_3.dir/build.make CMakeFiles/cv7_3.dir/sauce.cu.o.provides.build
.PHONY : CMakeFiles/cv7_3.dir/sauce.cu.o.provides

CMakeFiles/cv7_3.dir/sauce.cu.o.provides.build: CMakeFiles/cv7_3.dir/sauce.cu.o


CMakeFiles/cv7_3.dir/md5.cu.o: CMakeFiles/cv7_3.dir/flags.make
CMakeFiles/cv7_3.dir/md5.cu.o: ../md5.cu
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.CWJiPmfxT5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CUDA object CMakeFiles/cv7_3.dir/md5.cu.o"
	/usr/local/cuda/bin/nvcc  $(CUDA_DEFINES) $(CUDA_INCLUDES) $(CUDA_FLAGS) -x cu -dc /tmp/tmp.CWJiPmfxT5/md5.cu -o CMakeFiles/cv7_3.dir/md5.cu.o

CMakeFiles/cv7_3.dir/md5.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CUDA source to CMakeFiles/cv7_3.dir/md5.cu.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_PREPROCESSED_SOURCE

CMakeFiles/cv7_3.dir/md5.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CUDA source to assembly CMakeFiles/cv7_3.dir/md5.cu.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_ASSEMBLY_SOURCE

CMakeFiles/cv7_3.dir/md5.cu.o.requires:

.PHONY : CMakeFiles/cv7_3.dir/md5.cu.o.requires

CMakeFiles/cv7_3.dir/md5.cu.o.provides: CMakeFiles/cv7_3.dir/md5.cu.o.requires
	$(MAKE) -f CMakeFiles/cv7_3.dir/build.make CMakeFiles/cv7_3.dir/md5.cu.o.provides.build
.PHONY : CMakeFiles/cv7_3.dir/md5.cu.o.provides

CMakeFiles/cv7_3.dir/md5.cu.o.provides.build: CMakeFiles/cv7_3.dir/md5.cu.o


# Object files for target cv7_3
cv7_3_OBJECTS = \
"CMakeFiles/cv7_3.dir/main.cu.o" \
"CMakeFiles/cv7_3.dir/sauce.cu.o" \
"CMakeFiles/cv7_3.dir/md5.cu.o"

# External object files for target cv7_3
cv7_3_EXTERNAL_OBJECTS =

CMakeFiles/cv7_3.dir/cmake_device_link.o: CMakeFiles/cv7_3.dir/main.cu.o
CMakeFiles/cv7_3.dir/cmake_device_link.o: CMakeFiles/cv7_3.dir/sauce.cu.o
CMakeFiles/cv7_3.dir/cmake_device_link.o: CMakeFiles/cv7_3.dir/md5.cu.o
CMakeFiles/cv7_3.dir/cmake_device_link.o: CMakeFiles/cv7_3.dir/build.make
CMakeFiles/cv7_3.dir/cmake_device_link.o: CMakeFiles/cv7_3.dir/dlink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.CWJiPmfxT5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CUDA device code CMakeFiles/cv7_3.dir/cmake_device_link.o"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cv7_3.dir/dlink.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cv7_3.dir/build: CMakeFiles/cv7_3.dir/cmake_device_link.o

.PHONY : CMakeFiles/cv7_3.dir/build

# Object files for target cv7_3
cv7_3_OBJECTS = \
"CMakeFiles/cv7_3.dir/main.cu.o" \
"CMakeFiles/cv7_3.dir/sauce.cu.o" \
"CMakeFiles/cv7_3.dir/md5.cu.o"

# External object files for target cv7_3
cv7_3_EXTERNAL_OBJECTS =

cv7_3: CMakeFiles/cv7_3.dir/main.cu.o
cv7_3: CMakeFiles/cv7_3.dir/sauce.cu.o
cv7_3: CMakeFiles/cv7_3.dir/md5.cu.o
cv7_3: CMakeFiles/cv7_3.dir/build.make
cv7_3: CMakeFiles/cv7_3.dir/cmake_device_link.o
cv7_3: CMakeFiles/cv7_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.CWJiPmfxT5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CUDA executable cv7_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cv7_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cv7_3.dir/build: cv7_3

.PHONY : CMakeFiles/cv7_3.dir/build

CMakeFiles/cv7_3.dir/requires: CMakeFiles/cv7_3.dir/main.cu.o.requires
CMakeFiles/cv7_3.dir/requires: CMakeFiles/cv7_3.dir/sauce.cu.o.requires
CMakeFiles/cv7_3.dir/requires: CMakeFiles/cv7_3.dir/md5.cu.o.requires

.PHONY : CMakeFiles/cv7_3.dir/requires

CMakeFiles/cv7_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cv7_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cv7_3.dir/clean

CMakeFiles/cv7_3.dir/depend:
	cd /tmp/tmp.CWJiPmfxT5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.CWJiPmfxT5 /tmp/tmp.CWJiPmfxT5 /tmp/tmp.CWJiPmfxT5/cmake-build-debug /tmp/tmp.CWJiPmfxT5/cmake-build-debug /tmp/tmp.CWJiPmfxT5/cmake-build-debug/CMakeFiles/cv7_3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cv7_3.dir/depend

