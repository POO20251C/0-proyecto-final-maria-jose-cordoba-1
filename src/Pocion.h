//
// Created by majo on 26/05/2025.
//

#ifndef POCION_H
#define POCION_H
#include"Heroe.h"
#include<string>
using namespace std;

class Heroe;

class Pocion {
private:
    string name;
    int mejoraSalud;
    int mejoraSuerte;

public:
    Pocion();
    Pocion(const string& name,int mejoraSalud, int mejoraSuerte);

    //getters
    string getName()const;
    int getMejoraSalud()const;
    int getMejoraSuerte()const;

    //setters
    void setName(string name);
    void setMejoraSalud(int mejoraSalud);
    void setMejoraSuerte(int mejoraSuerte);
    //metodo
    void aplicarEfecto(Heroe& h);

};



#endif //POCION_H
