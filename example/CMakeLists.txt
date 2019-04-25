project(example CXX)

set(CMAKE_CXX_STANDARD 14)

include_directories(${WHYCPP_INCLUDES_DIR})

if (EMSCRIPTEN)
    add_definitions(-DEMSCRIPTEN)
    add_definitions(-DUSE_WASM)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --bind --memory-init-file 0 -s TOTAL_MEMORY=64*1024*1024 -s SAFE_HEAP=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1 -s USE_SDL=2 -s USE_SDL_MIXER=2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s WASM=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --use-preload-plugins")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --embed-file assets")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    file(COPY html/index.html DESTINATION ${CMAKE_BINARY_DIR}/example)
endif()

add_executable(example main.cpp)
target_link_libraries(example whycpp)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/example)