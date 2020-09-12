//
// Created by thunderger on 11/08/20.
//

#include "Electronico.h"

Electronico::Electronico(string _Marca, string _Color, string _Modelo, string _Descripcion) {
    Marca = _Marca;
    Color = _Color;
    Modelo = _Modelo;
    Descripcion = _Descripcion;
}
string Electronico::getMarca() {
    return Marca;
}
string Electronico::getColor() {
    return Color;
}
string Electronico::getModelo() {
    return Modelo;
}
string Electronico::getDescripcion() {
    return Descripcion;
}
void Electronico::setMarca(string _Marca) {
    Marca = _Marca;
}
void Electronico::setColor(string _Color) {
    Color = _Color;
}
void Electronico::setModelo(string _Modelo) {
    Modelo = _Modelo;
}
void Electronico::setDescripcion(string _Descripcion) {
    Descripcion = _Descripcion;
}