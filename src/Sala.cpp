//
// Created by majo on 26/05/2025.
//
#include<iostream>
#include "Sala.h"
#include"Heroe.h"
#include "Inventario.h"
#include"Villano.h"

// Constructor
Sala::Sala(const string& tipo, const int nuS, const vector<Villano*> &villanos) {
    this->tipo = tipo;
    this->numeroSala = nuS;
    this->VillanosAsignados = villanos;
}

// getters
string Sala::getTipo() const {
    return tipo;
}

int Sala::getNumeroSala() const {
    return numeroSala;
}

 vector<Villano*> Sala::getVillanos() const {
    return VillanosAsignados;
}

// setters
void Sala::setTipo(const string& tipo) {
    this->tipo = tipo;
}

void Sala::setNumeroSala(const int nuS) {
    this->numeroSala = nuS;
}


//metodos


//metodo batalla //si me toco partirlos porq me perdi DURISIMO
bool Sala::batalla(vector<Heroe*>& heroes) {
    if (VillanosAsignados.empty()) {
        cout<<"No hay villano en la sala"<<endl;
        return false; //cambie esto ahora es con bool por lo de mazmorra y los scores tons se agrega false y true
    }
    Inventario inventarioHeroes(15);
    cout<<"\nBATALLA ENNN"<<tipo<<"\n"<< "con enemigo:"<<VillanosAsignados[0]->getNombre()<<endl;


    while (true) {  //srive como para una clase de "bucle"

        for (Heroe* heroe : heroes) {
            //turnos
            if (heroe->getSalud()>0) {
                cout<<"Turno de"<<heroe->getNombre()<<"\n";
                cout<<"Elige \n1. Atacar!\n2.Usar Item"; //hice como unas clases de opciones para el jugador durante la battala
                int opcion;
                cin>>opcion;

                if (opcion==1) {
                    heroe->atacar(*VillanosAsignados[0]);
                }else {
                    inventarioHeroes.mostrarInventario();
                    cout<<"Elige tu item:";
                    string nombreItem;
                    getline(cin>>ws,nombreItem); //busqye y es mejor para leer el nombre completo porq repito mucho la primera palabra jeje:)

                    heroe->usarItem(inventarioHeroes,nombreItem);
                }
                if (VillanosAsignados[0]->getSalud()<=0) {
                    cout<<"\nGanasteeee venciste a"<<VillanosAsignados[0]->getNombre()<<"\n";
                    return true; //termina la batalla :) //true--> ganas
                }
            }
        }
        if (VillanosAsignados[0]->getSalud()>0) {
            //buscar que queda vivo jeje
            for (Heroe* h : heroes) {
                if (h->getSalud()>0) {
                    VillanosAsignados[0]->atacar(*h);
                    cout <<VillanosAsignados[0]->getNombre()<<"ataca a"<<h->getNombre()<<"!\n";

                    int heroesMuertos=0;
                    for (Heroe* heroe : heroes) {
                        if (heroe->getSalud()<=0)heroesMuertos++;
                    }
                    if (heroesMuertos>=2) {
                        cout <<"\nGame over ;(";
                        terminarJuego();
                        return false; //false --> pierdes
                    }
                    break;
                }
            }
        }
    }
}

//metodo fin batalla
bool Sala::verificarFinBatalla(const vector<Heroe*>& heroes) {
            if (VillanosAsignados[0]->getSalud()<=0)return true;
            int heroesMuertos=0;
            for (Heroe* heroe : heroes) {
                if (heroe->getSalud()<=0)heroesMuertos++;
            }
            return (heroesMuertos>=2);
}
    //metodo terminar juego
void Sala::terminarJuego() {
        cout<<"\nHas perdido el juego ha terminado";
        exit(0);
}