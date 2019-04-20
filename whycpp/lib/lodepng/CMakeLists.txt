cmake_minimum_required(VERSION 3.6)
project(lodepng CXX)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX ")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wfloat-equal -Wunused-parameter")
endif ()

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
add_library(lodepng SHARED STATIC picopng.cpp include/lodepng/picopng.h)
