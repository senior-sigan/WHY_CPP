cmake_minimum_required(VERSION 3.6)
project(whycpp_js CXX)

if (EMSCRIPTEN)
    add_definitions(-DEMSCRIPTEN)
    add_definitions(-DUSE_WASM)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --bind --memory-init-file 0 -s TOTAL_MEMORY=64*1024*1024 -s SAFE_HEAP=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1 -s USE_SDL=2 -s FORCE_FILESYSTEM=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s WASM=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s ASSERTIONS=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 --use-preload-plugins")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --embed-file example@/")
    set(CMAKE_EXECUTABLE_SUFFIX ".js")
endif()

include_directories(${WHYCPP_INCLUDES_DIR})

add_executable(whycpp_js ${WHYCPP_JS_SOURCES})

target_link_libraries(whycpp_js whycpp duktape duktape_modules)
target_include_directories(whycpp_js PRIVATE SYSTEM ${DUKTAPE_INCLUDE_DIR} ${DUKTAPE_MODULES_INCLUDE_DIR})