cmake_minimum_required(VERSION 3.6)
project(whycpp_js CXX)

include_directories(${WHYCPP_JS_INCLUDES_DIR})
include_directories(${WHYCPP_INCLUDES_DIR})

if (EMSCRIPTEN)
    add_library(whycpp_js STATIC ${WHYCPP_JS_SOURCES} ${WHYCPP_JS_HEADERS} ${WHYCPP_JS_INCLUDES})
else ()
    add_library(whycpp_js SHARED STATIC ${WHYCPP_JS_SOURCES} ${WHYCPP_JS_HEADERS} ${WHYCPP_JS_INCLUDES})
endif ()

target_link_libraries(whycpp_js whycpp duktape duktape_modules)
target_include_directories(whycpp_js PRIVATE SYSTEM ${DUKTAPE_INCLUDE_DIR} ${DUKTAPE_MODULES_INCLUDE_DIR})