#------------------------------------------------------------------------------
# External Project:     SDL2
# Downloads:            https://libsdl.org/release/
#------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8.2)

project(sdl2-download NONE)

include(ExternalProject)

message(STATUS "Compiling SDL2 from sources")

set(SDL2_CMAKE_ARGS
        -DSDL_SHARED=OFF
        -DSDL_STATIC=ON
        -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
        -DCMAKE_OSX_ARCHITECTURES=${CMAKE_OSX_ARCHITECTURES}
        )

ExternalProject_Add(
        sdl2
#            PREFIX ${DEPENDENCY_EXTRACT_DIR}
#            DOWNLOAD_DIR ${DEPENDENCY_DOWNLOAD_DIR}
        URL https://libsdl.org/release/SDL2-2.0.9.tar.gz
        URL_MD5 f2ecfba915c54f7200f504d8b48a5dfe
        SOURCE_DIR        "${CMAKE_CURRENT_BINARY_DIR}/sdl2-src"
        BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/sdl2-build"
#            CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${DEPENDENCY_INSTALL_DIR}
#            INSTALL_DIR ${DEPENDENCY_INSTALL_DIR}
#            CMAKE_ARGS ${SDL2_CMAKE_ARGS}
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
)