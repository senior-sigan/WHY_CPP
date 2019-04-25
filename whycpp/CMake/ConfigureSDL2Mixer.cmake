configure_file(${CMAKE_DIR}/DownloadSDL2Mixer.cmake sdl2mixer-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/sdl2mixer-download)
if (result)
    message(FATAL_ERROR "CMake step for SDL2Mixer failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/sdl2mixer-download)
if (result)
    message(FATAL_ERROR "Build step for SDL2Mixer failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} -E copy SDL_mixer.h ${CMAKE_CURRENT_BINARY_DIR}/sdl2-headers/SDL2/SDL_mixer.h
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/sdl2mixer-src)
if (result)
    message(FATAL_ERROR "Build step for SDL2Mixer failed: ${result}")
endif ()

file(GLOB_RECURSE SDL2_MIXER_INCLUDES ${CMAKE_CURRENT_BINARY_DIR}/sdl2mixer-src/*.h)
file(GLOB_RECURSE SDL2_MIXER_SOURCES ${CMAKE_CURRENT_BINARY_DIR}/sdl2mixer-src/*.c)


add_library(SDL2mixer SHARED STATIC ${SDL2_MIXER_INCLUDES} ${SDL2_MIXER_SOURCES})
target_include_directories(SDL2mixer SYSTEM PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(SDL2mixer ${SDL2_LIBRARIES})

set(SDL2_MIXER_LIBRARIES SDL2mixer)