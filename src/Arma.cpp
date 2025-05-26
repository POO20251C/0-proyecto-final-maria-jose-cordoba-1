//
// Created by majo on 26/05/2025.
//

#include "Arma.h"
Arma::Arma(string nombre, int mejoraDefensa, int mejoraAtaque) {
    this->nombre = nombre;
    this->mejoraDefensa = mejoraDefensa;
    this->mejoraAtaque = mejoraAtaque;
}

//getters
string Arma::getNombre()const {
    return nombre;
}
int Arma::getMejoraDef()const {
    return mejoraDefensa;
}
int Arma::getMejoraAtaque()const {
    return mejoraAtaque;
}

//setters
void Arma::setNombre(string nombre) {
    this->nombre = nombre;
}
void Arma::setMejoraDef(int mejoraDefensa) {
    this->mejoraDefensa = mejoraDefensa;
}
void Arma::setMejoraAtaque(int mejoraAtaque) {
    this->mejoraAtaque = mejoraAtaque;
}

//metodo
void Arma::aplicarEfecto(Heroe &h) {
    int nuevaDefensa= h.getDefensa()+mejoraDefensa;  //al principio use setDefensa pero debo usarlo en get
    int nuevoAtaque= h.getAtaque()+mejoraAtaque;     //pero set-->void tons no funciona
    h.setDefensa(nuevaDefensa);
    h.setAtaque(nuevoAtaque);
}
