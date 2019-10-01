cmake_minimum_required(VERSION 3.6)
project(duktape C)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX ")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wfloat-equal -Wunused-parameter")
endif ()

set(CMAKE_C_STANDARD 11)
set(DUKTAPE_INCLUDE_DIR .)

if (EMSCRIPTEN)
    add_library(duktape STATIC duktape.c duk_config.h duktape.h duk_module_node.c duk_module_node.h)
else()
    add_library(duktape SHARED STATIC duktape.c duk_config.h duktape.h duk_module_node.c duk_module_node.h)
endif()

target_include_directories(duktape PRIVATE ${DUKTAPE_INCLUDE_DIR})