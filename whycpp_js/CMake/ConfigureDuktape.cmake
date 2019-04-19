configure_file(${CMAKE_DIR}/DownloadDuktape.cmake duktape-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/duktape-download )
if(result)
    message(FATAL_ERROR "CMake step for duktape failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/duktape-download )
if(result)
    message(FATAL_ERROR "Build step for duktape failed: ${result}")
endif()

SET(DUKTAPE_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/duktape-src/src-separate)
file(GLOB_RECURSE DUKTAPE_SOURCES ${CMAKE_CURRENT_BINARY_DIR}/duktape-src/src-separate/*.c)
file(GLOB_RECURSE DUKTAPE_HEADERS ${CMAKE_CURRENT_BINARY_DIR}/duktape-src/src-separate/*.h)

SET(DUKTAPE_MODULES_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/duktape-src/extras/module-node)
SET(DUKTAPE_MODULES_SOURCES ${DUKTAPE_MODULES_INCLUDE_DIR}/duk_module_node.c)
SET(DUKTAPE_MODULES_HEADERS ${DUKTAPE_MODULES_INCLUDE_DIR}/duk_module_node.h)

message(STATUS ${DUKTAPE_MODULES_SOURCES})

add_library(duktape STATIC SHARED ${DUKTAPE_SOURCES} ${DUKTAPE_HEADERS})
target_include_directories(duktape PRIVATE ${DUKTAPE_INCLUDE_DIR})

add_library(duktape_modules STATIC SHARED ${DUKTAPE_MODULES_SOURCES} ${DUKTAPE_MODULES_HEADERS})
target_link_libraries(duktape_modules duktape)
target_include_directories(duktape_modules PRIVATE ${DUKTAPE_MODULES_INCLUDE_DIR} ${DUKTAPE_INCLUDE_DIR})