project(whycpp CXX)

include_directories(${PROJECT_INCLUDES_DIR})

add_library(whycpp SHARED ${SOURCES} ${HEADERS} ${INCLUDES})

if (EMSCRIPTEN)
    add_definitions(-DEMSCRIPTEN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1 -s USE_SDL=2")
else ()
    find_package(SDL2 REQUIRED)
    string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
    target_link_libraries(whycpp ${SDL2_LIBRARIES})
endif ()

set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/why_cpp)
set(OUTPUT_LIB_DIR ${OUTPUT_DIR}/${CMAKE_SYSTEM_NAME}${BITNESS})
set_target_properties(whycpp PROPERTIES PUBLIC_HEADER "${INCLUDES}")

install(TARGETS whycpp
        LIBRARY DESTINATION ${OUTPUT_LIB_DIR}
        PUBLIC_HEADER DESTINATION ${OUTPUT_DIR}/include)