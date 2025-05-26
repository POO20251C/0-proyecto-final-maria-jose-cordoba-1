//
// Created by majo on 26/05/2025.
//

#include "Villano.h"

Villano::Villano(const string nombre, const string tipo, int s, int su, int a, int def, int vel)
    :Personaje(int s, int su, int a, int def, int vel ){
    this->nombre = nombre;
    this->tipo = tipo;
}

//getters
string Villano::getNombre()const {
    return nombre;
}
string Villano::getTipo()const {
    return tipo;
}
//setter
void Villano::setNombre(const string nombre) {
    this->nombre = nombre;
}
void Villano::setTipo(const string tipo) {
    this->tipo = tipo;
}

