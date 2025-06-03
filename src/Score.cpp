//
// Created by majo on 27/05/2025.
//
#include<iostream>
#include "Score.h"

Score::Score(const string usuario,const string fecha, const string hora, const int salaMaxSuperada, const int saludPerdida) {
    this->usuario = usuario;
    this->fecha = fecha;
    this->hora = hora;
    this->salaMaxSuperada = salaMaxSuperada;
    this->saludPerdida =saludPerdida;
}

//getters
string Score::getUsuario()const {
    return this->usuario;

}
string Score::getFecha() const {
    return this->fecha;
}
string Score::getHora() const {
    return this->hora;
}
int Score::getSalaMaxSuperada() const {
    return this->salaMaxSuperada;
}
int Score::getSaludPerdida() const  {
    return this->saludPerdida;
}

//setters
void Score::setUsuario(const string usuario) { this->usuario = usuario; }
void Score::setFecha(const string fecha) { this->fecha = fecha; }
void Score::setHora(const string hora) { this->hora = hora; }
void Score::setSalaMaxSuperada(int salaMaxSuperada) { this->salaMaxSuperada = salaMaxSuperada; }
void Score::setSaludPerdida(int saludPerdida) { this->saludPerdida = saludPerdida; }

//metodo
void Score::mostrarScore() const {
    cout << "Jugador: " << usuario << "\n";
    cout << "Fecha: " << fecha << " Hora: " << hora << "\n";
    cout << "Sala Máxima Superada: " << salaMaxSuperada << "\n";
    cout << "Salud Total Perdida: " << saludPerdida << "\n";
}