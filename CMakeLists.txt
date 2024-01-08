cmake_minimum_required(VERSION 3.27)
project(C_DateStruct_ex C)

set(CMAKE_C_STANDARD 17)
include_directories("./include")

add_executable(C_DateStruct_ex main.c
        src/slist.c
        include/slist.h
)
