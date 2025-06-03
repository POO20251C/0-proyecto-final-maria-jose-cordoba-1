//
// Created by majo on 26/05/2025.
//

#include "Inventario.h"
#include"Pocion.h"
#include"Arma.h"
#include"Armadura.h"
#include "Heroe.h"
#include<iostream>

Inventario::Inventario(int cm) {
    this->capacidadMaxima=cm;

}
Inventario::Inventario() {
    capacidadMaxima = 15; //15 items maxxxxx
}

//metdos
void Inventario::agregarPocion(const Pocion& pocion) {
    if (static_cast<int>(this->pocion.size()) +
        static_cast<int>(armadura.size()) +
        static_cast<int>(arma.size()) < capacidadMaxima) {
        this->pocion.push_back(pocion);
    } else {
        cout <<"Inventario lleno, no se puede agregar pocion"<<endl;
}
}

void Inventario::agregarArma(const Arma& arma) {
    if (static_cast<int>(pocion.size()) +
        static_cast<int>(armadura.size()) +
        static_cast<int>(this->arma.size()) < capacidadMaxima) {
        this->arma.push_back(arma);
    } else {
        cout<<"Inventario lleno, no se puede agregar arma"<<endl;

    }
}

void Inventario::agregarArmadura(const Armadura& armadura) {
    if (static_cast<int>(pocion.size()) +
        static_cast<int>(this->armadura.size()) +
        static_cast<int>(arma.size()) < capacidadMaxima) {
        this->armadura.push_back(armadura);
    } else {
        cout<<"Inventario lleno, no se puede agregar armadura"<<endl;

    }
}

void Inventario::mostrarInventario() {
    //pociones
    cout<<"Pociones:"<<endl;
    if (pocion.empty()) {
        cout<<"No hay pociones"<<endl;
    }else {
        for (size_t i = 0; i < this->pocion.size(); i++) {
            cout<<"pociones:\n";
            cout<<"-"<<pocion[i].getName()<<endl;  //pocion[i].getName-->lo posiciona
        }

    }
    //armas
    cout<<"Armas:"<<endl;
    if (arma.empty()) {
        cout<<"No hay armas"<<endl;
    }else {
        for (size_t i = 0; i < this->arma.size(); i++) {
            cout<<"Armas:\n";
            cout<<"-"<<arma[i].getNombre()<<endl;
        }
    }
    //armaudra
    cout<<"Armaduras:"<<endl;
    if (armadura.empty()) {
        cout<<"No hay armaduras"<<endl;
    }else {
        for (size_t i = 0; i < this->armadura.size(); i++) {
            cout<<"Armadura:\n";
            cout<<"-"<<armadura[i].getNombre()<<endl;
        }
    }
}
void Inventario::usarItem(const string &nombreItem, Heroe &heroe) {
    // Buscar en pociones
    for (auto &p : pocion) {
        if (p.getName() == nombreItem) {
            p.aplicarEfecto(heroe);
            return;
        }
    }
    // Buscar en armaduras
    for (auto &a : armadura) {
        if (a.getNombre() == nombreItem) {
            a.aplicarEfecto(heroe);
            return;
        }
    }
    // Buscar en armas
    for (auto &arma : arma) {
        if (arma.getNombre() == nombreItem) {
            arma.aplicarEfecto(heroe);
            return;
        }
    }
    cout << "¡Ítem no encontrado!" << endl;
}


