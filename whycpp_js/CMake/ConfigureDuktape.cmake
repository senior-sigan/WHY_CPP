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

add_library(duktape STATIC SHARED ${DUKTAPE_SOURCES} ${DUKTAPE_HEADERS})
target_include_directories(duktape PRIVATE ${DUKTAPE_INCLUDE_DIR})