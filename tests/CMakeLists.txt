project(test)

add_executable(test test-main.cpp)
target_link_libraries(test PUBLIC src)
