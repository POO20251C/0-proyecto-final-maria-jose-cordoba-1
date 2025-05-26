//
// Created by majo on 26/05/2025.
//

#ifndef INVENTARIO_H
#define INVENTARIO_H
#include<vector>
#include"Arma.h"
#include"Armadura.h"
#include"Pocion.h"

using namespace std;
class Inventario {
private:
    vector<Pocion> pocion;
    vector<Armadura> armadura;
    vector<Arma> arma;
    int capacidadMaxima;

    public:
    Inventario();
    Inventario(int capacidadMaxima);
    //metodos
    void agregarPocion(vector<Pocion> pocion);
    void agregarArma(vector<Armadura> armadura);
    void agregarArma(vector<Arma> arma);
    void mostrarInventario();
    void usaritem();


};



#endif //INVENTARIO_H
