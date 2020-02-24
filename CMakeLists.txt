cmake_minimum_required(VERSION 3.2)
project (word_iterator)
#version number
set (WORD_ITERATOR_VERSION_MAJOR 1)
set (WORD_ITERATOR_VERSION_MINOR 0)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif()

add_executable(world_iterator src/main.cpp src/word_iterator.hpp)
