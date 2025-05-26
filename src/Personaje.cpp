//
// Created by majo on 20/05/2025.
//

#include "Personaje.h"

Personaje::Personaje(int s, int su, int a, int def, int vel) {
    this->salud=s;
    this->suerte=su;
    this->ataque=a;
    this->defensa=def;
    this->velocidad=vel;

}

//getters
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

void Personaje::recibirAtaque(int dano) {
    int danoReal=dano-defensa;
    if(danoReal<0) {
        danoReal=0; //esto es para no recibir ninugn ataque megativo osea q no tenga sentido
    }

    salud-=danoReal;
    if (salud<0) {
        salud=0;
    }
}

