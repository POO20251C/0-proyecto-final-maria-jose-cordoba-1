//
// Created by majo on 26/05/2025.
//

#ifndef VILLANO_H
#define VILLANO_H
#include"Personaje.H"
#include<string>

using namespace std;

class Villano {
private:
    string nombre;
    string tipo;

public:
    Villano();
    Villano(string nombre, string tipo, int s, int su, int a, int def, int vel);

    //getter
    string getNombre()const;
    string getTipo() const ;
    //setter
    void setNombre(string nombre);
    void setTipo(string tipo);

};



#endif //VILLANO_H
