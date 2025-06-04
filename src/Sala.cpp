//
// Created by majo on 26/05/2025.
//
#define _GLIBCXX_USE_FLOAT128 0
#include<iostream>
#include<limits>
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


//metodo batalla //si me toco partirlos porq me perdi DURISIMO  //este metodo me esta matando pprq no enteindo porq no funciona
bool Sala::batalla(vector<Heroe*>& heroes) {
    // Inventario inventarioHeroes(15);

    cout<<"\nBATALLA ENNN"<<tipo<<"\n"<< "con enemigo:"<<VillanosAsignados[0]->getNombre()<<endl;

    //  if (VillanosAsignados.empty()) {
    //cout << "No hay villano en la sala" << endl;
    //return false; //cambie esto ahora es con bool por lo de mazmorra y los scores tons se agrega false y true
    //}


    while (true) {
        //srive como para una clase de "bucle"

        for (Heroe* heroe : heroes) {
            //turnos
            if (heroe->getSalud()>0) {
                cout<<"\nTurno de"<<heroe->getNombre()<<"\n";
                cout<<"Elige \n1. Atacar!\n2.Usar Item\n"; //hice como unas clases de opciones para el jugador durante la battala
                int opcion;
                cin>>opcion;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //me toco agregarleesto

                if (opcion == 1) {
                    // Villanos vivos
                    cout << "¿A qué villano deseas atacar?\n";
                    for (int i = 0; i < VillanosAsignados.size(); ++i) {
                        if (VillanosAsignados[i]->getSalud() > 0) {
                            cout << i + 1 << ". " << VillanosAsignados[i]->getNombre()
                                 << " (Salud: " << VillanosAsignados[i]->getSalud() << ")\n";
                        }
                    }
                    int indice;
                    cin >> indice;
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    indice--; // para q vea tipo vil1 o vil 2

                    if (indice >= 0 && indice < VillanosAsignados.size() && VillanosAsignados[indice]->getSalud() > 0) {
                        heroe->atacar(*VillanosAsignados[indice]);
                    } else {
                        cout << "Villano vencido!!.\n";
                    }
                }else if (opcion==2){

                    heroe->getInventario().mostrarInventario();
                    cout<<"Elige tu item:";
                    string nombreItem;
                    getline(cin>>ws,nombreItem); //busqye y es mejor para leer el nombre completo porq repito mucho la primera palabra jeje:)

                    heroe->usarItem(heroe->getInventario(),nombreItem);
                }
            }
        }

        for (Villano* villano : VillanosAsignados) {
            if (villano->getSalud() > 0) {
                for (Heroe* h : heroes) {
                    if (h->getSalud() > 0) {
                        villano->atacar(*h);
                        cout << villano->getNombre() << " ataca a " << h->getNombre() << "!\n";
                        break; // un villano ataca a un héroe por turno
                    }
                }
            }
        } //if (VillanosAsignados[0]->getSalud()>0) {
        //buscar que queda vivo jeje
        // for (Heroe* h : heroes) {
        //  if (h->getSalud()>0) {
        // VillanosAsignados[0]->atacar(*h);
        //  cout <<VillanosAsignados[0]->getNombre()<<"ataca a"<<h->getNombre()<<"!\n";

        //ver si ganasteee
        bool todosMuertos = true;
        for (Villano* v : VillanosAsignados) {
            if (v->getSalud() > 0) {
                todosMuertos = false;
                break;
            }
        }
        if (todosMuertos) {
            cout << "\n¡Ganasteee! Venciste a todos los villanos de la sala\n";
            return true;
        }



        int heroesMuertos=0;
        for (Heroe* hero : heroes) {
            if (hero->getSalud()<=0)heroesMuertos++;
        }
        if (heroesMuertos>=2) {
            cout <<"\nGame over ;(";
            terminarJuego();
            return false; //false --> pierdes
        }
        break;
    }
    return false;
}



//metodo fin batalla
bool Sala::verificarFinBatalla(const vector<Heroe*>& heroes) {
    bool todosVillanosMuertos = true;
    for (Villano* v : VillanosAsignados) {
        if (v->getSalud() > 0) {
            todosVillanosMuertos = false;
            break;
        }
    }
    if (todosVillanosMuertos) return true;

    int heroesMuertos=0;
    for (Heroe* heroe : heroes) {
        if (heroe->getSalud()<=0)heroesMuertos++;
    }
    return (heroesMuertos>=2);
}
//metodo terminar juego
void Sala::terminarJuego() {
    cout<<"\nHas perdido el juego ha terminado";
    //exit(0);
}