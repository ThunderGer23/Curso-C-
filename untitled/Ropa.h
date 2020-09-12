//
// Created by thunderger on 11/08/20.
//

#ifndef UNTITLED_ROPA_H
#define UNTITLED_ROPA_H
#include <iostream>
using namespace std;
class Ropa{
private:
    string Marca;
    string Tam;
    float Precio;
public:
    Ropa(string, string, float);
    string getMarca();
    string getTam();
    float getPrecio();
    void setMarca(string);
    void setTam(string);
    void setPrecio(float );
};
#endif //UNTITLED_ROPA_H