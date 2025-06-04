//
// Created by majo on 26/05/2025.
//
#define _GLIBCXX_USE_FLOAT128 0
#ifndef VILLANO_H
#define VILLANO_H
#include<string>
#include"Personaje.h"
using namespace std;

class Villano:public Personaje{
private:
    std::string tipo;

public:
    Villano();
    Villano(const std::string& nombre, const string& tipo, int s, int su, int a, int def, int vel);

    //getter
    [[nodiscard]] std::string getTipo() const ;
    //setter
    void setTipo(const std::string& tipo);

};






#endif //VILLANO_H
