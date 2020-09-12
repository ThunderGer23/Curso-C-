//
// Created by thunderger on 11/08/20.
//

#ifndef UNTITLED_COMPONENTE_H
#define UNTITLED_COMPONENTE_H

#include <iostream>
#include "Electronico.h"
using namespace std;
class Componente: public Electronico{
private:
    string Conectividad;
    int NumPuertUSB;
    int NumPuertAux;
    string Pot;
    string Compatibilidad;
    float Precio;
public:
    Componente(string, string, string, string, string, int, int, string, string, float);
    string getConectividad();
    int getNumPuertUSB();
    int getNumPuertAux();
    string getPot();
    string getCompativilidad();
    float getPrecio();
    void setConectividad(string);
    void setNumPuertUSB(int);
    void setNumPuertAux(int);
    void setPot(string);
    void setCompatibilidad(string);
    void setPrecio(float );
};

#endif //UNTITLED_COMPONENTE_H