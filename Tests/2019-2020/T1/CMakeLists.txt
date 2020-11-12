cmake_minimum_required(VERSION 3.10)
project(aeda1920_cp01)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)



add_executable(aeda1920_cp01 main.cpp Tests/tests.cpp Tests/Room.cpp)

target_link_libraries(aeda1920_cp01 gtest gtest_main)
