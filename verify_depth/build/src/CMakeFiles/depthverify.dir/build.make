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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fish/Desktop/panoMaker/dtype_verify

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fish/Desktop/panoMaker/dtype_verify/build

# Include any dependencies generated for this target.
include src/CMakeFiles/depthverify.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/depthverify.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/depthverify.dir/flags.make

src/CMakeFiles/depthverify.dir/depthverify.cpp.o: src/CMakeFiles/depthverify.dir/flags.make
src/CMakeFiles/depthverify.dir/depthverify.cpp.o: ../src/depthverify.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fish/Desktop/panoMaker/dtype_verify/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/depthverify.dir/depthverify.cpp.o"
	cd /home/fish/Desktop/panoMaker/dtype_verify/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/depthverify.dir/depthverify.cpp.o -c /home/fish/Desktop/panoMaker/dtype_verify/src/depthverify.cpp

src/CMakeFiles/depthverify.dir/depthverify.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/depthverify.dir/depthverify.cpp.i"
	cd /home/fish/Desktop/panoMaker/dtype_verify/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/fish/Desktop/panoMaker/dtype_verify/src/depthverify.cpp > CMakeFiles/depthverify.dir/depthverify.cpp.i

src/CMakeFiles/depthverify.dir/depthverify.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/depthverify.dir/depthverify.cpp.s"
	cd /home/fish/Desktop/panoMaker/dtype_verify/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/fish/Desktop/panoMaker/dtype_verify/src/depthverify.cpp -o CMakeFiles/depthverify.dir/depthverify.cpp.s

src/CMakeFiles/depthverify.dir/depthverify.cpp.o.requires:
.PHONY : src/CMakeFiles/depthverify.dir/depthverify.cpp.o.requires

src/CMakeFiles/depthverify.dir/depthverify.cpp.o.provides: src/CMakeFiles/depthverify.dir/depthverify.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/depthverify.dir/build.make src/CMakeFiles/depthverify.dir/depthverify.cpp.o.provides.build
.PHONY : src/CMakeFiles/depthverify.dir/depthverify.cpp.o.provides

src/CMakeFiles/depthverify.dir/depthverify.cpp.o.provides.build: src/CMakeFiles/depthverify.dir/depthverify.cpp.o

# Object files for target depthverify
depthverify_OBJECTS = \
"CMakeFiles/depthverify.dir/depthverify.cpp.o"

# External object files for target depthverify
depthverify_EXTERNAL_OBJECTS =

../bin/depthverify: src/CMakeFiles/depthverify.dir/depthverify.cpp.o
../bin/depthverify: /usr/local/lib/libopencv_videostab.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_video.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_ts.a
../bin/depthverify: /usr/local/lib/libopencv_superres.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_stitching.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_photo.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_ocl.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_objdetect.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_nonfree.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_ml.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_legacy.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_imgproc.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_highgui.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_gpu.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_flann.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_features2d.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_core.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_contrib.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_calib3d.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_nonfree.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_ocl.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_gpu.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_photo.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_objdetect.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_legacy.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_video.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_ml.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_calib3d.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_features2d.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_highgui.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_imgproc.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_flann.so.2.4.11
../bin/depthverify: /usr/local/lib/libopencv_core.so.2.4.11
../bin/depthverify: src/CMakeFiles/depthverify.dir/build.make
../bin/depthverify: src/CMakeFiles/depthverify.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/depthverify"
	cd /home/fish/Desktop/panoMaker/dtype_verify/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/depthverify.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/depthverify.dir/build: ../bin/depthverify
.PHONY : src/CMakeFiles/depthverify.dir/build

src/CMakeFiles/depthverify.dir/requires: src/CMakeFiles/depthverify.dir/depthverify.cpp.o.requires
.PHONY : src/CMakeFiles/depthverify.dir/requires

src/CMakeFiles/depthverify.dir/clean:
	cd /home/fish/Desktop/panoMaker/dtype_verify/build/src && $(CMAKE_COMMAND) -P CMakeFiles/depthverify.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/depthverify.dir/clean

src/CMakeFiles/depthverify.dir/depend:
	cd /home/fish/Desktop/panoMaker/dtype_verify/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fish/Desktop/panoMaker/dtype_verify /home/fish/Desktop/panoMaker/dtype_verify/src /home/fish/Desktop/panoMaker/dtype_verify/build /home/fish/Desktop/panoMaker/dtype_verify/build/src /home/fish/Desktop/panoMaker/dtype_verify/build/src/CMakeFiles/depthverify.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/depthverify.dir/depend
