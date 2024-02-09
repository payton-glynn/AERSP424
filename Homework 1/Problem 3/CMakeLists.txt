cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(Question3) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # Specify C++ version.
include_directories(${CMAKE_SOURCE_DIR})	# header file folder
add_executable(question3 question3.cpp plane_class.h)		# source files

