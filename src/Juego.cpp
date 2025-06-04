//
// Created by majo on 27/05/2025.
//
#define _GLIBCXX_USE_FLOAT128 0
#include<iostream>
#include<memory>
#include "Juego.h"
#include"Heroe.h"
#include"Mazmorra.h"
#include"Arma.h"
#include"Armadura.h"
#include"Pocion.h"

using namespace std;
Juego::Juego(const vector<Sala>& salas) : mazmorra(salas) {
    cargarHeroes();
    cargarItems();
    cargarScores();
}

//metodos
void Juego::cargarHeroes() {
    heroes.clear();
    heroes.push_back(make_unique<Heroe>("Mandragora", 100, 50, 90, 60, 45));
    heroes.push_back(make_unique<Heroe>("Cálamo", 100, 35, 80, 75, 60));
    heroes.push_back(make_unique<Heroe>("Belladona", 100, 60, 80, 55, 60));
    heroes.push_back(make_unique<Heroe>("Ginseng", 100, 80, 50, 70, 50));
    heroes.push_back(make_unique<Heroe>("Artemisa", 100, 60, 60, 70, 20));
    heroes.push_back(make_unique<Heroe>("Valeriana", 100, 70, 20, 95, 60));
}

    //heroes={
     //   Heroe("Mandragora",100,50,90,60,45 ),
       // Heroe("Cálamo",100,35,80,75,60 ),
      //  Heroe("Belladona",100,60,80,55,60 ),
       // Heroe("Ginseng",100,80,50,70,50 ),
       // Heroe("Artemisa",100,60,60,70,20 ),
       // Heroe("Valeriana",100,70,20,95,60 ),

void Juego::seleccionarHeroes() {
    seleccionados = escogerHeroes();
}

void Juego::cargarItems() {
    inventarioTotal=Inventario(50);
    inventarioequipo=Inventario(15);
    vector<Pocion>pociones={
            Pocion ("Poción de Vida", 50, 0),
            Pocion ("Elixir fortuna", 0, 30),
            Pocion ("Brebaje vital", 30, 20),
            Pocion ("Tonico del destino", 10, 20),
            Pocion ("Suero de energía", 40, 0),
            Pocion ("Suerte ciega", 0, 50),
            Pocion ("Infusion curativa", 25, 10),
            Pocion ("Agua del oráculo", 15, 25),
            Pocion ("Elixir brillante", 20, 15),
            Pocion ("Té de las etsrellas", 10, 40),
            Pocion ("Nectar de vida", 60, 0),
            Pocion ("Pocion del azar", 20, 30),
            Pocion ("Etracto de esperanza", 35, 10),
            Pocion ("Gotas de suerte", 0, 45),
            Pocion ("Tonico de acero", 55, 5),
            Pocion ("Poción del gruadian", 45, 5),
            Pocion ("Brebaje del valiente", 25, 20),
            };
    vector<Arma> armas = {
        Arma ("Espada del alba", 40, 10),
    Arma ("Martillo Celeste", 45, 8),
    Arma ("Hacha del coloso", 50, 5),
Arma ("Lanza del silencio", 35, 15),
Arma ("Dagas del viento", 25, 10),
Arma ("Arco de sombras", 30, 12),
Arma ("Cuchillas de medianoche", 38, 7),
Arma ("Mega Espada", 42, 13),
Arma ("Maza del titan", 48, 6),
Arma ("Katana del eclipse", 36, 9),
Arma ("Lanza de la Tempestad", 44, 11),
Arma ("Espada del vacio", 50, 0),
Arma ("Aguijon de hielo", 32, 14),
Arma ("Garrote de guerra", 39, 10),
Arma ("Dagas del engaño", 28, 12),
Arma ("Filo del trueno", 47, 5),
Arma ("Escudo", 9, 41),
Arma ("Arma rara",60,50)

};

    vector<Armadura> armaduras = {
        Armadura ("Armadura del guardian", 40),
Armadura ("Coraza de hierro", 35),
Armadura ("Armadura de la luz", 28),
Armadura ("Escamas del dragon", 40),
Armadura ("Armadura del centinela", 33),
Armadura ("Coraza de los Antiguos", 37),
Armadura ("Armadura del cristal sagrado", 26),
Armadura ("Armadura de Guerra Élfica", 32),
Armadura ("Malla del Trueno", 31),
Armadura ("Armadura del Invierno", 29),
Armadura ("Armadura del León Dorado", 36),
Armadura ("Coraza de la Tempestad", 34),
Armadura ("Ala de Acero", 40),
Armadura ("Armadura del Olvido", 39),
Armadura ("Manto de los Titanes ", 38),
Armadura ("Armadura de la Eternidad ", 42),
};
    //this->todasPociones = pociones;
    //this->todasArmas = armas;
    //this->todasArmaduras = armaduras;


   for (auto& pocion : pociones) {inventarioTotal.agregarPocion(pocion);}
    for (auto& arma : armas) {inventarioTotal.agregarArma(arma);}
    for (auto& armadura : armaduras) {inventarioTotal.agregarArmadura(armadura);}

}


void Juego::elegirItems() {
    cout <<"Debes elegir 15 items para tu equipo"<<endl;
    inventarioTotal.mostrarInventario(); // Mostrar todos los ítems disponibles

    int Itemseleccionados = 0;
    //const int max = 15;

    while (Itemseleccionados < 15) {

        cout << "Elige el item #" << (Itemseleccionados + 1) << " (Nombre o \"fin\" para dejar de elegir): ";
        string nombre;
        cin >> nombre;

        if (nombre == "fin") break;

        void* item= inventarioTotal.buscarItemPorNombre(nombre);
        if (!item) {
            cout << "Item no encontrado, intenta otra vez\n";
            continue;
        }

            //total a eqiuipo
        if (inventarioTotal.esPocion(item)) {
            auto* p = (Pocion*)item;
            if (inventarioequipo.agregarPocion(*p)) {
                inventarioTotal.eliminarPocion(*p);
                Itemseleccionados++;
            } else {
                cout << "No se pudo agregar (inventario lleno)\n";
            }
        }
        else if (inventarioTotal.esArmadura(item)) {
            auto* a = (Armadura*)item;
            if (inventarioequipo.agregarArmadura(*a)) {
                inventarioTotal.eliminarArmadura(*a);
                Itemseleccionados++;
            } else {
                cout << "No se pudo agregar (inventario lleno)\n";
            }
        }
        else if (inventarioTotal.esArma(item)) {  //  Usa inventarioTotal, no inventarioequipo
            Arma* ar = (Arma*)item;
            if (inventarioequipo.agregarArma(*ar)) {
                inventarioTotal.eliminarArma(*ar);
                Itemseleccionados++;
            } else {
                cout << "No se pudo agregar (inventario lleno)\n";
            }
        }
    }

    //asignacion
    cout << "¿A qué héroe deseas asignarlo?\n"<<endl;
    inventarioequipo.mostrarInventario();

    for (auto & seleccionado : seleccionados) {
        cout << "Asignando ítems a " << seleccionado->getNombre() << ":" << endl;
        cout << "Elige un ítem (nombre): ";
        string nombreItem;
        cin >> nombreItem;


        void* item = inventarioequipo.buscarItemPorNombre(nombreItem);
        if (!item) {
            cout << "Ítem no disponible." << endl;
            continue;
        }
        if (inventarioequipo.esPocion(item)) {
            auto* p = static_cast<Pocion*>(item);
            seleccionado->getInventario().agregarPocion(*p);
        }
        else if (inventarioequipo.esArma(item)) {
            Arma* a = static_cast<Arma*>(item);
            seleccionado->getInventario().agregarArma(*a);
        }
        else if (inventarioequipo.esArmadura(item)) {
            auto* arm = static_cast<Armadura*>(item);
            seleccionado->getInventario().agregarArmadura(*arm);
        }
    }
}

    void Juego::iniciar() {
        if (seleccionados.empty()) {
            cout << "Primero selecciona héroes (Opción 1)\n";
            return;
        }
        mazmorra.recorrerMazmorra(seleccionados);
    }

void Juego::mostrarTop5()const {
    if (scores.empty()) {
        cout << "No hay puntuaciones registradas aún";
        //return;

    }
    cout<<"top 5 puntuaciones!!:\n";
    int limite=min(5,static_cast<int>(scores.size()));
    for (int i=0;i<limite;i++) {
        cout<<i+1<<"-\n";scores[i].mostrarScore();cout<<"------\n"<<endl;
    }
}
    void Juego::cargarScores() {

    }

    void Juego::guardarScores() const {

    }
    void Juego::mostrarMenu() {
        cout<<"----Menu principal----";
        cout<<"\n1.Escoger Heroes";
        cout<<"\n2.Iniciar partida";
        cout<<"\n3.Mostrar Top 5 scores";
        cout<<"\n4.Salir";
    cout<<"\n-Seleccione una opcion-"<<endl;

    }
    vector<Heroe *> Juego::escogerHeroes() {
        vector<Heroe *> seleccionados;
        constexpr int heroesRequeridos=3;

        cout<<"Para empezar escoge 3 heroes:)";
        for (size_t i=0;i<heroes.size();i++) {
            cout<<i+1<<"."<<heroes[i]->getNombre()<<"\n";
        }

        while (seleccionados.size() < heroesRequeridos) {  // elegir 3 heroessss
            cout << "Ingrese número de héroe " << seleccionados.size() + 1 << ": ";
            int opcion;
            cin >> opcion;


            if (opcion<1 || opcion>static_cast<int>(heroes.size())) {
                cout << "Opcion no valida. Intente de nuevo:) ";
                continue;
            }
            bool yaElegido=false;
            for (const auto& heroes_seleccionado: seleccionados) {
                if (heroes_seleccionado==heroes[opcion-1].get()) { //profe la verdad esto si me ha tocado buscarlo prq no se como arreglar el error de memoria tons hago lo q puedo perdon
                    cout<<"Ya tienes este heroe, intenta otro:)"<<endl;
                    yaElegido=true;
                    break;
                }
            }
            if (!yaElegido) {
                seleccionados.push_back(heroes[opcion-1].get());
                cout<<"¡"<<heroes[opcion-1]->getNombre()<<"\nUnido al equipo!"; //al parecer el get es una funcion que ayuda cuando quiere usar el puntero *
            }
        }
        return seleccionados;
    }






