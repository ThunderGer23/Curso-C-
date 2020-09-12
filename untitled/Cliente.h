//
// Created by cuand on 16/8/2020.
//

#ifndef UNTITLED_CLIENTE_H
#define UNTITLED_CLIENTE_H
#include "Persona.h"

class Cliente: public Persona {
private:
    string calle;
    int num_int;
    int num_ext;
    string Ciudad;
    string contra;
public:
    Cliente(string, string, string, string, string,string, int, int, string, string);
    string getCalle();
    void setCalle(string );
    int getNumInt();
    void setNumInt(int );
    int getNumExt();
    void setNumExt(int );
    string getCiudad();
    void setCiudad(string );
    string getContra();
    void setContra(string _contra);
};

#endif //UNTITLED_CLIENTE_H