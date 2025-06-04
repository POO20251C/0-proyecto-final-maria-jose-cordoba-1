//
// Created by majo on 26/05/2025.
//
#define _GLIBCXX_USE_FLOAT128 0
#ifndef INVENTARIO_H
#define INVENTARIO_H
#include<string>
#include<vector>
#include"Pocion.h"
#include"Arma.h"
#include"Armadura.h"

using namespace std;
class Pocion;
class Arma;
class Armadura;
class Heroe;

class Inventario {
private:
    int capacidadMaxima; //escribo el porque lo agregue porq honestemne me tarde mis buenos 30 min
                        //tratando de recordar orque habia escirto capacidad maxima
                        //tons capacidadmaxima= limite de items que puede tener un heroe
    vector<Pocion> pocion;
    vector<Arma> arma;
    vector<Armadura> armadura;


public:
    Inventario();
    explicit Inventario(int capacidadMaxima);
    //metodos
    bool agregarPocion(const Pocion& pocion); //se pñone Pocion& pocion y no vector<Popcion> pocion como siempre poruqe asi se agrega de a 1 y no de muchos a la vez
    bool agregarArma(const Arma& arma);
    bool agregarArmadura(const Armadura& armadura);
    void mostrarInventario();
    void* buscarItemPorNombre(const string& nombre); //si es un nombre largo pero me toco porq no se como mas ponerle a estos cosos
    void usarItem(const string &item, Heroe &heroe);  //la verdd no sabia q poidia poner olos dos jutnos pero bueno
    //Heroe &heroe--> referencia de quien lo usa
    bool esPocion(void* item);
    bool esArmadura(void* item);
    bool esArma(void* item);
    void eliminarPocion(const Pocion& pocion);
    void eliminarArma(const Arma& arma);
    void eliminarArmadura(const Armadura& armadura);
    bool existeItem(const std::string& nombre)const;

};



#endif //INVENTARIO_H
