cmake_minimum_required(VERSION 3.27)
project(Projet_CDataFrame C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projet_CDataFrame
        liste.c
        liste.h
        main.c)
