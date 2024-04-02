cmake_minimum_required(VERSION 3.24)

project(algorithms CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(GTest REQUIRED)

add_subdirectory(src)
add_subdirectory(test)
