cmake_minimum_required(VERSION 3.10)
project(aeda2021_p10)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

add_executable(aeda2021_p10 main.cpp Tests/tests.cpp Tests/box.cpp Tests/packagingMachine.cpp)

target_link_libraries(aeda2021_p10 gtest gtest_main)