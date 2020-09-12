//
// Created by cuand on 11/9/2020.
//
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include "Ticket.h"

using namespace std;

void Ticket::Generar_ticket() {
    remove("D:\\JetBrains\\Proyect\\untitled\\1.txt");
    fstream  Arch("D:\\JetBrains\\Proyect\\untitled\\1.txt", ios::in);

    if (!Arch){
        fstream CArch("D:\\JetBrains\\Proyect\\untitled\\"+Nombre, ios::out);


        CArch<<"---"<<endl;
    }

}

Ticket::Ticket(string _Nombre) {
    Nombre = _Nombre;
}
