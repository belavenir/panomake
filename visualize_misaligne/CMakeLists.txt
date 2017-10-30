cmake_minimum_required(VERSION 2.8)

PROJECT(panoMatching) 

SET(CMAKE_CXX_COMPILER "g++") 

SET(CMAKE_BUILD_TYPE "Debug") #debugger of GDB

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)


