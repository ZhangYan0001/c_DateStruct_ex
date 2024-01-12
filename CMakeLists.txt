cmake_minimum_required(VERSION 3.27)
project(C_DateStruct_ex C)

set(CMAKE_C_STANDARD 17)
include_directories("./include")
file(GLOB SRC_FILES "src/*.c")

add_subdirectory(./test)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_library(cds ${SRC_FILES}
        )
#set_target_properties(cds PROPERTIES
#        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
#)