cmake_minimum_required(VERSION 3.16.0)
project(base VERSION 0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

find_package(Git QUIET)

# get SFML as a git submodule
set(BUILD_SHARED_LIBS FALSE) # use static linking
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE_SFML "Update SFML during build" ON)
    if(GIT_SUBMODULE_SFML)
        message(STATUS "doctest update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive --depth 1 -- submodules/sfml
                        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "Submodule SFML update FAILED with: \"${GIT_SUBMOD_RESULT}\"")
        endif()
    endif()
endif()
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/submodules/sfml/CMakeLists.txt")
    message(FATAL_ERROR "Submodule SFML was not downloaded! GIT_SUBMODULE_SFML was turned off or failed. Please update submodules and try again.")
endif()
add_subdirectory("submodules/sfml")

# source libraries
add_subdirectory("src")

# testing
include(CTest)
if(BUILD_TESTING)
    # get doctest as a git submodule
    if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
        option(GIT_SUBMODULE_DOCTEST "Update doctest during build" ON)
        if(GIT_SUBMODULE_DOCTEST)
            message(STATUS "doctest update")
            execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive --depth 1 -- submodules/doctest
                            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                            RESULT_VARIABLE GIT_SUBMOD_RESULT)
            if(NOT GIT_SUBMOD_RESULT EQUAL "0")
                message(FATAL_ERROR "Submodule doctest update FAILED with: \"${GIT_SUBMOD_RESULT}\"")
            endif()
        endif()
    endif()
    if(NOT EXISTS "${PROJECT_SOURCE_DIR}/submodules/doctest/CMakeLists.txt")
        message(FATAL_ERROR "Submodule doctest was not downloaded! GIT_SUBMODULE_DOCTEST was turned off or failed. Please update submodules and try again.")
    endif()

    add_subdirectory("submodules/doctest")
    add_subdirectory("tests")
endif()

# main executable
add_subdirectory("app")
