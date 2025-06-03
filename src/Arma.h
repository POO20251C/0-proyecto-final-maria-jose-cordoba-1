//
// Created by majo on 26/05/2025.
//

#ifndef ARMA_H
#define ARMA_H
#include<string>
#include"Heroe.h"


class Heroe;

class Arma {
private:
    std::string nombre;
    int mejoraAtaque;
    int mejoraDefensa;


public:
    Arma();
    Arma(const std::string& nombre, int mejoraAtaque,int mejoraDefensa);

    //getters
    [[nodiscard]]std::string getNombre()const;
    [[nodiscard]]int getMejoraAtaque()const;
    [[nodiscard]]int getMejoraDef()const;


    //setter
    void setNombre(const std::string& nombre);
    void setMejoraAtaque(int mejoraAtaque);
    void setMejoraDef(int mejoraDefensa);

    //metodo
    void aplicarEfecto(Heroe& h);  //se que en el UML puse perosnaje,
                                    //pero quiero que sea mas espcifico osea q solos
                                    //los herores puedan usarlo tons asi lo cambie perdon jeje

};


#endif //ARMA_H
