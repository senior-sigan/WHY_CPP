cmake_minimum_required(VERSION 3.6)

project(whycpp-root)

set(WHYCPP_INCLUDES_DIR ${PROJECT_SOURCE_DIR}/whycpp/include)
set(WHYCPP_C_INCLUDES_DIR ${PROJECT_SOURCE_DIR}/whycpp_c/include)
set(WHYCPP_JS_INCLUDES_DIR ${PROJECT_SOURCE_DIR}/whycpp_js/include)

add_subdirectory(whycpp)
add_subdirectory(whycpp_c)
add_subdirectory(whycpp_python)
add_subdirectory(whycpp_js)
add_subdirectory(example)
add_subdirectory(example_c)
add_subdirectory(example_js)
add_subdirectory(doc/examples)