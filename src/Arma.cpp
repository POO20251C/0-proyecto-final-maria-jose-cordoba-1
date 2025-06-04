//
// Created by majo on 26/05/2025.
//
#define GLIBCXX_USE_FLOAT128 0
#include"Arma.h"
#include<iostream>
#include"Heroe.h"



Arma::Arma(const std::string& nombre, int mejoraAtaque,int mejoraDefensa) {
    this->nombre = nombre;
    this->mejoraAtaque = mejoraAtaque;
    this->mejoraDefensa = mejoraDefensa;

}

//getters
std::string Arma::getNombre()const {
    return nombre;
}
int Arma::getMejoraAtaque()const {
    return mejoraAtaque;
}
int Arma::getMejoraDef()const {
    return mejoraDefensa;
}


//setters
void Arma::setNombre(const std::string& nombre) {
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
    cout << "El arma aumentó el ataque a " << nuevoAtaque
             << " y la defensa a " << nuevaDefensa << "." << endl;
}
