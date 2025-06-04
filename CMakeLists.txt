cmake_minimum_required(VERSION 3.30)
project(NatalKombat)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # ← Obliga a usar C++20 exacto
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(src)
if(MINGW)
    add_compile_definitions(_GLIBCXX_USE_FLOAT128=0)
    add_compile_options(-U__FLOAT128__ -U__SIZEOF_FLOAT128__)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mno-avx")  # Opcional: desactiva AVX
endif()
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
        src/Mazmorra.cpp
        src/Mazmorra.h
        src/Score.cpp
        src/Score.h
        src/Juego.cpp
        src/Juego.h
)
