cmake_minimum_required(VERSION 3.6)
project(lodepng CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wswitch-default -Wfloat-equal -Wdangling-else -Wunused-parameter")

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
add_library(lodepng picopng.cpp include/lodepng/picopng.h)