//
// Created by majo on 20/05/2025.
//
#define _GLIBCXX_USE_FLOAT128 0
#include "Personaje.h"

Personaje::Personaje(const std::string& nombre,int s, int su, int a, int def, int vel) {
    this->nombre=nombre;
    this->salud=s;
    this->suerte=su;
    this->ataque=a;
    this->defensa=def;
    this->velocidad=vel;

}

//getters
string Personaje::getNombre() const {
    return nombre;
}
int Personaje::getSalud() {
    return salud;
}
int Personaje::getSuerte() {
    return suerte;
}
int Personaje::getAtaque() {
    return ataque;
}
int Personaje::getDefensa() {
    return defensa;
}
int Personaje::getVelocidad() {
    return velocidad;
}

//setters
void Personaje::setNombre(const std::string& nombre) {
    this->nombre=nombre;
}

void Personaje::setSalud(int s) {
    salud=s;
}
void Personaje::setSuerte(int su) {
    suerte=su;
}
void Personaje::setAtaque(int a) {
    ataque=a;
}
void Personaje::setDefensa(int def) {
    defensa=def;
}
void Personaje::setVelocidad(int vel) {
    velocidad=vel;
}
//metdos

void Personaje::atacar(Personaje &enemigo) {
    enemigo.recibirAtaque(ataque);
}

void Personaje::recibirAtaque(int ataqueEnemigo) {
    int danoReal=calcularDanoRecibido(ataqueEnemigo);

    salud-=danoReal;
    if (salud<0) {
        salud=0;
    }
}
int Personaje::calcularDanoRecibido(int ataqueEnemigo) {
    float factorDefensa=defensa * 0.5f;
    float factorSuerte=suerte * 0.3f;

    int dano=ataqueEnemigo - static_cast<int>(factorDefensa+factorSuerte);
    if(dano<0) dano=0;
    return dano;
}

bool Personaje::estaVivo() const {
    return salud>0;
}


