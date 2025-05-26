//
// Created by majo on 25/05/2025.
//

#include "Heroe.h"

Heroe::Heroe(const string N, int s, int su, int a, int def, int vel)
    : Personaje(s, su,a,def,vel) {
    this->nombre = N;

}

//getter
string Heroe::getNombre() const {  //se que esto no lo puse en mi UML pero me parece necesrio porque aja debo nombrar a los heroes y
    return nombre;              // le puse const porque yo ya doy los nombres :)
}

//setter
void Heroe::setNombre(const string N) {
    this->nombre = N;
}

//metodo
void Heroe::usarItem() {                          //debo agregar item no he creado clase inventario

}

