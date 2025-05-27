//
// Created by majo on 25/05/2025.
//

#include "Heroe.h"
#include"Inventario.h"

Heroe::Heroe(const string N, int s, int su, int a, int def, int vel)
    : Personaje(N,s, su,a,def,vel) {

}


//metodo
void Heroe::usarItem(Inventario& inventario, const string& nombreItem) {
    inventario.usarItem(nombreItem, *this);  //debo agregar item no he creado clase inventario
//this--> puntero
}

