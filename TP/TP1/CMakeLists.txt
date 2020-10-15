cmake_minimum_required(VERSION 3.10)
project(aeda2021_fp01)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

add_executable(aeda2021_fp01 main.cpp Tests/tests.cpp Tests/parque.cpp)

target_link_libraries(aeda2021_fp01 gtest gtest_main)