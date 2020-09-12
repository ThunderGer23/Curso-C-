//
// Created by cuand on 11/9/2020.
//

#ifndef UNTITLED_TICKET_H
#define UNTITLED_TICKET_H

#include "Pantalon.h"
#include "Falda.h"
#include "Calzado.h"
#include "Zapatos.h"
#include "Tenis.h"
#include "Componente.h"
#include "Televisor.h"
#include "Altavoz.h"
#include <iostream>

using namespace std;

class Ticket {
private:
    string Nombre;
public:
    Ticket(string);
    void Generar_ticket();
};


#endif //UNTITLED_TICKET_H
