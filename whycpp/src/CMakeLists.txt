project(whycpp CXX)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX ")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wfloat-equal -Wunused-parameter -Wsign-conversion -Wold-style-cast")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
    #    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything")
endif ()

include_directories(${WHYCPP_INCLUDES_DIR})

add_library(whycpp SHARED STATIC ${WHYCPP_SOURCES} ${WHYCPP_HEADERS} ${WHYCPP_INCLUDES})

target_include_directories(whycpp SYSTEM PRIVATE ${LODEPNG_HEADERS})
target_link_libraries(whycpp lodepng)

if (WIN32)
    target_link_libraries(whycpp winmm.lib)
endif ()

if (EMSCRIPTEN)
    add_definitions(-DEMSCRIPTEN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1 -s USE_SDL=2")
else ()
    if (SDL2_FROM_SOURCE)
        add_dependencies(whycpp SDL2-static SDL2main)
        # TODO: compile sdl2_mixer from sources
    else ()
        find_package(SDL2 REQUIRED)
        find_package(SDL2_mixer)
        string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
    endif ()
    target_include_directories(whycpp SYSTEM PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(whycpp ${SDL2_LIBRARIES})

    if (SDL2_MIXER_FOUND)
        message(STATUS "Use compiled SDL2_MIXER")
        target_include_directories(whycpp SYSTEM PRIVATE ${SDL2_MIXER_INCLUDE_DIRS})
        target_link_libraries(${PROJECT_NAME} ${SDL2_MIXER_LIBRARIES})
    endif ()
endif ()

set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/why_cpp)
set(OUTPUT_LIB_DIR ${OUTPUT_DIR}/${CMAKE_SYSTEM_NAME}${BITNESS})
set_target_properties(whycpp PROPERTIES PUBLIC_HEADER "${INCLUDES}")

if (WIN32)
    # Fix unix-like "lib" prefix and ".a" suffix
    set_target_properties(whycpp PROPERTIES
            PREFIX ""
            SUFFIX ".dll"
            IMPORT_PREFIX ""
            IMPORT_SUFFIX ".lib")
endif ()

install(TARGETS whycpp
        ARCHIVE DESTINATION ${OUTPUT_LIB_DIR}
        LIBRARY DESTINATION ${OUTPUT_LIB_DIR}
        PUBLIC_HEADER DESTINATION ${OUTPUT_DIR}/include)