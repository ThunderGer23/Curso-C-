//
// Created by thunderger on 11/08/20.
//

#include "Calzado.h"

Calzado::Calzado(string _Marca, string _Tam,float _Pre, string _Color, string _CortExt, string _CortInt, string _TipSue)
        :Ropa(_Marca, _Tam, _Pre){
    Color = _Color;
    CorteExterior = _CortExt;
    CorteInterior = _CortInt;
    TipoSuela = _TipSue;
}
string Calzado::getColor() {
    return Color;
}
string Calzado::getCortExt() {
    return CorteExterior;
}
string Calzado::getCortInt() {
    return CorteInterior;
}
string Calzado::getTipSue() {
    return TipoSuela;
}
void Calzado::setColor(string _Color) {
    Color = _Color;
}
void Calzado::setCortExt(string _CortExt) {
    CorteExterior = _CortExt;
}
void Calzado::setCortInt(string _CortInt) {
    CorteInterior = _CortInt;
}
void Calzado::setTipSue(string _TipSue) {
    TipoSuela = _TipSue;
}