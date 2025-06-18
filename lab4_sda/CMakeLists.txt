cmake_minimum_required(VERSION 3.29)
project(lab4_sda C)

set(CMAKE_C_STANDARD 11)

add_executable(lab4_sda main.c
        functions.h
        functions.c
        structs.c)
