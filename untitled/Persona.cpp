//
// Created by cuand on 16/8/2020.
//

#include "Persona.h"
Persona::Persona(string _nombre, string _apellido_paterno, string _apellido_materno, string _correo, string _celular) {
    nombre = _nombre;
    apellido_paterno = _apellido_paterno;
    apellido_materno = _apellido_materno;
    correo = _correo;
    celular = _celular;
}

//Getters&Setters
string Persona::getNombre() {
    return nombre;
}

void Persona::setNombre(string _nombre) {
    nombre = _nombre;
}

string Persona::getAP() {
    return apellido_paterno;
}

void Persona::setAP(string _apellido_paterno) {
    apellido_paterno = _apellido_paterno;
}

string Persona::getAM() {
    return apellido_materno;
}

void Persona::setAM(string _apellido_materno) {
    apellido_materno = _apellido_materno;
}

string Persona::getCorreo() {
    return correo;
}

void Persona::setCorreo(string _correo) {
    correo = _correo;
}

string Persona::getCelular() {
    return celular;
}

void Persona::setCelular(string _celular) {
    celular = _celular;
}