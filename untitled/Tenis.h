//
// Created by thunderger on 11/08/20.
//

#ifndef UNTITLED_TENIS_H
#define UNTITLED_TENIS_H

#include <iostream>
#include "Calzado.h"

using namespace std;

class Tenis: public Calzado{
private:
    string TipoTenis;
public:
    Tenis(string, string, float , string, string, string, string, string);
    string getTipoTenis();
    void setTipoTenis(string);
};

#endif //UNTITLED_TENIS_H