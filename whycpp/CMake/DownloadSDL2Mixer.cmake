cmake_minimum_required(VERSION 2.8.2)

project(sdl2mixer-download NONE)

include(ExternalProject)

message(STATUS "Compiling SDL2Mixer from sources")

set(SDL2MIXER_CMAKE_ARGS
-DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
-DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
-DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
-DCMAKE_OSX_ARCHITECTURES=${CMAKE_OSX_ARCHITECTURES}
)

ExternalProject_Add(
sdl2mixer
URL https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.4.tar.gz
URL_MD5 a36e8410cac46b00a4d01752b32c3eb1
SOURCE_DIR        "${CMAKE_CURRENT_BINARY_DIR}/sdl2mixer-src"
BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/sdl2mixer-build"
CONFIGURE_COMMAND ""
BUILD_COMMAND     ""
INSTALL_COMMAND   ""
TEST_COMMAND      ""
)