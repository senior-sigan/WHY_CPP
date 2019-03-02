cmake_minimum_required(VERSION 3.6)
project(whycpp CXX)

math(EXPR BITNESS "8*${CMAKE_SIZEOF_VOID_P}")
set(CMAKE_CXX_STANDARD 11)
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX ")
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wswitch-default -Wfloat-equal -Wdangling-else -Wno-unused-parameter")
endif()

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

set(SDL2_FROM_SOURCE ON) # if you have libsdl2 installed use OFF instead

if (SDL2_FROM_SOURCE)
    include(ConfigureSDL2)
endif ()

set(LODEPNG_HEADERS ${PROJECT_SOURCE_DIR}/lib/lodepng/include)
add_subdirectory(lib/lodepng)
add_subdirectory(src)
add_subdirectory(example)
add_subdirectory(doc/examples)
#add_subdirectory(test)