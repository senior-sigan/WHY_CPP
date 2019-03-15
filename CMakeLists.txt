cmake_minimum_required(VERSION 3.6)
project(whycpp CXX)

math(EXPR BITNESS "8*${CMAKE_SIZEOF_VOID_P}")
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_DIR "${PROJECT_SOURCE_DIR}/CMake")
list(APPEND CMAKE_MODULE_PATH ${CMAKE_DIR})

set(PROJECT_INCLUDES_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src)
set(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)
set(TEST_SOURCES_DIR ${PROJECT_SOURCE_DIR}/tests)

file(GLOB_RECURSE INCLUDES ${PROJECT_INCLUDES_DIR}/*.h)
file(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)
file(GLOB_RECURSE TEST_SOURCES ${TEST_SOURCES_DIR}/*.cpp)

if (NOT DEFINED SDL2_FROM_SOURCE AND NOT EMSCRIPTEN)
    message(STATUS "By default SDL2_FROM_SOURCE=ON")
    set(SDL2_FROM_SOURCE ON) # if you have libsdl2 installed use OFF instead
endif()

if (SDL2_FROM_SOURCE AND NOT EMSCRIPTEN)
    include(ConfigureSDL2)
endif ()

set(LODEPNG_HEADERS ${PROJECT_SOURCE_DIR}/lib/lodepng/include)
add_subdirectory(lib/lodepng)
add_subdirectory(src)
add_subdirectory(example)
add_subdirectory(doc/examples)
#add_subdirectory(test)