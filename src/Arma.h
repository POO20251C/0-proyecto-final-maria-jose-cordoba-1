//
// Created by majo on 26/05/2025.
//

#ifndef ARMA_H
#define ARMA_H
#include<string>
#include"Heroe.h"
using namespace std;

class Arma {
private:
    string nombre;
    int mejoraAtaque;
    int mejoraDefensa;


public:
    Arma();
    Arma(string nombre, int mejoraAtaque,int mejoraDefensa);

    //getters
    string getNombre()const;
    int getMejoraAtaque()const;
    int getMejoraDef()const;


    //setter
    void setNombre(string nombre);
    void setMejoraAtaque(int mejoraAtaque);
    void setMejoraDef(int mejoraDefensa);

    //metodo
    void aplicarEfecto(Heroe& h);  //se que en el UML puse perosnaje,
                                    //pero quiero que sea mas espcifico osea q solos
                                    //los herores puedan usarlo tons asi lo cambie perdon jeje

};


#endif //ARMA_H
