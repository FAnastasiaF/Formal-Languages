cmake_minimum_required(VERSION 3.16)
project(earleyparser)

set(CMAKE_CXX_STANDARD 17)

if(DEBUG)
    add_subdirectory(googletest-master)
    include_directories(googletest-master/googletest/include)
    include_directories(googletest-master/googlemock/include)
endif()

include_directories(EarleyParser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
if(DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG=1")
    include_directories(tests)
    set(SOURCE_DEBUG_FILES tests/test.cpp)
endif()

set(SOURCE_FILES EarleyParser/main.cpp "EarleyParser/Grammar.cpp" "EarleyParser/Grammar.h")

add_executable(earleyparser ${SOURCE_FILES} ${SOURCE_DEBUG_FILES})
if(DEBUG)
    target_link_libraries(earleyparser gtest gtest_main)
endif()
