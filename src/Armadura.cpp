//
// Created by majo on 26/05/2025.
//

#define GLIBCXX_USE_FLOAT128 0
#include"Armadura.h"
#include"Heroe.h"
Armadura::Armadura(const std::string& nombre, int mejoraDefensa) {
    this->nombre = nombre;
    this->mejoraDefensa = mejoraDefensa;

}
//geter
std::string Armadura::getNombre() const{
    return this->nombre;
}
int Armadura::getMejoraDefensa() const {
    return this->mejoraDefensa;
}

//seter
void Armadura::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}
void Armadura::setMejoraDef(const int mejoraDefensa) {
    this->mejoraDefensa = mejoraDefensa;
}

void Armadura::aplicarEfecto(Heroe& heroe) {
    heroe.setDefensa(heroe.getDefensa() + mejoraDefensa);
}
