//
// Created by majo on 27/05/2025.
//
#include<iostream>
#include "Mazmorra.h"
#include"Sala.h"
#include"Inventario.h"
#include"Heroe.h"
#include"Score.h"
#include"Arma.h"
#include"Armadura.h"
Mazmorra::Mazmorra(const vector <Sala>& salas) : salas(salas) {}
Mazmorra::~Mazmorra() = default;

//metodos
void Mazmorra::recorrerMazmorra(vector<Heroe*> &heroes) {
    int salaActual=0;
    int saludInicial=0;

    for (Heroe*& heroe : heroes) {
        saludInicial += heroe->getSalud();
    }
    for (size_t i = 0; i < salas.size(); i++) {
        //recorro las salas
        cout<<"Entrando a la sala: "<<i+1<<endl;
        //al recorrer las salas en algunas tengo regalos epscpieclaes
        if (i==0) { //sala 1--> se guia desde el 0
            cout<<"Muy bien, has pasado la primera sala! tienes la oportunidad de escoger entre un arma o armadura!"<<endl;
            for (Heroe*& heroe : heroes) {
                cout << "Heroe: " << heroe->getNombre() << ", elige una opcion:" << endl;
                cout << "1. Arma" << endl;
                cout << "2. Armadura" << endl;
                int opcion;
                cin >> opcion;
                if (opcion==1) {
                    Arma armaEspecial("Espada de fuego", 30,25);
                    heroe->usarItem(armaEspecial);
                }else if (opcion==2) {
                    Armadura aramduraEspecial("Escudo de Luz",50);
                    heroe->usarItem(aramduraEspecial);
                }

            }
        }
        else if (i==2) {//sala 3
            cout <<"Has derrotado fuertes soldados, por tu valentia recibiras una gran recompensa, cada heroe recibira una arma unica "<<endl; //cambie  suerte por denfesa porq asi engo mis armas perdon :)
            for (Heroe*& heroe : heroes) {
                Arma armaunica("Hacha legendaria",60,50);
//reciben +60 ataque / tamien le baje porq noooooo  mucho AJJJA
                //reciben +50 defensa
                heroe->getInventario()->agregarArma(armaunica);
            }
        }
        else if (i==5) { //sala 6
            cout<<"Has vencido al primer mini jefe, por esta asombrosa azaña tendran una recompensa aliviadora"<<endl;
            for (Heroe*& heroe : heroes) {
                heroe->recuperarSaludCompleta();
            }
        }
        bool resultado=salas[i].batalla(heroes);
        if (!resultado) {
            salaActual=i; //== es comparacion y = es asignacion
            cout<<"Has perdido en la sala: "<<i+1<<endl;
            break;
        }
        salaActual=i+1;
    }
    int saludRestante=0;
    for (Heroe*& heroe : heroes) {
        saludRestante+=heroe->getSalud();
    }
int saludPerdida=saludInicial- saludRestante;
    cout<<"La salud perdida total fue:"<<saludPerdida<<endl;
    cout<<"Ultima sala recorrida: "<<salaActual<<endl;

}

void Mazmorra::registrarScore(vector<Score> &historialScores,const string &usuario, int salaMaxSuperada, int saludPerdida) {
    string fecha;
    cout<<"Ingrese el fecha (YYYY-MM-DD): ";
    cin>>fecha;
    string hora;
    cout<<"Ingrese el hora (HH:MM:SS): ";
    cin>>hora;

    Score nuevoScore(usuario,fecha,hora,salaMaxSuperada, saludPerdida);
    historialScores.push_back(nuevoScore);

    for (int i=0; i<(int)historialScores.size()-1; i++) {
        for (int j=i+1; j<(int)historialScores.size(); j++) {
            if (historialScores[j].getSalaMaxSuperada()>historialScores[i].getSalaMaxSuperada()|| //condicones para que se cumplan si no esoty mal
                (historialScores[j].getSalaMaxSuperada()==historialScores[i].getSalaMaxSuperada()&&
                    historialScores[j].getSaludPerdida() < historialScores[i].getSaludPerdida())
                   ) { swap(historialScores[i], historialScores[j]); }  //swap es una funcion para valga a redundancia swapearlos
                    }
        }
    }



