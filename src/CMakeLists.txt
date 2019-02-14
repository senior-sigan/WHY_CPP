if (UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif ()

project(whycpp CXX)

include_directories(${PROJECT_INCLUDES_DIR})

add_library(whycpp SHARED ${SOURCES} ${HEADERS} ${INCLUDES})
target_compile_definitions(whycpp PRIVATE)

if (WIN32)
    target_link_libraries(whycpp winmm.lib)
endif ()

if (EMSCRIPTEN)
    add_definitions(-DEMSCRIPTEN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1 -s USE_SDL=2")
else ()
    find_package(SDL2 REQUIRED)
    string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
    target_link_libraries(whycpp ${SDL2_LIBRARIES})
endif ()

option(BUILD_SHARED_LIBS "Build dynamic version of library" ON)
if (NOT APPLE)
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "-s")
endif ()
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fvisibility=hidden")
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUNICODE")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static")
elseif (LINUX)
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static-libgcc")
endif ()
if (NOT BUILD_SHARED_LIBS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWHYCPP_STATIC_BUILD")
endif ()
math(EXPR BITNESS "8*${CMAKE_SIZEOF_VOID_P}")
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
elseif (APPLE)

endif ()

install(TARGETS whycpp
        ARCHIVE DESTINATION ${OUTPUT_LIB_DIR}
        LIBRARY DESTINATION ${OUTPUT_LIB_DIR}
        PUBLIC_HEADER DESTINATION ${OUTPUT_DIR}/include)