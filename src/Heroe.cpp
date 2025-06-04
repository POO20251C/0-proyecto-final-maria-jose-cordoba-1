//
// Created by majo on 25/05/2025.
//
#define GLIBCXX_USE_FLOAT128 0
#include "Heroe.h"
#include<iostream>
#include"Inventario.h"


Heroe::Heroe(const string& nombre, int s, int su, int a, int def, int vel)
    : Personaje(nombre,s, su,a,def,vel),
    inventario(std::make_unique<Inventario>()) { // Inicialización directa
    }

//Heroe::~Heroe() {
  //  delete inventario;
    //inventario = nullptr;
//}

void Heroe::setNombre(const std::string &nombre) {
    Personaje::setNombre(nombre);
}


//metodo
void Heroe::usarItem(Inventario& inventarioEquipo, const string& nombreItem) {
    if (inventarioEquipo.existeItem(nombreItem)) {
        inventarioEquipo.usarItem(nombreItem, *this);  //debo agregar item no he creado clase inventario
        //this--> puntero
        //ahora tenemso estos metoods
        cout<<nombre<<"Ha usado el item"<<nombreItem<<endl;

        //esta es una prubea porq ka verdad no se si esto esta funcionando o no jeje
        cout << "Nuevo ataque: " << getAtaque() << ", nueva defensa: " << getDefensa() << ", nueva salud: " << getSalud() << ", nueva suerte: " << getSuerte()<<endl;

    }
}
    void Heroe::agregarItem(const Arma& arma) {
        this->inventario->agregarArma(arma);}

void Heroe::agregarItem(const Armadura& armadura) {
    this->inventario->agregarArmadura(armadura);
}
void Heroe::agregarItem(const Pocion &pocion) {
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


