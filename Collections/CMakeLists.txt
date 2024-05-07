cmake_minimum_required(VERSION 3.28)
project(Collections C)

set(CMAKE_C_STANDARD 11)

add_library(Collections STATIC List.c
        Collections.h)
