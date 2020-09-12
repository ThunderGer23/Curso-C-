//
// Created by thunderger on 11/08/20.
//

#ifndef UNTITLED_FALDA_H
#define UNTITLED_FALDA_H

#include <iostream>
#include "Ropa.h"

using namespace std;

class Falda: public Ropa {
private:
    string Modelo;
public:
    Falda(string, string, float,string);
    string getModelo();
    string setModelo(string);
};

#endif //UNTITLED_FALDA_H