//
// Created by cuand on 16/8/2020.
//

#ifndef UNTITLED_PERSONA_H
#define UNTITLED_PERSONA_H
#include <iostream>

using namespace std;

class Persona {
private:
    //Atributos privados de la clase persona
    string nombre;
    string apellido_paterno;
    string apellido_materno;
    string correo;
    string celular;
public:
    //metodos publicos de la clase persona
    //Constructor
    Persona(string, string, string, string, string);

    //getters&setters
    string getNombre();
    void setNombre(string );
    string getAP();
    void setAP(string );
    string getAM();
    void setAM(string );
    string getCorreo();
    void setCorreo(string );
    string getCelular();
    void setCelular(string );
};


#endif //UNTITLED_PERSONA_H