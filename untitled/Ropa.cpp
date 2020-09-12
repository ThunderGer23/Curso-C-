//
// Created by thunderger on 11/08/20.
//

#include "Ropa.h"

Ropa::Ropa(string _Marca, string _Tam, float _Pre) {
    Marca = _Marca;
    Tam = _Tam;
    Precio = _Pre;
}
string Ropa::getMarca() {
    return Marca;
}
string Ropa::getTam() {
    return Tam;
}
void Ropa::setMarca(string _Marca) {
    Marca = _Marca;
}
void Ropa::setTam(string _Tam) {
    Tam = _Tam;
}

float Ropa::getPrecio() {
    return Precio;
}

void Ropa::setPrecio(float _Precio) {
    Precio = _Precio;
}