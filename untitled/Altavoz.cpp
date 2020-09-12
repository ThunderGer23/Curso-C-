//
// Created by thunderger on 11/08/20.
//

#include "Altavoz.h"

Altavoz::Altavoz(string _Marca, string _Color, string _Modelo, string _Descripcion, string _Conectividad, int _NumPuertoUSB, int _NumPuertAux, string _Pot, string _Compatibilidad, float _Precio, bool _Tipo):
        Componente(_Marca, _Color, _Modelo, _Descripcion, _Conectividad, _NumPuertoUSB, _NumPuertAux, _Pot, _Compatibilidad, _Precio){
    Tipo = _Tipo;
}
bool Altavoz::getTipo() {
    return Tipo;
}
void Altavoz::setTipo(bool _Tipo) {
    Tipo = _Tipo;
}