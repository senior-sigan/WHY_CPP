cmake_minimum_required(VERSION 2.8.2)

project(duktape-download NONE)

include(ExternalProject)

ExternalProject_Add(
        duktape
        URL https://github.com/svaarala/duktape/releases/download/v2.3.0/duktape-2.3.0.tar.xz
        URL_MD5 352105b39979fc766bbd0b3721e8c2b5
        SOURCE_DIR        "${CMAKE_CURRENT_BINARY_DIR}/duktape-src"
        BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/duktape-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
)