//
// Created by majo on 26/05/2025.
//

#include "Pocion.h"
Pocion::Pocion(const string& name, const int mejoraSalud, const int mejoraSuerte) {
    this->name = name;
    this->mejoraSalud = mejoraSalud;
    this->mejoraSuerte = mejoraSuerte;

}

//getters
string Pocion::getName() const{
    return this->name;
}
int Pocion::getMejoraSalud() const {
    return this->mejoraSalud;
}
int Pocion::getMejoraSuerte() const {
    return this->mejoraSuerte;
}
//setters
void Pocion::setMejoraSalud(const int mej) {
    this->mejoraSalud = mej;
}
void Pocion::setMejoraSuerte(const int mej) {
    this->mejoraSuerte = mej;
}
//metodo
void Pocion::aplicarEfecto(Heroe &h) {        //el heroe& se usa como referencia el puntero (heroe*) mo se usa porque (si sirve pero) el objeto puede llegar a ser nulo(osea que solo se pueda usar si hay un heroe"valido"
    int nuevaSalud= h.getSalud()+mejoraSalud;  //como siempre hay6 un heroe se usa &
    int nuevoSuerte= h.getSuerte()+mejoraSuerte;
    h.setSalud(nuevaSalud);
    h.setSuerte(nuevoSuerte);
}
