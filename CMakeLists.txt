cmake_minimum_required(VERSION 3.13)
project(ipcalculator)

set(CMAKE_C_STANDARD  11)

include_directories(.)

add_executable(ipcalc
        cidr.c
        cidr.h
        ip.c
        ip.h
        main.c)
