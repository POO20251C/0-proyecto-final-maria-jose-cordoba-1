//
// Created by majo on 27/05/2025.
//
#define _GLIBCXX_USE_FLOAT128 0
#ifndef MAZMORRA_H
#define MAZMORRA_H
#include<vector>
#include"Sala.h"
#include"Heroe.h"
#include"Villano.h"
#include"Score.h"

using namespace std;

class Mazmorra {
    private:
    vector<Sala> salas;
    vector<Heroe> heroes;
    vector<Villano> villanos;
    vector<Score> historialScores;
    public:
    Mazmorra(const vector <Sala>& salas);
    ~Mazmorra(); //esa ~ significa aca ponemos un destructorpara liberar memoria

    //metodos
    void recorrerMazmorra(vector<Heroe*>&heroes); //aqui metemos lo de lso regalos epeciales de cada sala
    static void registrarScore(vector<Score>&historialScores, const string &usuario, int salaMaxSuperada, int saludPerdida);//aaa la difernecie de porque aca me toca agregar los paramteros es porq mi clase de score
    //solo me giarda los datos, mas que aca si me toca darle valores su los uso y los necesito
    //fehca y hora no se agregan porq no son parametros en si porqye ya se piden
    //tal vez ahcer vector que recorra los scores eso ahora


};


#endif //MAZMORRA_H
