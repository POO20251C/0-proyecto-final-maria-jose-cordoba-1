//
// Created by majo on 27/05/2025.
//
#define _GLIBCXX_USE_FLOAT128 0
#ifndef JUEGO_H
#define JUEGO_H
#include <vector>
#include<memory>
#include"Mazmorra.h"
#include"Score.h"
#include"Heroe.h"
#include"Inventario.h"
#include"Arma.h"
#include"Armadura.h"
#include"Pocion.h"

using namespace std;

class Juego {
private:
    Mazmorra mazmorra;
    std::vector<Score> scores;
    vector<unique_ptr<Heroe>> heroes;
    //std::vector<Heroe> heroes;
    std::vector<Heroe*>seleccionados;
    std::vector<Pocion> todasPociones;
    std::vector<Arma> todasArmas;
    std::vector<Armadura> todasArmaduras;
    Inventario inventarioequipo;
    Inventario inventarioTotal;

public:
    Juego();
    explicit Juego(const std::vector<Sala>& salas);
    ~Juego()=default; //no tieen nada dentro

    //metodos
    void iniciar();
    void seleccionarHeroes(); //al parecer no estaba devolviendo eso en nada tons obvio no pasaba nada 😭😭😭
    void mostrarTop5()const;
    void cargarScores();
    void guardarScores()const;
    static void mostrarMenu(); //estos no estan en elUML pero la  verdad me salte que debia agregarlos perdon
    void cargarHeroes();
    void cargarItems();
    void elegirItems(); //la verdad me ha tocado agregar muchas cosas yo no era consicnete de todo lo q me faltaba peor porq como antes no me corria puesss no sabia q funcionaba y q no
                        // me falataba agregar un poco cosas 😭😭
    std::vector<Heroe*>escogerHeroes(); //{
      // return seleccionados;
    //}; //es mas facil de leer para el codigo !averiguar porqie¡

};
#endif //JUEGO_H
