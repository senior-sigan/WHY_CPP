cmake_minimum_required(VERSION 3.6)
project(whycpp_python C)

find_package(PythonLibs REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${WHYCPP_C_INCLUDES_DIR})
include_directories(${WHYCPP_INCLUDES_DIR})

add_executable(whycpp_python ${WHYCPP_PYTHON_SOURCES})

target_link_libraries(whycpp_python ${PYTHON_LIBRARIES} whycpp_c)