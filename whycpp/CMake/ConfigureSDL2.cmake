configure_file(${CMAKE_DIR}/DownloadSDL2.cmake sdl2-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/sdl2-download )
if(result)
    message(FATAL_ERROR "CMake step for SDL2 failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/sdl2-download )
if(result)
    message(FATAL_ERROR "Build step for SDL2 failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory include ${CMAKE_CURRENT_BINARY_DIR}/sdl2-headers/SDL2
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/sdl2-src )
if(result)
    message(FATAL_ERROR "Build step for SDL2 failed: ${result}")
endif()

set(SDL_SHARED_ENABLED_BY_DEFAULT OFF)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/sdl2-src
        ${CMAKE_CURRENT_BINARY_DIR}/sdl2-build
        EXCLUDE_FROM_ALL)

set(SDL2_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/sdl2-headers)
set(SDL2_LIBRARIES SDL2main SDL2-static)