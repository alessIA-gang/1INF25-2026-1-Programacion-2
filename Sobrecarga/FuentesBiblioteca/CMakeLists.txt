cmake_minimum_required(VERSION 4.0)
project(FuentesBiblioteca)

set(CMAKE_CXX_STANDARD 20)

add_executable(FuentesBiblioteca main.cpp
        MiBiblioteca/Sobrecarga.cpp
        MiBiblioteca/Sobrecarga.h
        MiBiblioteca/Funciones.cpp
        MiBiblioteca/Funciones.h
        MiBiblioteca/Funciones.cpp)
