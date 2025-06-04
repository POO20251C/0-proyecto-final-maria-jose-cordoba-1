//
// Created by majo on 20/05/2025.
//
#define _GLIBCXX_USE_FLOAT128 0
#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>


using namespace std;
class Personaje {
protected:
    std::string nombre;
    int salud;
    int suerte;
    int ataque;
    int defensa;
    int velocidad;

public:
    Personaje();
    Personaje(const std::string& nombre,int salud, int suerte, int ataque, int defensa, int velocidad);
    //getters
    std::string getNombre()const;
    int getSalud();
    int getSuerte();
    int getAtaque();
    int getDefensa();
    int getVelocidad();

    //setters
    virtual void setNombre(const std::string& nombre);
    void setSalud(int salud);
    void setSuerte(int suerte);
    void setAtaque(int ataque);
    void setDefensa(int defensa);
    void setVelocidad(int velocidad);

    //metodos
    void atacar(Personaje& enemigo);   //el & es porque asi se granatiza que se haga el cambio cuando se reciba el daño al ptro personaje
    void recibirAtaque(int ataqueEnemigo);
    int calcularDanoRecibido(int ataqueEnemigo);
    bool estaVivo() const; //me toco agregarlo proq nunca prepare bien el metood batalla y duhh no puede seguir sin saber si el heroe esta vivo o q

};



#endif //PERSONAJE_H
