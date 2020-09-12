//
// Created by thunderger on 11/08/20.
//

#ifndef UNTITLED_ZAPATOS_H
#define UNTITLED_ZAPATOS_H

#include <iostream>
#include "Calzado.h"

using namespace std;

class Zapatos: public Calzado{
private:
    string TipoZapato;
public:
    Zapatos(string, string, float, string, string, string, string, string);
    string getTipZa();
    void setTipZa(string);
};

#endif //UNTITLED_ZAPATOS_H