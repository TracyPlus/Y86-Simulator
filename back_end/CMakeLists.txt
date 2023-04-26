cmake_minimum_required(VERSION 3.21)
project(pj_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(pj_2
        Decode.cpp
        Decode.h
        Execute.cpp
        Execute.h
        Fetch.cpp
        Fetch.h
        header.h
        main.cpp
        Memory.cpp
        Memory.h
        Register.cpp
        Register.h
        Renewpc.cpp
        Renewpc.h
        variables_declaration.h
        variables_definition.cpp
        Wback.cpp
        Wback.h)
