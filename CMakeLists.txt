cmake_minimum_required(VERSION 3.16.0)
project(base VERSION 0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory("src")
add_subdirectory("app")
add_subdirectory("tests")
