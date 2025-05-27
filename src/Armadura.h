//
// Created by majo on 26/05/2025.
//

#ifndef ARMADURA_H
#define ARMADURA_H
#include<string>


using namespace std;

class Heroe;

class Armadura {
private:
    string nombre;
    int mejoraDefensa;
public:
    Armadura();
    Armadura(string nombre, int mejoraDefensa);
    //getters
    string getNombre()const ;
    int getMejoraDefensa()const ;
//stters
    void setNombre(string nombre);
    void setMejoraDef(int mejoraDefensa);
    //metodo    //antes de segior pequeña explicacion, yo al principio tenia pensado usar herencia,
    void aplicarEfecto(Heroe& h); //puesto que podia hacer una clase item--> arma, etc dentro de inventario porque comparten el metood de aplicarefecto
                    //sij embargo usted(el profe) me recomendo no usarlo y mas bien hacer las clases separadas
                    //le explicacion que encuentro seria que de esta forma es ams senccillo y simple, ademas como cada objeto se usa en disnitos momentos
                    //y con propositos difrentes puede ser mejor

};


#endif //ARMADURA_H
