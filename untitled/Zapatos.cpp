//
// Created by thunderger on 11/08/20.
//

#include "Zapatos.h"

Zapatos::Zapatos(string _Marca, string _Tam, float _Pre, string _Color, string _CortExt, string _CortInt, string _TipSue, string _TipZap)
        :Calzado(_Marca, _Tam, _Pre, _Color, _CortExt, _CortInt, _TipSue){
    TipoZapato = _TipZap;
}
string Zapatos::getTipZa() {
    return TipoZapato;
}
void Zapatos::setTipZa(string _TipZap) {
    TipoZapato = _TipZap;
}