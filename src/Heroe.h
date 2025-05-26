//
// Created by majo on 25/05/2025.
//

#ifndef HEROE_H
#define HEROE_H
#include <string>

#include"Personaje.h"
//#include <vector>
//#include"Inventario.h"

using namespace std;

class Heroe: public Personaje{
private:
    string nombre;

public:
    Heroe();
    Heroe(string nombre, int s, int su, int a, int def, int vel);

//getter
    string getNombre() const;
    //setter
    void setNombre(string nombre);  //al parecer aca no se pone const solo en el cpp:Clang-Tidy: Parameter 'nombre' is const-qualified in the function declaration; const-qualification of parameters only has an effect in function definitions
    //metodo
    void usarItem();   //debo agregar item:iventario porque aun no he creaod la clase

};



#endif //HEROE_H
