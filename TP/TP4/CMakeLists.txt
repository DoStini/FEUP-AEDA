cmake_minimum_required(VERSION 3.10)
project(aeda2021_p04)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

add_executable(aeda2021_p04 main.cpp Tests/tests.cpp Tests/carPark.cpp Tests/sequentialSearch.h Tests/insertionSort.h Tests/ClientDoesNotExist.cpp Tests/ClientDoesNotExist.h Tests/PositionDoesNotExiste.cpp Tests/PositionDoesNotExiste.h)

target_link_libraries(aeda2021_p04 gtest gtest_main)
