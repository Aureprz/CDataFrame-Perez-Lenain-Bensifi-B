cmake_minimum_required(VERSION 3.27)
project(CDataFrame_Perez_Lenain_Bensifi C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CDataFrame_Perez_Lenain_Bensifi
        cdataframe.c
        cdataframe.h
        column.c
        column.h
        list.c
        list.h
        main.c
        sort.h
        sort.h
        sort.c)
