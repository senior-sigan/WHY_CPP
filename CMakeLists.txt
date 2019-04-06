cmake_minimum_required(VERSION 3.6)

project(whycpp-root)

set(WHYCPP_INCLUDES_DIR ${PROJECT_SOURCE_DIR}/whycpp/include)
set(WHYCPP_C_INCLUDES_DIR ${PROJECT_SOURCE_DIR}/whycpp_c/include)

add_subdirectory(whycpp)
add_subdirectory(whycpp_c)
add_subdirectory(whycpp_python)
add_subdirectory(example)
add_subdirectory(example_c)
add_subdirectory(doc/examples)