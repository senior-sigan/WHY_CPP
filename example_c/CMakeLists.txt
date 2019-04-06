project(example_c C)

include_directories(${WHYCPP_C_INCLUDES_DIR})
include_directories(${WHYCPP_INCLUDES_DIR})

add_executable(example_c main.c)
target_link_libraries(example_c whycpp_c)
