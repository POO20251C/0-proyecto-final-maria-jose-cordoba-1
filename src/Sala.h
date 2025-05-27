//
// Created by majo on 26/05/2025.
//

#ifndef SALA_H
#define SALA_H
#include<string>
#include<vector>
#include"Villano.h"
#include"Heroe.h"
 using namespace std;


class Sala {

private:
 string tipo;
 int numeroSala;
 vector<Villano*> VillanosAsignados; //el vector es porque en algunas salas quiero q haya mas de 1 villano

 public:
 Sala();
 Sala(const string &tipo,int numeroSala, const vector <Villano*> &villanos);
 //getters
 string getTipo()const ;
 int getNumeroSala() const;
 vector<Villano*> getVillanos() const;

 //setters
 void setTipo(const string& tipo); //siemore uso el & para referenciar es la llave
 void setNumeroSala(int numeroSala);
 void agregarVillano(Villano* villano);

 //Metodos
 void batalla(vector<Heroe*> &heroes);
 void calcularDanoHeroe(Heroe& herido);
 void calcularDanoVillano(Villano& heridoEnemigo);
 void regaloEspecial(vector<Heroe*> &heroes);
 bool verificarFinBatalla(const vector<Heroe*> &heroes);
 bool avanzar();
 void terminarJuego();


};



#endif //SALA_H
