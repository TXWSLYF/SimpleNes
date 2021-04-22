cmake_minimum_required(VERSION 3.13)

# set project name
project(my_simple_nes)

# set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(test)