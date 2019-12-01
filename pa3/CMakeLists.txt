cmake_minimum_required(VERSION 3.10)
project(pa3)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(pa3
        canvas.cpp
        canvas.h
        repl.cpp
        patch.cpp
        patch.h
        utils.cpp
        utils.h)
