cmake_minimum_required(VERSION 3.28)
project(Config C)

set(CMAKE_C_STANDARD 11)

link_directories(../Collections/cmake-build-debug)
include_directories(../Collections)

add_library(Config STATIC Config.c
        Parser.c
        Parser.h
        String.c
        String.h
        Types/ValueInt.c
        Types/ValueInt.h
        Types/ValueDouble.c
        Types/ValueDouble.h
        Types/ValueString.c
        Types/ValueString.h
        Types/ValueStruct.c
        Types/ValueStruct.h
        Types/ValueArray.c
        Types/ValueArray.h
        Types/ValueType.c
        Types/ValueType.h
        TextFile.c
        TextFile.h
        Types/ValueTypeFormat.h)

target_link_libraries (Config LINK_PUBLIC Collections)
