cmake_minimum_required(VERSION 3.27)
project(Projet_CDataFrame C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projet_CDataFrame
        column.c
        column.h
        main.c
        cdataframe.c
        cdataframe.h)
