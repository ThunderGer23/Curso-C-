//
// Created by thunderger on 11/08/20.
//

#ifndef UNTITLED_PANTALON_H
#define UNTITLED_PANTALON_H

#include <iostream>
#include "Ropa.h"
using namespace std;
class Pantalon: public Ropa {
private:
    string Tipo;
    string DamCab;
public:
    Pantalon(string, string, float, string, string);
    string getTipo();
    string getDamCab();
    string setTipo(string);
    string setDamCab(string);
};
#endif //UNTITLED_PANTALON_H