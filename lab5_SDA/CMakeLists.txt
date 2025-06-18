cmake_minimum_required(VERSION 3.29)
project(lab5_SDA C)

set(CMAKE_C_STANDARD 11)

add_executable(lab5_SDA main.c
        functions.h
        functions.c
        structs.c
        structs.h)
