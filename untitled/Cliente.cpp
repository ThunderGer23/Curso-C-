//
// Created by cuand on 16/8/2020.
//

#include "Cliente.h"

Cliente::Cliente(string _nombre, string _apellido_paterno, string _apellido_materno,
                 string _correo, string _celular,string _calle, int _num_int,
                 int _num_ext, string _Ciudad, string _contra):Persona(_nombre, _apellido_paterno,_apellido_paterno, _correo, _celular) {
    calle = _calle;
    num_int = _num_int;
    num_ext = _num_ext;
    Ciudad = _Ciudad;
    contra = _contra;
}

string Cliente::getCalle() {
    return calle;
}

void Cliente::setCalle(string _calle) {
    calle = _calle;
}

int Cliente::getNumInt() {
    return num_int;
}

void Cliente::setNumInt(int _num_int) {
    num_int = _num_int;
}

int Cliente::getNumExt() {
    return num_ext;
}

void Cliente::setNumExt(int _num_ext) {
    num_ext = _num_ext;
}

string Cliente::getCiudad() {
    return Ciudad;
}

void Cliente::setCiudad(string _Ciudad) {
    Ciudad = _Ciudad;
}

string Cliente::getContra(){
    return contra;
}

void Cliente::setContra(string _contra){
    contra = _contra;
}