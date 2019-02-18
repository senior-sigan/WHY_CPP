project(whycpp CXX)

include_directories(${PROJECT_INCLUDES_DIR})

add_library(whycpp SHARED STATIC ${SOURCES} ${HEADERS} ${INCLUDES})

if (WIN32)
    target_link_libraries(whycpp winmm.lib)
endif ()

if (EMSCRIPTEN)
    add_definitions(-DEMSCRIPTEN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1 -s USE_SDL=2")
else ()
    if (SDL2_FROM_SOURCE)
        add_dependencies(whycpp SDL2-static SDL2main)
        target_include_directories(whycpp SYSTEM PRIVATE ${SDL2_HEADERS})
        target_link_libraries(whycpp SDL2main SDL2-static)
    else ()
        find_package(SDL2 REQUIRED)
        string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
        target_link_libraries(whycpp ${SDL2_LIBRARIES})
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