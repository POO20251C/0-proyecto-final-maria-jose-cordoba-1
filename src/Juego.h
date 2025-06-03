//
// Created by majo on 27/05/2025.
//

#ifndef JUEGO_H
#define JUEGO_H
#include <vector>
#include"Mazmorra.h"
#include"Score.h"
#include"Heroe.h"
#include"Inventario.h"

using namespace std;

class Juego {
private:
    Mazmorra mazmorra;
    std::vector<Score> scores;
    std::vector<Heroe> heroes;
    std::vector<Heroe*>seleccionados;
    Inventario inventarioequipo;

public:
    Juego();
    explicit Juego(const std::vector<Sala>& salas);
    ~Juego()=default; //no tieen nada dentro

    //metodos
    void iniciar();
    //void escogerHeroes();
    void mostrarTop5()const;
    void cargarScores();
    void guardarScores()const;
    static void mostrarMenu(); //estos no estan en elUML pero la  verdad me salte que debia agregarlos perdon
    void cargarHeroes();
    void cargarItems();
    std::vector<Heroe*>escogerHeroes(); //{
      // return seleccionados;
    //}; //es mas facil de leer para el codigo !averiguar porqie¡

};
#endif //JUEGO_H
