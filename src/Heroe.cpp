//
// Created by majo on 25/05/2025.
//

#include "Heroe.h"
#include"Inventario.h"
#include "Arma.h"
#include"Armadura.h"
#include"Pocion.h"

Heroe::Heroe(const string& nombre, int s, int su, int a, int def, int vel)
    : Personaje(nombre,s, su,a,def,vel) {

}
Heroe::~Heroe() {
    delete inventario;
}
void Heroe::setNombre(const std::string &nombre) {
    Personaje::setNombre(nombre);
}


//metodo
void Heroe::usarItem(Inventario& inventario, const string& nombreItem) {
    inventario.usarItem(nombreItem, *this);  //debo agregar item no he creado clase inventario
    //this--> puntero
    //ahora tenemso estos metoods
}
    void Heroe::usarItem(const Arma& arma) {
        this->inventario->agregarArma(arma);}

void Heroe::usarItem(const Armadura& armadura) {
    this->inventario->agregarArmadura(armadura);
}
void Heroe::usarItem(const Pocion &pocion) {
    this->inventario->agregarPocion(pocion);
}

void Heroe::añadirSalud(int valor){
    setSalud(getSalud()+valor);
}
void Heroe::añadirSuerte(int valor){
    setSuerte(getSuerte()+valor);
}
void Heroe::añadirAtaque(int valor){
    setAtaque(getAtaque()+valor);
}
void Heroe::añadirDefensa(int valor){
    setDefensa(getDefensa()+valor);
}
void Heroe::añadirVelocidad(int valor){
    setVelocidad(getVelocidad()+valor);
}

void Heroe::recuperarSaludCompleta() {
    setSalud(100);
}

