cmake_minimum_required(VERSION 3.28)
project(TestCollections C)

set(CMAKE_C_STANDARD 11)

link_directories(../Collections/cmake-build-debug)

add_executable(TestCollections main.c)

target_link_libraries (TestCollections LINK_PUBLIC Collections)

include_directories(../Collections)