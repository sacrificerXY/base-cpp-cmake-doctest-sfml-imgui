cmake_minimum_required(VERSION 3.16.0)
project(base VERSION 0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

# source libraries
add_subdirectory("src")

# testing
include(CTest)
if(BUILD_TESTING)
    add_subdirectory("submodules/doctest")
    add_subdirectory("tests")
endif()

# main executable
add_subdirectory("app")
