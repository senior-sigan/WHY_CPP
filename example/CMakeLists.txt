project(example CXX)

include_directories(${PROJECT_INCLUDES_DIR})

if (EMSCRIPTEN)
    add_definitions(-DEMSCRIPTEN)
    add_definitions(-DUSE_WASM)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --bind --memory-init-file 0 -s TOTAL_MEMORY=64*1024*1024 -s SAFE_HEAP=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1 -s USE_SDL=2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s WASM=1 -s GL_DEBUG=1 -s GL_ASSERTIONS=1 -s TRACE_WEBGL_CALLS=0")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

add_executable(example main.cpp)
target_link_libraries(example whycpp)
