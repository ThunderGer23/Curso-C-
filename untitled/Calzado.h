//
// Created by thunderger on 11/08/20.
//

#ifndef UNTITLED_CALZADO_H
#define UNTITLED_CALZADO_H

#include <iostream>
#include "Ropa.h"
using namespace std;
class Calzado: public Ropa{
private:
    string Color;
    string CorteExterior;
    string CorteInterior;
    string TipoSuela;
public:
    Calzado(string, string,float, string, string, string, string);
    string getColor();
    string getCortExt();
    string getCortInt();
    string getTipSue();
    void setColor(string);
    void setCortExt(string);
    void setCortInt(string);
    void setTipSue(string);
};

#endif //UNTITLED_CALZADO_H