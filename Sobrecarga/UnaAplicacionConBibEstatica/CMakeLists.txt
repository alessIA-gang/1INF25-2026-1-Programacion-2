cmake_minimum_required(VERSION 4.0)
project(UnaAplicacionConBibEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(UnaAplicacionConBibEstatica main.cpp
        MiBiblioteca/Funciones.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/MiBiblioteca")

target_link_libraries(UnaAplicacionConBibEstatica PRIVATE BibEstatica)
