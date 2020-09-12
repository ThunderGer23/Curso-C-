//
// Created by thunderger on 11/08/20.
//

#ifndef UNTITLED_TELEVISOR_H
#define UNTITLED_TELEVISOR_H

#include <iostream>
#include "Electronico.h"

using namespace std;

class Televisor: public Electronico{
private:
    float Tam;
    float Precio;
    string Def;
public:
    Televisor(string, string, string, string, float, float, string);
    void Encender();
    void Apagar();
    void CamCan();
    float getTam();
    void setTam( float);
    float getPrecio();
    void setPrecio( float);
    string getDef();
    void setDef( string);
};

#endif //UNTITLED_TELEVISOR_H