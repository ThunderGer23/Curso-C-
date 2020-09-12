//
// Created by thunderger on 11/08/20.
//

#include "Falda.h"

Falda::Falda(string _Marca, string _Tam, float _Precio, string _Modelo):Ropa(_Marca, _Tam, _Precio) {
    Modelo = _Modelo;
}

string Falda::getModelo() {
    return Modelo;
}

string Falda::setModelo(string _Modelo) {
    Modelo = _Modelo;
}