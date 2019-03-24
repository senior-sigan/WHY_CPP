cmake_minimum_required(VERSION 3.6)

project(whycpp-root)

set(WHYCPP_INCLUDES_DIR ${PROJECT_SOURCE_DIR}/whycpp/include)

add_subdirectory(whycpp)
add_subdirectory(example)
add_subdirectory(doc/examples)