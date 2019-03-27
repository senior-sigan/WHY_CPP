cmake_minimum_required(VERSION 3.6)
project(whycpp_c C)

if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /WX ")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wswitch-default -Wfloat-equal -Wdangling-else -Wunused-parameter -Wsign-conversion")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
endif()

include_directories(${WHYCPP_C_INCLUDES_DIR})
include_directories(${WHYCPP_INCLUDES_DIR})

message(WHYCPP_INCLUDES_DIR: ${WHYCPP_INCLUDES_DIR})

add_library(whycpp_c SHARED STATIC ${WHYCPP_C_SOURCES} ${WHYCPP_C_HEADERS} ${WHYCPP_C_INCLUDES} ${WHYCPP_HEADERS} ${WHYCPP_INCLUDES})
target_link_libraries(whycpp_c whycpp)