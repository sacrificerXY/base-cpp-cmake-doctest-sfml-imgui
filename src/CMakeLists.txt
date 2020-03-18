project(src)

add_library(src STATIC _sample/_sample.cpp)
target_include_directories(src PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(src sfml-graphics sfml-audio sfml-network)
