project(sample-test)

add_executable(sample-test test-main.cpp)
target_link_libraries(sample-test src doctest)

add_test(SampleTest sample-test)
