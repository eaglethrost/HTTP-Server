cmake_minimum_required(VERSION 3.15)
project(HTTPServer)

add_subdirectory(include)
add_subdirectory(src)

option(BUILD_EXAMPLES "Build examples or not" ON)

if (BUILD_EXAMPLES)
    message(STATUS "Building example...")
    add_subdirectory(example)
endif()