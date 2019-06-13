cmake_minimum_required(VERSION 3.6)
project(whycpp CXX)

math(EXPR BITNESS "8*${CMAKE_SIZEOF_VOID_P}")
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_DIR "${PROJECT_SOURCE_DIR}/CMake")
list(APPEND CMAKE_MODULE_PATH ${CMAKE_DIR})

set(WHYCPP_INCLUDES_DIR ${PROJECT_SOURCE_DIR}/include)
set(WHYCPP_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE WHYCPP_INCLUDES ${WHYCPP_INCLUDES_DIR}/*.h)
file(GLOB_RECURSE WHYCPP_HEADERS ${WHYCPP_SOURCES_DIR}/*.h)
file(GLOB_RECURSE WHYCPP_SOURCES ${WHYCPP_SOURCES_DIR}/*.cpp)

if (NOT DEFINED SDL2_FROM_SOURCE AND NOT EMSCRIPTEN)
    message(STATUS "By default SDL2_FROM_SOURCE=ON")
    set(SDL2_FROM_SOURCE ON) # if you have libsdl2 installed use OFF instead
endif()

if (SDL2_FROM_SOURCE AND NOT EMSCRIPTEN)
    include(ConfigureSDL2)
endif ()

set(LODEPNG_HEADERS ${PROJECT_SOURCE_DIR}/lib/lodepng/include)
set(SDL2MIXER_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/lib/sdl2_mixer/include)
add_subdirectory(lib/lodepng)
add_subdirectory(lib/sdl2_mixer)
add_subdirectory(src)