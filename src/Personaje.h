//
// Created by majo on 20/05/2025.
//

#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>


using namespace std;
class Personaje {
private:
    string nombre;
    int salud;
    int suerte;
    int ataque;
    int defensa;
    int velocidad;

public:
    Personaje();
    Personaje(string nombre,int salud, int suerte, int ataque, int defensa, int velocidad);
    //getters
    string getNombre()const;
    int getSalud();
    int getSuerte();
    int getAtaque();
    int getDefensa();
    int getVelocidad();

    //setters
    void setSalud(int salud);
    void setSuerte(int suerte);
    void setAtaque(int ataque);
    void setDefensa(int defensa);
    void setVelocidad(int velocidad);

    //metodos
    void atacar(Personaje& enemigo);   //el & es porque asi se granatiza que se haga el cambio cuando se reciba el daño al ptro personaje
    void recibirAtaque(int dano);

};



#endif //PERSONAJE_H
