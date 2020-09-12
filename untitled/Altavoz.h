//
// Created by thunderger on 11/08/20.
//

#ifndef UNTITLED_ALTAVOZ_H
#define UNTITLED_ALTAVOZ_H

#include <iostream>
#include "Componente.h"
using namespace std;

class Altavoz: public Componente{
private:
    bool Tipo;
public:
    Altavoz(string, string, string, string , string, int, int, string, string, float, bool );
    void setTipo(bool );
    bool getTipo();
};

#endif //UNTITLED_ALTAVOZ_H