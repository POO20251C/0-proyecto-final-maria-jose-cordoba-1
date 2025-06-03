//
// Created by majo on 26/05/2025.
//

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
    Inventario(int capacidadMaxima);
    //metodos
    void agregarPocion(const Pocion& pocion); //se pñone Pocion& pocion y no vector<Popcion> pocion como siempre poruqe asi se agrega de a 1 y no de muchos a la vez
    void agregarArma(const Arma& arma);
    void agregarArmadura(const Armadura& armadura);
    void mostrarInventario();
    void usarItem(const string &item, Heroe &heroe);  //la verdd no sabia q poidia poner olos dos jutnos pero bueno
                                                    //Heroe &heroe--> referencia de quien lo usa


};



#endif //INVENTARIO_H
