//
// Created by majo on 26/05/2025.
//

#include "Armadura.h"
#include"Heroe.h"
Armadura::Armadura(string nombre, int mejoraDefensa) {
    this->nombre = nombre;
    this->mejoraDefensa = mejoraDefensa;

}
//geter
string Armadura::getNombre() const{
    return this->nombre;
}
int Armadura::getMejoraDefensa() const {
    return this->mejoraDefensa;
}

//seter
void Armadura::setNombre(const string nombre) {
    this->nombre = nombre;
}
void Armadura::setMejoraDef(const int mejoraDefensa) {
    this->mejoraDefensa = mejoraDefensa;
}
void Armadura::aplicarEfecto(Heroe &h) {
    int nuevaDefensa= h.getDefensa()+mejoraDefensa;
    h.setDefensa(nuevaDefensa);
}
