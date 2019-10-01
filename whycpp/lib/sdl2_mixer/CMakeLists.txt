cmake_minimum_required(VERSION 3.6)
project(SDL2-mixer C)

add_definitions(-DMUSIC_WAV)
add_definitions(-DMUSIC_CMD)

file(GLOB_RECURSE SDL2MIXER_INCLUDES include/*.h)
file(GLOB_RECURSE SDL2MIXER_HEADERS src/*.h)
file(GLOB_RECURSE SDL2MIXER_SOURCES src/*.c)

if (NOT EMSCRIPTEN)
    find_package(SDL2 REQUIRED)
    string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
endif ()

include_directories(include)

add_library(SDL2-mixer SHARED STATIC ${SDL2MIXER_SOURCES} ${SDL2MIXER_HEADERS} ${SDL2MIXER_INCLUDES})

target_include_directories(SDL2-mixer SYSTEM PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(SDL2-mixer ${SDL2_LIBRARIES})