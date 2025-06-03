#include <iostream>
#include "Heroe.h"
#include "Villano.h"
#include "Inventario.h"
#include"Arma.h"
#include"Armadura.h"
#include"Sala.h"
#include"Juego.h"
#include"Pocion.h"

using namespace std;


int main() {
//crear personaje

Heroe h1("Mandragora",100,50,90,60,45 );
Heroe h2("Cálamo",100,35,80,75,60 );
Heroe h3("Belladona",100,60,80,55,60 );
Heroe h4("Ginseng",100,80,50,70,50 );
Heroe h5("Artemisa",100,60,60,70,20 );
Heroe h6("Valeriana",100,70,20,95,60 );

//villano

Villano Vil1("Sistrurus","Soldado",100,20,40,35,20 ); //S1
Villano Vil2("Vipera","Soldado",100,20,40,35,25 ); //S2
Villano Vil3("Cerastes","Soldado",100,25,45,40,30 ); //S3
Villano Vil4("Atheris","Soldado",100,30,50,50,30 ); //S3
Villano Vil5("Hydrophis","Soldado",100,30,53,50,35 ); //S4
Villano Vil6("Calloselasma","Soldado",100,33,55,50,35 ); //s5
Villano Vil7("Pseudonaja","Soldado",100,35,55,55,35 ); //S6
Villano Vil8("Bothrops","Soldado",100,35,55,55,35); //S6
Villano Vil9("Dispholidus","Soldado",100,40,55,55,30 ); //S7
Villano Vil10("Echis","Soldado",100,40,55,55,40 ); //S7
Villano Vil11("Naja","Soldado",100,40,55,55,40 ); //S8
Villano Vil12("DeathAdder","Minijefe",100,45,58,55,40 );//S8
Villano Vil13("Bushmaster","Minijefe",100,50,60,55,40 ); //S9
Villano Vil14("Krait","Minijefe",100,50,60,60,40 ); //S9
Villano Vil15("Mamba","Jefe",100,60,70,70,60 );//S10

// cout << "¡Comienza el combate!\n";
// cout << "Salud inicial del héroe: " << h1.getSalud() << "\n";

Inventario inventario;

//pociones --> 17
vector<Pocion>pociones= {
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
for (auto i : pociones) {
inventario.agregarPocion(i);
}

//Armas 17
vector<Arma> armas={
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
for (auto i : armas) {
inventario.agregarArma(i);
}

//Aramadura 16
vector<Armadura> armaduras={
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
for (auto i : armaduras) {
inventario.agregarArmadura(i);
}

//SALAS
//vecotres para indicar donde va cada uno
vector<Villano*> villanosSala1 = { &Vil1 };
vector<Villano*> villanosSala2 = { &Vil2};
vector<Villano*> villanosSala3 = { &Vil3,&Vil4 };
vector<Villano*> villanosSala4 = { &Vil5};
vector<Villano*> villanosSala5 = { &Vil6};
vector<Villano*> villanosSala6 = { &Vil7,&Vil8 };
vector<Villano*> villanosSala7 = { &Vil9,&Vil10 };
vector<Villano*> villanosSala8 = { &Vil11,&Vil12};
vector<Villano*> villanosSala9 = { &Vil13,&Vil14 };
vector<Villano*> villanosSala10 = { &Vil15};

//salas
Sala s1("Sala de Iniciación",1,villanosSala1);
Sala s2("Sala de la Garra Fría",2,villanosSala2 );
Sala s3("Sala de los Acechadores",3,villanosSala3);
Sala s4("Sala Abisal",4,villanosSala4);
Sala s5("Sala de la Jungla Oculta",5,villanosSala5);
Sala s6("Sala de los Espejismos ",6,villanosSala6);
Sala s7(" Sala de la Sangre",7,villanosSala7);
Sala s8("Sala del Tóxico Real",8,villanosSala8);
Sala s9("Sala del Silencio Letal ",9,villanosSala9);
Sala s10("Sala del Fin",10, villanosSala10);

    std::vector<Sala> salas = {s1, s2, s3, s4, s5, s6, s7, s8, s9, s10};

//Juego
    Juego juego(salas);

    juego.iniciar();

juego.cargarScores();

bool jugando=true;
while (jugando) {
    juego.mostrarMenu();

    int opcion;
    cout<<"Ingrese una opcion:";
    cin>>opcion;

    switch (opcion) {
        case 1: {
            vector<Heroe*> heroesElegidos=juego.escogerHeroes();
            break;
        }
        case 2: {
            juego.iniciar();
            break;
        }
        case 3:{
            juego.mostrarTop5();
            break;
        }
        case 4: {
            cout<<"Gracias por jugar:)!"<<endl;
            jugando=false;
            break;
        }
        default:{
            cout<<"Opcion no valida!"<<endl;
            cin.clear();
            break;
        }
    }
}
    //score
    //return 0;
}




// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
// Also, you can try interactive lessons for CLion by selecting
// 'Help | Learn IDE Features' from the main menu.

