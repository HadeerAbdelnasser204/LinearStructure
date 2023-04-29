cmake_minimum_required(VERSION 3.21)
project(LinearStructure)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LinearStructure
        CLL.cpp
        DLL.cpp
        list.cpp
        SLL.cpp
        queue
        Stack)
