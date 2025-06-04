//
// Created by majo on 27/05/2025.
//
#define _GLIBCXX_USE_FLOAT128 0
#ifndef SCORE_H
#define SCORE_H
#include<string>
using namespace std;

class Score {
private:
    string usuario;
    string fecha;
    string hora;
    int salaMaxSuperada;
    int saludPerdida;

public:
    Score();
    Score(string usuario, string fecha, string hora, int salaMaxSuperada, int saludPerdida);

    //getters
    [[nodiscard]] string getUsuario()const;
    [[nodiscard]] string getFecha()const;
    [[nodiscard]] string getHora()const;
    [[nodiscard]] int getSalaMaxSuperada()const;
    [[nodiscard]] int getSaludPerdida()const;
    //setters
    void setUsuario(string usuario);
    void setFecha(string fecha);
    void setHora(string hora);
    void setSalaMaxSuperada(int salaMaxSuperada);
    void setSaludPerdida(int saludPerdida);

    void mostrarScore() const;

};



#endif //SCORE_H
