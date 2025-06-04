//
// Created by majo on 26/05/2025.
//
#define GLIBCXX_USE_FLOAT128 0
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
bool Inventario::agregarPocion(const Pocion& pocion) {
    if (this->pocion.size() + armadura.size() + arma.size() >= capacidadMaxima) {
        return false;
    }
    this->pocion.push_back(pocion);
    return true;
}

bool Inventario::agregarArma(const Arma& arma) {
    if (pocion.size() + armadura.size() + this->arma.size() >= capacidadMaxima) {
        return false;
    }
    this->arma.push_back(arma);
    return true;
}
bool Inventario::agregarArmadura(const Armadura& armadura) {
    if (pocion.size() + this->armadura.size() + arma.size() >= capacidadMaxima) {
        return false;
    }
    this->armadura.push_back(armadura);
    return true;
}


void Inventario::mostrarInventario() {
    //pociones
    cout<<"Pociones:"<<endl;
    if (pocion.empty()) {
        cout<<"No hay pociones"<<endl;
    }else {
        for (size_t i = 0; i < this->pocion.size(); i++) {
            cout<<"pociones:\n";
            cout<<"-"<<pocion[i].getNombre()<<endl;  //pocion[i].getName-->lo posiciona
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
        if (p.getNombre() == nombreItem) {
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
void* Inventario::buscarItemPorNombre(const string& nombre) {
    for (auto& p : pocion) {
        if (p.getNombre() == nombre) return &p;
    }
    for (auto& a : armadura) {
        if (a.getNombre() == nombre) return &a;
    }
    for (auto& ar : arma) {
        if (ar.getNombre() == nombre) return &ar;
    }
    return nullptr; // apreendi este metodo a las malas, sorve por si no se encuentra nada
}
bool Inventario::esPocion(void* item) {
    for (auto& p : pocion) {
        if (&p == item) return true;
    }
    return false;
}

bool Inventario::esArmadura(void* item) {
    for (auto& a : armadura) {
        if (&a == item) return true;
    }
    return false;
}

bool Inventario::esArma(void* item) {
    for (auto& ar : arma) {
        if (&ar == item) return true;
    }
    return false;
}

void Inventario::eliminarArma(const Arma &a) {
    for (auto it = arma.begin(); it != arma.end(); ++it) {
        if (it->getNombre() == a.getNombre()) {
            arma.erase(it);
            return;
        }
    }
}
void Inventario::eliminarArmadura(const Armadura& arm) {
    for (auto it = armadura.begin(); it != armadura.end(); ++it) {
        if (it->getNombre() == arm.getNombre()) {
            armadura.erase(it);
            return;
        }
    }
}
void Inventario::eliminarPocion(const Pocion& p) {
    for (auto it = pocion.begin(); it != pocion.end(); ++it) {
        if (it->getNombre() == p.getNombre()) {
            pocion.erase(it);
            return;
        }
    }
}
bool Inventario::existeItem(const std::string &nombre) const {
    for (const auto &p : pocion) {
        if (p.getNombre() == nombre) return true;
    }
    for (const auto &a : armadura) {
        if (a.getNombre() == nombre) return true;
    }
    for (const auto &ar : arma) {
        if (ar.getNombre() == nombre) return true;
    }
    return false;
}

