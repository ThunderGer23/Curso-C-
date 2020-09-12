//
// Created by thunderger on 11/08/20.
//

#include "Componente.h"

Componente::Componente(string _Marca, string _Color, string _Modelo,
                       string _Descripcion, string _Conectividad, int _NumPuertUSB,
                       int _NumPuertAux, string _Pot, string _Compatibilidad, float _Precio)
        :Electronico( _Marca, _Color, _Modelo, _Descripcion){
    Conectividad = _Conectividad;
    NumPuertUSB = _NumPuertUSB;
    NumPuertAux = _NumPuertAux;
    Pot = _Pot;
    Compatibilidad = _Compatibilidad;
    Precio = _Precio;
}
string Componente::getConectividad() {
    return Conectividad;
}
int Componente::getNumPuertUSB() {
    return NumPuertUSB;
}
int Componente::getNumPuertAux() {
    return NumPuertAux;
}
string Componente::getPot() {
    return Pot;
}
string Componente::getCompativilidad() {
    return Compatibilidad;
}
void Componente::setConectividad(string _Conectividad) {
    Conectividad = _Conectividad;
}
void Componente::setNumPuertUSB(int _NumPuertUSB) {
    NumPuertUSB = _NumPuertUSB;
}
void Componente::setNumPuertAux(int _NumPuertAux) {
    NumPuertAux = _NumPuertAux;
}
void Componente::setPot(string _Pot) {
    Pot = _Pot;
}
void Componente::setCompatibilidad(string _Compatibilidad) {
    Compatibilidad = _Compatibilidad;
}

float Componente::getPrecio() {
    return Precio;
}

void Componente::setPrecio(float _Precio) {
    Precio = _Precio;
}