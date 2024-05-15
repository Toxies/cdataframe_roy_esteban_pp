cmake_minimum_required(VERSION 3.27)
project(cdataframe_roy_esteban_pp C)

set(CMAKE_C_STANDARD 11)

add_executable(cdataframe_roy_esteban_pp
        main.c
        dataframe.c
        dataframe.h
        colonne.c
        colonne.h
)
