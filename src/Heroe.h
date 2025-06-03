//
// Created by majo on 25/05/2025.
//

#ifndef HEROE_H
#define HEROE_H
#include <string>
#include"Personaje.h"

class Inventario;
class Arma;
class Armadura;
class Pocion;

using namespace std;

class Heroe: public Personaje {
private:
    Inventario* inventario{};


public:
    Heroe(const std::string& nombre, int s, int su, int a, int def, int vel);

    virtual ~Heroe();  //destrucutor

    void añadirSalud(int valor);
    void añadirSuerte(int valor);
    void añadirAtaque(int valor);
    void añadirDefensa(int valor);
    void añadirVelocidad(int valor);
    void recuperarSaludCompleta(); //me toco agregarlo por la sala q regenra la salud
    Inventario* getInventario() { return inventario; }

    //setter
    void setNombre(const std::string& nombre)override;;  //al parecer aca no se pone const solo en el cpp:Clang-Tidy: Parameter 'nombre' is const-qualified in the function declaration; const-qualification of parameters only has an effect in function definitions
    //metodo
    void usarItem(Inventario& inventario, const string& nombreItem);   //debo agregar item:iventario porque aun no he creaod la clase
    void usarItem(const Arma& arma);
    void usarItem(const Armadura& armadura);
    void usarItem(const Pocion& pocion);
};



#endif //HEROE_H
