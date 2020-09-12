//
// Created by thunderger on 11/08/20.
//

#include "Tenis.h"

Tenis::Tenis(string _Marca, string _Tam, float _Pre, string _Color, string _CortExt, string _CortInt, string _TipSue,
             string _TipTen):Calzado(_Marca, _Tam, _Pre, _Color, _CortExt, _CortInt, _TipSue) {
    TipoTenis = _TipTen;
}
string Tenis::getTipoTenis() {
    return TipoTenis;
}
void Tenis::setTipoTenis(string _TipoTen) {
    TipoTenis = _TipoTen;
}