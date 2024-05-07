cmake_minimum_required(VERSION 3.28)
project(TestConfig C)

set(CMAKE_C_STANDARD 11)

link_directories(
        ../Config/cmake-build-debug
        ../Collections/cmake-build-debug
)


add_executable(TestConfig main.c)

target_link_libraries (TestConfig LINK_PUBLIC Config)
target_link_libraries (TestConfig LINK_PUBLIC Collections)


include_directories(
        ../Config
        ../Collections
)
