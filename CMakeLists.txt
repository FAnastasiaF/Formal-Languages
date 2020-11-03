cmake_minimum_required(VERSION 3.16)
project(regularexpressions)

set(CMAKE_CXX_STANDARD 17)

if(DEBUG)
    add_subdirectory(googletest-master)
    include_directories(googletest-master/googletest/include)
    include_directories(googletest-master/googlemock/include)
endif()

include_directories(task18)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
if(DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG=1")
    include_directories(tests)
    set(SOURCE_DEBUG_FILES tests/test.cpp)
endif()

set(SOURCE_FILES task18/main.cpp task18/MaxPrefixSymbol.cpp task18/MaxPrefixSymbol.h)

add_executable(regularexpressions ${SOURCE_FILES} ${SOURCE_DEBUG_FILES})
if(DEBUG)
    target_link_libraries(regularexpressions gtest gtest_main)
endif()