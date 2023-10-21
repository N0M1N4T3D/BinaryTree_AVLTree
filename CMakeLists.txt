cmake_minimum_required(VERSION 3.26)
project(tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tree
        class.cpp
        class.h
        main.cpp
        menu.cpp
        menu.h)
