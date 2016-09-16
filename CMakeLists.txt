cmake_minimum_required(VERSION 3.6)
project(HelloCpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES vector_demo.cpp Solution.cpp Point.cpp)
add_executable(HelloCpp ${SOURCE_FILES})