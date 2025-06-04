//
// Created by majo on 26/05/2025.
//
#define GLIBCXX_USE_FLOAT128 0
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
if (VillanosAsignados.empty()) {
        cout << "No hay villano en la sala." << endl;
        return false;
    }

    cout << "\nBATALLA EN " << tipo << "\nCon enemigo: " << VillanosAsignados[0]->getNombre() << endl;

    int turno = 0;
    int totalHeroes = heroes.size();
    int turnoVillano = -1; // empezamos en -1 para que el primero sea 0 al sumar 1

    while (true) {
        Heroe* heroeActual = heroes[turno];

        if (heroeActual->getSalud() > 0) {
            cout << "\nTurno de " << heroeActual->getNombre() << "\n";
            cout << "Elige: \n1. ¡Atacar!\n2. Usar ítem\n";
            int opcion;
            cin >> opcion;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (opcion == 1) {
                cout << "A qué villano deseas atacar?\n";
                for (int i = 0; i < VillanosAsignados.size(); ++i) {
                    if (VillanosAsignados[i]->getSalud() > 0) {
                        cout << i + 1 << ". " << VillanosAsignados[i]->getNombre()
                             << " (Salud: " << VillanosAsignados[i]->getSalud() << ")\n";
                    }
                }
                int indice;
                cin >> indice;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                indice--;

                if (indice >= 0 && indice < VillanosAsignados.size() && VillanosAsignados[indice]->getSalud() > 0) {
                    heroeActual->atacar(*VillanosAsignados[indice]);
                } else {
                    cout << "Villano inválido o ya vencido.\n";
                }
            } else if (opcion == 2) {
                heroeActual->getInventario().mostrarInventario();
                cout << "Elige tu ítem: ";
                string nombreItem;
                getline(cin >> ws, nombreItem);
                heroeActual->usarItem(heroeActual->getInventario(), nombreItem);

                cout << "¿A qué villano deseas atacar?\n";     //porque me hacia falta q ataca tambien con el item aish
                for (int i = 0; i < VillanosAsignados.size(); ++i) {
                    if (VillanosAsignados[i]->getSalud() > 0) {
                        cout << i + 1 << ". " << VillanosAsignados[i]->getNombre()
                             << " (Salud: " << VillanosAsignados[i]->getSalud() << ")\n";
                    }
                }
                int indiceVillano;
                cin >> indiceVillano;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                indiceVillano--;

                if (indiceVillano >= 0 && indiceVillano < VillanosAsignados.size() && VillanosAsignados[indiceVillano]->getSalud() > 0) {
                    heroeActual->atacar(*VillanosAsignados[indiceVillano]);
                } else {
                    cout << "Villano inválido o ya vencido.\n";
                }
            }
            }

            // Verificar si ganaste
            bool todosVillanosMuertos = true;
            for (Villano* v : VillanosAsignados) {
                if (v->getSalud() > 0) {
                    todosVillanosMuertos = false;
                    break;
                }
            }
            if (todosVillanosMuertos) {
                cout << "\n¡Ganasteee! Venciste a todos los villanos de la sala\n";
                return true;
            }

            // Turno de villano
            int vivos = 0;
            for (Villano* v : VillanosAsignados) {
                if (v->getSalud() > 0) vivos++;
            }

            if (vivos > 0) {
                for (int i = 0; i < VillanosAsignados.size(); ++i) {
                    turnoVillano = (turnoVillano + 1) % VillanosAsignados.size();
                    Villano* villano = VillanosAsignados[turnoVillano];
                    if (villano->getSalud() > 0) {
                        villano->atacar(*heroeActual);
                        cout << villano->getNombre() << " ataca a " << heroeActual->getNombre() << "!!\n";
                        break;
                    }
                }
            }

            // Verificar si perdiste
            int heroesMuertos = 0;
            for (Heroe* hero : heroes) {
                if (hero->getSalud() <= 0) heroesMuertos++;
            }
            if (heroesMuertos >= 2) {
                cout << "\nGame over ;(";
                terminarJuego();
                return false;
            }
        turno = (turno + 1) % totalHeroes;
        }
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