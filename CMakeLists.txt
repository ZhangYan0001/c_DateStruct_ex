cmake_minimum_required(VERSION 3.27)
project(C_DateStruct_ex C)

set(CMAKE_C_STANDARD 17)
include_directories("./heard")

add_executable(C_DateStruct_ex main.c
        src/cLink.c
        src/cTest.c
        heard/cTest.h)
