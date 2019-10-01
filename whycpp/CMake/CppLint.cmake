find_package(Python2 COMPONENTS Interpreter)

set(STYLE_FILTER)

# disable unwanted filters
#set(STYLE_FILTER ${STYLE_FILTER}-whitespace/braces,)
#set(STYLE_FILTER ${STYLE_FILTER}-whitespace/semicolon,)
#set(STYLE_FILTER ${STYLE_FILTER}-whitespace/blank_line,)
#set(STYLE_FILTER ${STYLE_FILTER}-whitespace/comma,)
#set(STYLE_FILTER ${STYLE_FILTER}-whitespace/operators,)
#set(STYLE_FILTER ${STYLE_FILTER}-whitespace/parens,)
#set(STYLE_FILTER ${STYLE_FILTER}-whitespace/indent,)
#set(STYLE_FILTER ${STYLE_FILTER}-whitespace/comments,)
set(STYLE_FILTER ${STYLE_FILTER}-whitespace/newline,)
#set(STYLE_FILTER ${STYLE_FILTER}-whitespace/tab,)
#set(STYLE_FILTER ${STYLE_FILTER}-whitespace/ending_newline,)

#set(STYLE_FILTER ${STYLE_FILTER}-build/include_subdir,)
#set(STYLE_FILTER ${STYLE_FILTER}-build/include_order,)
#set(STYLE_FILTER ${STYLE_FILTER}-build/namespaces,)
#set(STYLE_FILTER ${STYLE_FILTER}-build/include_what_you_use,)
#set(STYLE_FILTER ${STYLE_FILTER}-build/header_guard,)

set(STYLE_FILTER ${STYLE_FILTER}-readability/streams,)
set(STYLE_FILTER ${STYLE_FILTER}-readability/todo,)
#set(STYLE_FILTER ${STYLE_FILTER}-readability/namespace,)

#set(STYLE_FILTER ${STYLE_FILTER}-runtime/references,)
#set(STYLE_FILTER ${STYLE_FILTER}-runtime/int,)
#set(STYLE_FILTER ${STYLE_FILTER}-runtime/explicit,)
#set(STYLE_FILTER ${STYLE_FILTER}-runtime/printf,)

set(STYLE_FILTER ${STYLE_FILTER}-legal/copyright,)

# Add a target that runs cpplint.py
#
# Parameters:
# - TARGET_NAME the name of the target to add
# - SOURCES_LIST a complete list of source and include files to check
function(add_style_check_target CUSTOM_TARGET_NAME TARGET_NAME PROJECT_HEADERS_DIR PROJECT_SOURCES_DIR)

    if (NOT Python2_FOUND)
        return()
    endif ()

    FILE(GLOB_RECURSE SOURCES_LIST ${PROJECT_HEADERS_DIR}/*.h ${PROJECT_SOURCES_DIR}/*.cpp)

    list(REMOVE_DUPLICATES SOURCES_LIST)
    list(SORT SOURCES_LIST)

    add_custom_target(${CUSTOM_TARGET_NAME}
            COMMAND "${CMAKE_COMMAND}" -E chdir
            "${CMAKE_CURRENT_SOURCE_DIR}"
            ${Python2_EXECUTABLE}
            "${CMAKE_SOURCE_DIR}/misc/cpplint/cpplint.py"
            "--filter=${STYLE_FILTER}"
            "--counting=detailed"
            "--linelength=120"
            ${SOURCES_LIST}
            DEPENDS ${SOURCES_LIST}
            COMMENT "Linting ${TARGET_NAME}"
            VERBATIM)

endfunction()
