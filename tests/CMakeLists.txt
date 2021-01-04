cmake_minimum_required(VERSION 3.16)
project(regularexpressionstests)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest-master)
include_directories(googletest-master/googletest/include)
include_directories(googletest-master/googlemock/include)


include_directories(.)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG=1")

set(SOURCE_DEBUG_FILES test.cpp)

set(SOURCE_FILES main.cpp ../task18/MaxPrefixSymbol.cpp ../task18/MaxPrefixSymbol.h)

add_executable(regularexpressionstests ${SOURCE_FILES} ${SOURCE_DEBUG_FILES})
target_link_libraries(regularexpressionstests gtest gtest_main)
