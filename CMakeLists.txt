cmake_minimum_required(VERSION 3.30)
project(NatalKombat)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(NatalKombat main.cpp
        src/Personaje.cpp
        src/Personaje.h
        src/Heroe.cpp
        src/Heroe.h
        src/Villano.cpp
        src/Villano.h
        src/Inventario.cpp
        src/Inventario.h
        src/Arma.cpp
        src/Arma.h
        src/Armadura.cpp
        src/Armadura.h
        src/Pocion.cpp
        src/Pocion.h
        src/Sala.cpp
        src/Sala.h
)
