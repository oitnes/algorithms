cmake_minimum_required(VERSION 3.10)
project(algorithms CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# compiler specific settings
set(CMAKE_CXX_COMPILER_VERSION "10.0") # current conan file is not working with apple compiler version >12.0

# conan settings
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.9/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake)

# libs settings throw conan
set(CONAN_EXTERNAL_LIBS gtest/1.11.0)
conan_cmake_run(REQUIRES ${CONAN_EXTERNAL_LIBS} BASIC_SETUP)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_define_targets()

add_subdirectory(src)
add_subdirectory(test)
