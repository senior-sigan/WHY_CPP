project(whycpp CXX)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX ")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wfloat-equal -Wno-unused-private-field -Wunused-parameter -Wsign-conversion -Wold-style-cast")
    #    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
    #    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything")
endif ()

include_directories(${WHYCPP_INCLUDES_DIR})

if (EMSCRIPTEN)
    add_library(whycpp STATIC ${WHYCPP_SOURCES} ${WHYCPP_HEADERS} ${WHYCPP_INCLUDES})
else ()
    add_library(whycpp SHARED STATIC ${WHYCPP_SOURCES} ${WHYCPP_HEADERS} ${WHYCPP_INCLUDES})
endif ()

target_include_directories(whycpp SYSTEM PRIVATE ${LODEPNG_HEADERS})
target_link_libraries(whycpp lodepng)

if (WIN32)
    target_link_libraries(whycpp winmm.lib)
endif ()

if (EMSCRIPTEN)
    add_definitions(-DEMSCRIPTEN)
    add_definitions(-DSDL_MIXER)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1 -s USE_SDL=2 -s USE_SDL_MIXER=2")
else ()
    find_package(SDL2 REQUIRED)
    find_package(SDL2_mixer REQUIRED)

    target_include_directories(whycpp SYSTEM PRIVATE ${SDL2_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIRS})
    target_link_libraries(whycpp ${SDL2_LIBRARY} ${SDL2_MIXER_LIBRARIES})
endif ()

set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/whycpp_install)
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

configure_file(../whycpp.pc.in whycpp.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/whycpp.pc DESTINATION "${OUTPUT_LIB_DIR}/pkgconfig")