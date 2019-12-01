cmake_minimum_required(VERSION 3.14)
project(basics1-program)

set(CMAKE_CXX_STANDARD 11)

add_executable(add add.cpp)
add_executable(add-var add-var.cpp)
add_executable(hello-world hello-world.cpp)
add_executable(hello-world-too hello-world-too.cpp)
add_executable(product product.cpp)
add_executable(inc-mod inc-mod.cpp)