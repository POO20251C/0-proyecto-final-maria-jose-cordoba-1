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
    std::string name;
    int mejoraSalud;
    int mejoraSuerte;

public:
    Pocion();
    Pocion(const std::string& name,int mejoraSalud, int mejoraSuerte);

    //getters
    [[nodiscard]]std::string getName()const;
    [[nodiscard]]int getMejoraSalud()const;
    [[nodiscard]] int getMejoraSuerte()const;

    //setters
    void setName(const std::string& name);
    void setMejoraSalud(int mejoraSalud);
    void setMejoraSuerte(int mejoraSuerte);
    //metodo
    void aplicarEfecto(Heroe& h);
};



#endif //POCION_H
