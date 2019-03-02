cmake_minimum_required(VERSION 3.6)
project(lodepng CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
add_library(lodepng picopng.cpp include/lodepng/picopng.h)