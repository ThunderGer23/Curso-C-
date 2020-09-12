//
// Created by thunderger on 11/08/20.
//

#include "Televisor.h"

Televisor::Televisor(string _Marca, string _Color, string _Modelo, string _Descriptcion, float _Tam, float _Precio, string _Def)
        :Electronico( _Marca, _Color, _Modelo, _Descriptcion) {
    Tam = _Tam;
    Precio = _Precio;
    Def = _Def;
}
void Televisor::Encender() {
    cout<<"El televisor "<<getMarca()<<" esta encendido"<<endl;
}
void Televisor::Apagar() {
    cout<<"Apagando televisor"<<getMarca()<<endl;
}
void Televisor::CamCan() {
    cout<<"Cambiando Canal"<<getMarca()<<endl;
}
float Televisor::getTam() {
    return Tam;
}
void Televisor::setTam(float _Tam) {
    Tam = _Tam;
}
float Televisor::getPrecio() {
    return Precio;
}
void Televisor::setPrecio(float _Precio) {
    Precio = _Precio;
}
string Televisor::getDef() {
    return Def;
}
void Televisor::setDef(string _Def) {
    Def = _Def;
}