//
// Created by thunderger on 11/08/20.
//

#include "Pantalon.h"

Pantalon::Pantalon(string _Marca, string _Tam, float _Precio, string _Tipo, string _DamCab):Ropa(_Marca, _Tam, _Precio) {
    Tipo = _Tipo;
    DamCab = _DamCab;
}
string Pantalon::getTipo() {
    return Tipo;
}

string Pantalon::getDamCab() {
    return DamCab;
}

string Pantalon::setTipo(string _Tipo) {
    Tipo = _Tipo;
}
string Pantalon::setDamCab(string _DamCab) {
    DamCab = _DamCab;
}