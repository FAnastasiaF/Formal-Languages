cmake_minimum_required(VERSION 3.16)
project(regularexpressions)

set(CMAKE_CXX_STANDARD 17)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
set(SOURCE_FILES main.cpp MaxPrefixSymbol.cpp MaxPrefixSymbol.h)

add_executable(regularexpressions ${SOURCE_FILES})
