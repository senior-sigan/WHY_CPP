file(GLOB examples_SRCS "*.cpp")

include_directories(${WHYCPP_INCLUDES_DIR})

foreach(example_src ${examples_SRCS})
    get_filename_component(example ${example_src} NAME_WE)
    add_executable(${example} ${example_src})
    target_link_libraries(${example} whycpp)
#    add_custom_command(
#            TARGET ${example}
#            POST_BUILD
#            COMMAND ${example}
#            ARGS >${CMAKE_CURRENT_BINARY_DIR}/${example}.out
#    )
#    add_dependencies(all_examples ${example})
endforeach(example_src)