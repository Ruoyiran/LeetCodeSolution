cmake_minimum_required(VERSION 3.10)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)
include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(easy)
add_subdirectory(medium)
add_subdirectory(extra)
add_subdirectory(hard)
