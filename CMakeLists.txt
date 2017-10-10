cmake_minimum_required(VERSION 3.8)
project(examples)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Stack.h StackTest.cpp StackTest.h)
add_executable(examples ${SOURCE_FILES})