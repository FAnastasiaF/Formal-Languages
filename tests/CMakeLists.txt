cmake_minimum_required(VERSION 3.16)
project(earleyparsertests)


set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest-master)
include_directories(googletest-master/googletest/include)
include_directories(googletest-master/googlemock/include)


include_directories(.)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG=1")

set(SOURCE_DEBUG_FILES test.cpp)

set(SOURCE_FILES main.cpp ../EarleyParser/Grammar.cpp ../EarleyParser/Grammar.h)

add_executable(earleyparsertests ${SOURCE_FILES} ${SOURCE_DEBUG_FILES})
target_link_libraries(earleyparsertests gtest gtest_main)
