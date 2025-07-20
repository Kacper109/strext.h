cmake_minimum_required(VERSION 3.31)
project(strext_h C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(strext_h
        example.c
        strext.c
        strext.h)
