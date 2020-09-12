//
// Created by thunderger on 11/08/20.
//

#ifndef UNTITLED_ELECTRONICO_H
#define UNTITLED_ELECTRONICO_H

#include <iostream>
using namespace std;
class Electronico{
private:
    string Marca;
    string Color;
    string Modelo;
    string Descripcion;
public:
    Electronico(string, string, string, string);
    string getMarca();
    string getColor();
    string getModelo();
    string getDescripcion();
    void setMarca(string);
    void setColor(string);
    void setModelo(string);
    void setDescripcion(string);
};

#endif //UNTITLED_ELECTRONICO_H