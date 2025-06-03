//
// Created by majo on 26/05/2025.
//

#ifndef VILLANO_H
#define VILLANO_H
#include"Personaje.h"
#include<string>

using namespace std;

class Villano:public Personaje{
private:
    std::string tipo;

public:
    Villano();
    Villano(const std::string& nombre, string tipo, int s, int su, int a, int def, int vel);

    //getter
    std::string getTipo() const ;
    //setter
    void setTipo(std::string tipo);

};



#endif //VILLANO_H
