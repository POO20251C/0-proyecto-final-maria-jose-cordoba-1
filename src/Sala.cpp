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
void Sala::batalla(vector<Heroe*>& heroes) {
    if (VillanosAsignados.empty()) {
        cout<<"No hay villano en la sala"<<endl;
        return;
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
                    cin>>nombreItem;

                    heroe->usarItem(inventarioHeroes,nombreItem);
                }
                if (VillanosAsignados[0]->getSalud()<=0) {
                    cout<<"\nGanasteeee venciste a"<<VillanosAsignados[0]->getNombre()<<"\n";
                    return; //termina la batalla :)
                }
            }
        }
        if (VillanosAsignados[0]->getSalud()>0) {
            vector<Heroe*> heroes;  //buscar que queda vivo jeje
            for (Heroe* heroe : heroes) {
                if (heroe->getSalud()>0) {
                    VillanosAsignados[0]->atacar(*heroe);
                    cout <<VillanosAsignados[0]->getNombre()<<"ataca a"<<heroe->getNombre()<<"!\n";

                    int heroesMuertos=0;
                    for (Heroe* heroe : heroes) {
                        if (heroe->getSalud()<=0)heroesMuertos++;
                    }
                    if (heroesMuertos>=2) {
                        cout <<"\nGame over ;(";
                        terminarJuego();
                        return;
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