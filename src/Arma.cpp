//
// Created by majo on 26/05/2025.
//

#include"Heroe.h"
#include "Arma.h"


Arma::Arma(string nombre, int mejoraAtaque,int mejoraDefensa) {
    this->nombre = nombre;
    this->mejoraAtaque = mejoraAtaque;
    this->mejoraDefensa = mejoraDefensa;

}

//getters
string Arma::getNombre()const {
    return nombre;
}
int Arma::getMejoraAtaque()const {
    return mejoraAtaque;
}
int Arma::getMejoraDef()const {
    return mejoraDefensa;
}


//setters
void Arma::setNombre(string nombre) {
    this->nombre = nombre;
}
void Arma::setMejoraAtaque(int mejoraAtaque) {
    this->mejoraAtaque = mejoraAtaque;
}
void Arma::setMejoraDef(int mejoraDefensa) {
    this->mejoraDefensa = mejoraDefensa;
}


//metodo
void Arma::aplicarEfecto(Heroe &h) {
    int nuevoAtaque= h.getAtaque()+mejoraAtaque;
    int nuevaDefensa= h.getDefensa()+mejoraDefensa;  //al principio use setDefensa pero debo usarlo en get
         //pero set-->void tons no funciona
    h.setAtaque(nuevoAtaque);
    h.setDefensa(nuevaDefensa);

}
