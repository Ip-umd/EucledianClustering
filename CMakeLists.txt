cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(KdTree)

include_directories(include)

add_executable (test 
src/main.cpp 
src/KdTree.cpp 
src/Node.cpp 
include/KdTree.hpp
include/Node.hpp
)
