//
// Created by majo on 26/05/2025.
//
#define _GLIBCXX_USE_FLOAT128 0
#include "Villano.h"

Villano::Villano(const string& nombre, const string& tipo, int s, int su, int a, int def, int vel)
    : Personaje(nombre, s, su, a, def, vel) {
    this->tipo = tipo;
}


//getters
string Villano::getTipo()const {
    return tipo;
}
//setter
void Villano::setTipo(const string& tipo) {
    this->tipo = tipo;
}

