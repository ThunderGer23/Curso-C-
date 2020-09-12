//
// Created by cuand on 13/8/2020.
//

#ifndef UNTITLED_METODOS_H
#define UNTITLED_METODOS_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include "Pantalon.h"
#include "Falda.h"
#include "Calzado.h"
#include "Zapatos.h"
#include "Tenis.h"
#include "Componente.h"
#include "Televisor.h"
#include "Altavoz.h"
#include "Cliente.h"
#include "Ticket.h"

using namespace std;

void Menu();
void Compra();
void CopyArch(int);
void Root();
void User();
void Registro();
void RegistroUser();
void Catalogo(int);
void CatalogoCat();
void CrearTele();
void CrearComp();
void CrearAltavoz();
void CrearZap();
void CrearTen();
void CrearPant();
void CrearFal();
void CrearArch(string, int);
bool Loggin();

vector <string> datart;
vector <string> datart1;
vector <string> datart2;
vector <int> Banderas;
vector <int> Banderas1;
vector <Cliente> Cli;

vector <Televisor> Tel;
vector <Componente> Comp;
vector <Altavoz> Alta;
vector <Zapatos> Zap;
vector <Tenis> Ten;
vector <Falda> Fal;
vector <Pantalon> Pant;

void Menu(){
    CopyArch(1);
    char Opc;
    string Nombre;
    string Pass;
    int i;
    do {
        cout<<"1.Entrar como Admin"<<endl<<"2.Entrar como Usuario"<<endl<<"E.Salir"<<endl;
        cin>>Opc;

        switch (Opc) {
            case '1':
                CrearArch("Cli.csv",2);
                for (i = 0; i < 3; ++i) {
                    cout<<"Ingresa tu nombre"<<endl;
                    cin>>Nombre;
                    cout<<"Ingresa tu contraseña"<<endl;
                    cin>>Pass;

                    if (Nombre == datart1.at(1) && Pass == datart1.at(2)){
                        Root();
                        break;
                    } else if (Nombre == datart1.at(1) && Pass != datart1.at(2)){
                        cout<<"Contraseña incorrecta"<<endl;
                    } else if (Nombre != datart1.at(1) && Pass == datart1.at(2)){
                        cout<<"Usuario Incorrecto"<<endl;
                    } else{
                        cout<<"Intenta otra vez"<<endl;
                    }
                }
                if (i == 3){
                    cout<<"Numero de intentos excedido"<<endl;
                }
                break;
            case '2':
                User();
                break;
            case 'E':
                cout<<"Chao Chao"<<endl;
                break;
            default:
                cout<<"Que estas haciendo animal!?!?!?!?!?!"<<endl;
                break;
        }

    }while (Opc != 'E');
}

void CopyArch(int i){

    if (i == 1){

        ifstream infile("D:\\JetBrains\\Proyect\\untitled\\BD.csv");
        string line;
        while (getline(infile, line)){
            stringstream strstr(line);
            string word;
            while (getline(strstr,word,',')){
                datart.push_back(word);
            }
        }
        for (int j = 0; j < 2; ++j) {
            if (j == 0) {
                for (int i = 0; i < datart.size(); i++) {
                    if (datart.at(i) == "TELEVISORES"
                        || datart.at(i) == "COMPONENTES"
                        || datart.at(i) == "ALTAVOZ"
                        || datart.at(i) == "ZAPATOS"
                        || datart.at(i) == "TENIS"
                        || datart.at(i) == "PANTALONES"
                        || datart.at(i) == "FALDAS"
                        || datart.at(i) == "---") {
                        Banderas.push_back(i);
                    }
                }
            } else{
                for (int l = 0; l < Banderas.size()-1; ++l) {
                    for (int m = Banderas.at(l)+1; m < Banderas.at(l + 1); ++m) {
                        if (l == 0){
                            Televisor TCopArch(datart.at(m),datart.at(m+1),datart.at(m+2),datart.at(m+3),stof(datart.at(m+4)),stof(datart.at(m+5)),datart.at(m+6));
                            Tel.push_back(TCopArch);
                            m += 6;
                        } else if (l == 1){
                            Componente CCopArch(datart.at(m),datart.at(m+1),datart.at(m+2),datart.at(m+3),datart.at(m+4),stoi(datart.at(m+5)),stoi(datart.at(m+6)),datart.at(m+7),datart.at(m+8),stof(datart.at(m+9)));
                            Comp.push_back(CCopArch);
                            m += 9;
                        } else if (l == 2){
                            bool tipo;
                            if (datart.at(m+10) == "1"){
                                tipo = 1;
                            }else{
                                tipo = 0;
                            }
                            Altavoz PCopArch(datart.at(m),datart.at(m+1),datart.at(m+2),datart.at(m+3),datart.at(m+4),stof(datart.at(m+5)),stof(datart.at(m+6)),datart.at(m+7),datart.at(m+8),stof(datart.at(m+9)),tipo);
                            Alta.push_back(PCopArch);
                            m += 10;
                        } else if (l == 3){
                            Zapatos Z1(datart.at(m), datart.at(m+1), stof(datart.at(m+2)), datart.at(m+3), datart.at(m+4), datart.at(m+5), datart.at(m+6), datart.at(m+7));
                            Zap.push_back(Z1);
                            m += 7;
                        } else if (l == 4){
                            Tenis T1(datart.at(m),datart.at(m+1),stof(datart.at(m+2)),datart.at(m+3),datart.at(m+4),datart.at(m+5),datart.at(m+6),datart.at(m+7));
                            Ten.push_back(T1);
                            m += 7;
                        } else if (l == 5){
                            Pantalon P1(datart.at(m),datart.at(m+1),stof(datart.at(m+2)),datart.at(m+3),datart.at(m+4));
                            Pant.push_back(P1);
                            m += 4;
                        } else if (l == 6){
                            Falda F1(datart.at(m),datart.at(m+1),stof(datart.at(m+2)),datart.at(m+3));
                            Fal.push_back(F1);
                            m += 3;
                        }
                    }
                }
            }
        }
    }else if (i == 2){

        ifstream  infile("D:\\JetBrains\\Proyect\\untitled\\Cli.csv");
        string line = "";
        while (getline(infile, line)){
            stringstream strstr(line);
            string word = "";
            while (getline(strstr,word,',')){
                datart1.push_back(word);
            }
        }
    } else{

        ifstream infile("D:\\JetBrains\\Proyect\\untitled\\Clientes.csv");
        string line;
        while (getline(infile, line)){
            stringstream strstr(line);
            string word;
            while (getline(strstr,word,',')){
                datart2.push_back(word);
            }
        }

        for (int x = 0; x < 2; ++x) {
            if (x == 0){
                for (int j = 0; j < datart2.size(); ++j) {
                    if (datart2.at(j) == "CLIENTE" || datart2.at(j) == "---"){
                        Banderas1.push_back(j);
                    }
                }
            } else{
                for (int j = 0; j < Banderas1.size()-1; ++j) {
                    for (int m = Banderas1.at(j)+1; m < Banderas1.at(j + 1); ++m) {
                        Cliente C1(datart2.at(m),datart2.at(m+1),datart2.at(m+2),datart2.at(m+3),datart2.at(m+4),datart2.at(m+5),stoi(datart2.at(m+6)),stoi(datart2.at(m+7)),datart2.at(m+8),datart2.at(m+9));
                        m +=9;
                        Cli.push_back(C1);
                    }
                }
            }
        }
    }
}

void Root(){
    char Opc;
    do {
        cout<<"Selecciona una opción"<<endl;
        cout<<"1.Registrar Articulo"<<endl<<"2.Mostrar Catalogo"<<endl;
        cout<<"E.Salir"<<endl;
        cin>>Opc;
        switch (Opc) {
            case '1':
                Registro();
                break;
            case '2':
                Catalogo(0);
                break;
            case 'E':
                CrearArch("BD.csv",1);
                break;
            default:
                cout<<"Que estas haciendo animal!?!?!?!?!"<<endl;
                break;
        }
    }while(Opc != 'E');
}

void User(){
    CopyArch(3);
    char OPC;
    do {
        cout<<"Selecciona una opcción para continuar"<<endl;
        cout<<"1.Registrar Nuevo Usuario"<<endl<<"2.Logguear"<<endl<<"E.Salir"<<endl;
        cin>>OPC;

        switch (OPC) {
            case '1':
                RegistroUser();
                break;
            case '2':
                if (Loggin()){
                    Catalogo(1);
                }else{
                    cout<<"No esta registrado"<<endl;
                }
                break;
            case 'E':
                cout<<"Chao Chao"<<endl;
                CrearArch("Clientes.csv",3);
                break;
            default:
                break;
        }

    }while (OPC != 'E');
}

void RegistroUser(){
    int ValRef = 0;
    int ValCorreo = 0;
    bool Let;
    bool Carac;
    int ContNum;
    string Nombre;
    string ApPa;
    string ApMa;
    string Correo;
    string Celular;
    string Calle;
    int NumInt;
    int NumExt;
    string Ciudad;
    string Contra;

    cout<<"Hola nuevo comprador"<<endl;
    cout<<"Vamos a iniciar con tu registro..."<<endl;

    for (int i = 0; i <= 10; ++i) {
        switch (i) {
            case 0:
                cout<<"Cual es tu nombre?"<<endl;
                cin>>Nombre;

                for (int j = 0; j < Nombre.size(); ++j) {
                    if((((int)Nombre[j]) >= 65 && ((int)Nombre[j]) <=90) || (((int)Nombre[j]) > 96 && ((int)Nombre[j]) <=122)){
                        continue;
                    }else{
                        cout<<"Nombre no valido"<<endl;
                        i--;
                        break;
                    }
                }
                break;
            case 1:

                cout<<"Cual es tu apellido paterno?"<<endl;
                cin>>ApPa;
                for (int j = 0; j < ApPa.size(); ++j) {
                    if((((int)ApPa[j]) > 64 && ((   int)ApPa[j]) <=90) || (((int)ApPa[j]) > 96 && ((int)ApPa[j]) <=122)){
                        continue;
                    }else{
                        cout<<"Apellido no valido"<<endl;
                        i--;
                        break;
                    }
                }
                break;
            case 2:

                cout<<"Cual es tu apellido materno?"<<endl;
                cin>>ApMa;
                for (int j = 0; j < ApMa.size(); ++j) {
                    if((((int)ApMa[j]) > 64 && ((int)ApMa[j]) <=90) || (((int)ApMa[j]) > 96 && ((int)ApMa[j]) <=122)){
                        continue;
                    }else{
                        cout<<"Apellido no valido"<<endl;
                        i--;
                        break;
                    }
                }

                break;
            case 3:

                cout<<"Ingresa un correo?"<<endl;
                cin>>Correo;

                for (int j = 0; j < Correo.size(); ++j) {
                    if(((int)Correo[j] == 64) ||((int) Correo[j] == 46)){
                        ValCorreo++;
                    }
                }

                if(ValCorreo == 2){
                    continue;
                }else{
                    cout<<"Correo Invalido"<<endl;
                    i--;
                    break;
                }

                break;
            case 4:

                cout<<"Ingresa tu numero telefonico a 10 digitos"<<endl;
                cin>>Celular;

                for (int m = 0; m < Celular.size(); ++m) {
                    if(Celular.size() != 10){
                        i--;
                    }else if (((int)Celular[m]) > 47 && ((int)Celular[m]) <=57){
                        continue;
                    }else{
                        cout<<"Numero no valido"<<endl;
                        i--;
                        break;
                    }
                }

                break;
            case 5:

                cout<<"Ingresa el nombre de tu calle"<<endl;
                cin>>Calle;

                for (int k = 0; k < Calle.size(); ++k) {
                    if((((int)Calle[k]) > 64 && ((int)Calle[k]) <=90) || (((int)Calle[k]) > 96 && ((int)Calle[k]) <=122) || ((int)Calle[k] == 46) || (((int)Calle[k]) > 47 && ((int)Calle[k]) <=57)){
                        continue;
                    }else{
                        cout<<"Nombre de calle no valido"<<endl;
                        i--;
                        break;
                    }
                }

                break;
            case 6:
                cout<<"Ingresa tu numero interno"<<endl;
                cin>>NumInt;
                break;
            case 7:
                cout<<"Ingresa tu numero externo"<<endl;
                cin>>NumExt;
                break;
            case 8:
                cout<<"Ingresa tu ciudad"<<endl;
                cin>>Ciudad;

                for (int l = 0; l < Ciudad.size(); ++l) {
                    if((((int)Ciudad[l]) > 64 && ((int)Ciudad[l]) <=90) || (((int)Ciudad[l]) > 96 && ((int)Ciudad[l]) <=122)){
                        continue;
                    }else{
                        cout<<"Esto no es una ciudad"<<endl;
                        i--;
                        break;
                    }
                }
                break;
            case 9:

                cout<<"Ingresa una contraseña de 8 a 10 digitos que contenga almenos"<<endl;
                cout<<"2 Numeros"<<endl<<"1 Letra mayuscula"<<endl<<"1 Caracter '(,),+,-,*,/,.'"<<endl;
                cin>>Contra;

                if((Contra.size() >= 8) && (Contra.size() <= 10)){
                    for (int j = 0; j < Contra.size(); ++j) {
                        if((int)Contra.at(j) >= 65 && (int)Contra.at(j) <= 90){
                            Let = true;
                        }else if((int)Contra.at(j) >= 48 && (int)Contra.at(j) <= 57){
                            ContNum++;
                        }else if((int)Contra.at(j) >= 40 && (int)Contra.at(j) <= 47){
                            Carac = true;
                        }
                    }
                }else{
                    cout<<"La Contraseña no cumple con las caracteristicas"<<endl;
                    i--;
                    break;
                }
                break;
            case 10:
                Cliente C1(Nombre,ApPa, ApMa, Correo, Celular, Calle, NumInt, NumExt, Ciudad, Contra);
                Cli.push_back(C1);
                break;
        }
    }
}

void Registro(){
    char Opc;
    do{
        cout<<"Que Articulo quieres registrar"<<endl;
        cout<<"1.Tevision"<<endl<<"2.Componente"<<endl;
        cout<<"3.Alatavoz"<<endl<<"4.Zapatos"<<endl;
        cout<<"5.Tenis"<<endl<<"6.Pantalon"<<endl;
        cout<<"7.Falda"<<endl<<"E.Salir"<<endl;
        cin>>Opc;

        switch (Opc) {
            case '1':
                CrearTele();
                break;
            case '2':
                CrearComp();
                break;
            case '3':
                CrearAltavoz();
                break;
            case '4':
                CrearZap();
                break;
            case '5':
                CrearTen();
                break;
            case '6':
                CrearPant();
                break;
            case '7':
                CrearFal();
                break;
            case 'E':
                cout<<"Volviendo al menu anterior"<<endl;
                break;
            default:
                cout<<"Que estas haciendo animal!?!?!?!?!"<<endl;
                break;
        }

    }while (Opc != 'E');
}

bool Loggin(){
    string Correo;
    string Contra;
    for (int i = 0; i < 3; ++i) {
        cout<<"Ingrese su Correo"<<endl;
        cin>>Correo;
        cout<<"Ingrese su contraseña"<<endl;
        cin>>Contra;

        for (int j = 0; j < Cli.size(); ++j) {
            while (Contra == Cli.at(j).getContra() && Correo == Cli.at(j).getCorreo()){
                return true;
            }
        }
        cout<<"Usuario no encontrado"<<endl;
    }
    cout<<"Numero de intentos excedidos"<<endl;
    return false;
}

void Catalogo(int num){
    char OPC;
    float Precio;
    string Marca;
    do{
        cout<<"1.Mostrar Catalogo completo"<<endl<<"2.Buscar por categoria"<<endl;
        cout<<"3.Buscar por precio"<<endl<<"4.Buscar por Marca"<<endl;
        cout<<"E.Salir"<<endl;
        cin>>OPC;

        if (num == 0){
            switch (OPC) {
                case '1':
                    //Aqui se declaran todos los atributos de los objetos para el catalogo general
                    for (int i = 0; i < 7; ++i) {
                        switch (i) {
                            case 0:
                                cout<<"Televisores"<<endl;
                                cout<<"Marca\t"<<"Color\t"<<"Precio\t"<<"Tamanio\t"<<"Definición\t"<<"Descripcion\t"<<endl;
                                for (int j = 0; j < (Tel.size()); ++j) {
                                    cout <<Tel.at(j).getMarca() << "\t";
                                    cout <<Tel.at(j).getColor() << "\t";
                                    cout <<Tel.at(j).getPrecio() << "\t";
                                    cout <<Tel.at(j).getTam() <<"\t";
                                    cout <<Tel.at(j).getDef() <<"\t\t";
                                    cout <<Tel.at(j).getDescripcion() <<"\t";
                                    cout<<endl;
                                }
                                cout<<endl;
                                break;
                            case 1:
                                cout<<"Componentes"<<endl;
                                cout<<"Marca\t"<<"Color\t"<<"Precio\t"<<"Potencia\t"<<"Modelo\t"<<"Descripcion\t\t";
                                cout<<"Compativilidad\t"<<"Conectividad\t"<<"#Aux\t"<<"#USB"<<endl;
                                for (int j = 0; j < (Comp.size()); ++j) {
                                    cout <<Comp.at(j).getMarca()<<"\t";
                                    cout <<Comp.at(j).getColor()<<"\t";
                                    cout <<Comp.at(j).getPrecio()<<"\t";
                                    cout <<Comp.at(j).getPot()<<"\t\t";
                                    cout <<Comp.at(j).getModelo()<<"\t";
                                    cout <<Comp.at(j).getDescripcion()<<"\t";
                                    cout <<Comp.at(j).getCompativilidad()<<"\t";
                                    cout <<Comp.at(j).getConectividad()<<"\t";
                                    cout <<Comp.at(j).getNumPuertAux()<<"\t";
                                    cout <<Comp.at(j).getNumPuertUSB()<<"\t"<<endl;
                                }
                                cout<<endl;
                                break;
                            case 2:
                                cout<<"Altavoces"<<endl;
                                cout<<"Marca\t"<<"Color\t"<<"Precio\t"<<"Potencia\t"<<"Modelo\t"<<"Descripcion\t\t";
                                cout<<"Compativilidad\t"<<"Conectividad\t"<<"#Aux\t"<<"#USB\t"<<"Tipo"<<endl;
                                for (int j = 0; j < (Alta.size()); ++j) {
                                    cout <<Alta.at(j).getMarca()<<"\t";
                                    cout <<Alta.at(j).getColor()<<"\t";
                                    cout <<Alta.at(j).getPrecio()<<"\t";
                                    cout <<Alta.at(j).getPot()<<"\t\t";
                                    cout <<Alta.at(j).getModelo()<<"\t";
                                    cout <<Alta.at(j).getDescripcion()<<"\t";
                                    cout <<Alta.at(j).getCompativilidad()<<"\t";
                                    cout <<Alta.at(j).getConectividad()<<"\t";
                                    cout <<Alta.at(j).getNumPuertAux()<<"\t";
                                    cout <<Alta.at(j).getNumPuertUSB()<<"\t";
                                    cout <<Alta.at(j).getTipo()<<"\t"<<endl;
                                }
                                cout<<endl;
                                break;
                            case 3:
                                cout<<"Zapapatos"<<endl;
                                cout<<"Marca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo de Zapato\t"<<"Color\t"<<"Corte Exterior\t"<<"Corte Interior\t"<<"Tipo de Suela\t"<<endl;
                                for (int j = 0; j < (Zap.size()); ++j) {
                                    cout<<Zap.at(j).getMarca()<<"\t";
                                    cout<<Zap.at(j).getTam()<<"\t";
                                    cout<<Zap.at(j).getPrecio()<<"\t";
                                    cout<<Zap.at(j).getTipZa()<<"\t";
                                    cout<<Zap.at(j).getColor()<<"\t";
                                    cout<<Zap.at(j).getCortExt()<<"\t";
                                    cout<<Zap.at(j).getCortInt()<<"\t";
                                    cout<<Zap.at(j).getTipZa()<<"\t"<<endl;
                                }
                                cout<<endl;
                                break;
                            case 4:
                                cout<<"Tenis"<<endl;
                                cout<<"Marca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo de Zapato\t"<<"Color\t"<<"Corte Exterior\t"<<"Corte Interior\t"<<"Tipo de Suela\t"<<endl;
                                for (int j = 0; j < (Ten.size()); ++j) {
                                    cout<<Ten.at(j).getMarca()<<"\t";
                                    cout<<Ten.at(j).getTam()<<"\t";
                                    cout<<Ten.at(j).getPrecio()<<"\t";
                                    cout<<Ten.at(j).getTipoTenis()<<"\t";
                                    cout<<Ten.at(j).getColor()<<"\t";
                                    cout<<Ten.at(j).getCortExt()<<"\t";
                                    cout<<Ten.at(j).getCortInt()<<"\t";
                                    cout<<Ten.at(j).getTipoTenis()<<"\t"<<endl;
                                }
                                cout<<endl;
                                break;
                            case 5:
                                cout<<"Pantalon"<<endl;
                                cout<<"Marca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo\t"<<"Dama o Caballero"<<endl;
                                for (int j = 0; j < Pant.size(); ++j) {
                                    cout<<Pant.at(j).getMarca()<<"\t";
                                    cout<<Pant.at(j).getTam()<<"\t";
                                    cout<<Pant.at(j).getPrecio()<<"\t";
                                    cout<<Pant.at(j).getTipo()<<"\t";
                                    cout<<Pant.at(j).getDamCab()<<"\t"<<endl;
                                }
                                cout<<endl;
                                break;
                            case 6:
                                cout<<"Falda"<<endl;
                                cout<<"Marca\t"<<"Tamanio\t"<<"Precio\t"<<"Modelo"<<endl;
                                for (int j = 0; j < Fal.size(); ++j) {
                                    cout<<Fal.at(j).getMarca()<<"\t";
                                    cout<<Fal.at(j).getTam()<<"\t";
                                    cout<<Fal.at(j).getPrecio()<<"\t";
                                    cout<<Fal.at(j).getModelo()<<"\t"<<endl;
                                }
                                cout<<endl;
                                break;
                        }
                    }
                    break;
                case '2':
                    CatalogoCat();
                    break;
                case '3':
                    cout<<"Ingresa el precio que buscas"<<endl;
                    cin>>Precio;
                    for (int i = 0; i < 7; ++i) {
                        switch (i) {
                            case 0:
                                cout<<"Televisores"<<endl;
                                cout<<"Marca\t"<<"Color\t"<<"Tamanio\t"<<"Definición\t"<<"Descripcion\t"<<endl;
                                for (int j = 0; j < (Tel.size()); ++j) {
                                    if (Tel.at(j).getPrecio() == Precio){
                                        cout <<Tel.at(j).getMarca() << "\t";
                                        cout <<Tel.at(j).getColor() << "\t";
                                        cout <<Tel.at(j).getTam() <<"\t";
                                        cout <<Tel.at(j).getDef() <<"\t\t";
                                        cout <<Tel.at(j).getDescripcion() <<"\t";
                                        cout<<endl;
                                    }
                                }
                                break;
                            case 1:
                                cout<<"Componentes"<<endl;
                                cout<<"Marca\t"<<"Color\t"<<"Potencia\t"<<"Modelo\t"<<"Descripcion\t\t";
                                cout<<"Compativilidad\t"<<"Conectividad\t"<<"#Aux\t"<<"#USB"<<endl;
                                for (int j = 0; j < (Comp.size()); ++j) {
                                    if (Comp.at(j).getPrecio() == Precio){
                                        cout <<Comp.at(j).getMarca()<<"\t";
                                        cout <<Comp.at(j).getColor()<<"\t";
                                        cout <<Comp.at(j).getPot()<<"\t\t";
                                        cout <<Comp.at(j).getModelo()<<"\t";
                                        cout <<Comp.at(j).getDescripcion()<<"\t";
                                        cout <<Comp.at(j).getCompativilidad()<<"\t";
                                        cout <<Comp.at(j).getConectividad()<<"\t";
                                        cout <<Comp.at(j).getNumPuertAux()<<"\t";
                                        cout <<Comp.at(j).getNumPuertUSB()<<"\t"<<endl;
                                    }

                                }
                                break;
                            case 2:
                                cout<<"Altavoces"<<endl;
                                cout<<"Marca\t"<<"Color\t"<<"Precio\t"<<"Potencia\t"<<"Modelo\t"<<"Descripcion\t\t";
                                cout<<"Compativilidad\t"<<"Conectividad\t"<<"#Aux\t"<<"#USB\t"<<"Tipo"<<endl;
                                for (int j = 0; j < Alta.size(); ++j) {
                                    if (Alta.at(j).getPrecio() == Precio){
                                        cout <<Alta.at(j).getMarca()<<"\t";
                                        cout <<Alta.at(j).getColor()<<"\t";
                                        cout <<Alta.at(j).getPot()<<"\t\t";
                                        cout <<Alta.at(j).getModelo()<<"\t";
                                        cout <<Alta.at(j).getDescripcion()<<"\t";
                                        cout <<Alta.at(j).getCompativilidad()<<"\t";
                                        cout <<Alta.at(j).getConectividad()<<"\t";
                                        cout <<Alta.at(j).getNumPuertAux()<<"\t";
                                        cout <<Alta.at(j).getNumPuertUSB()<<"\t";
                                        cout <<Alta.at(j).getTipo()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 3:
                                cout<<"Zapapatos"<<endl;
                                cout<<"Marca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo de Zapato\t"<<"Color\t"<<"Corte Exterior\t"<<"Corte Interior\t"<<"Tipo de Suela\t"<<endl;
                                for (int j = 0; j < Zap.size(); ++j) {
                                    if (Zap.at(j).getPrecio() == Precio){
                                        cout<<Zap.at(j).getMarca()<<"\t";
                                        cout<<Zap.at(j).getTam()<<"\t";
                                        cout<<Zap.at(j).getTipZa()<<"\t";
                                        cout<<Zap.at(j).getColor()<<"\t";
                                        cout<<Zap.at(j).getCortExt()<<"\t";
                                        cout<<Zap.at(j).getCortInt()<<"\t";
                                        cout<<Zap.at(j).getTipSue()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 4:
                                cout<<"Tenis"<<endl;
                                cout<<"Marca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo de Zapato\t"<<"Color\t"<<"Corte Exterior\t"<<"Corte Interior\t"<<"Tipo de Suela\t"<<endl;
                                for (int j = 0; j < Ten.size(); ++j) {
                                    if (Ten.at(j).getPrecio() == Precio){
                                        cout<<Ten.at(j).getMarca()<<"\t";
                                        cout<<Ten.at(j).getTam()<<"\t";
                                        cout<<Ten.at(j).getTipoTenis()<<"\t";
                                        cout<<Ten.at(j).getColor()<<"\t";
                                        cout<<Ten.at(j).getCortExt()<<"\t";
                                        cout<<Ten.at(j).getCortInt()<<"\t";
                                        cout<<Ten.at(j).getTipSue()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 5:
                                cout<<"Pantalon"<<endl;
                                cout<<"Marca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo\t"<<"Dama o Caballero"<<endl;
                                for (int j = 0; j < Pant.size(); ++j) {
                                    if(Pant.at(j).getPrecio() == Precio){
                                        cout<<Pant.at(j).getMarca()<<"\t";
                                        cout<<Pant.at(j).getTam()<<"\t";
                                        cout<<Pant.at(j).getTipo()<<"\t";
                                        cout<<Pant.at(j).getDamCab()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 6:
                                cout<<"Falda"<<endl;
                                cout<<"Marca\t"<<"Tamanio\t"<<"Precio\t"<<"Modelo"<<endl;
                                for (int j = 0; j < Fal.size(); ++j) {
                                    if (Fal.at(j).getPrecio() == Precio){
                                        cout<<Fal.at(j).getMarca()<<"\t";
                                        cout<<Fal.at(j).getTam()<<"\t";
                                        cout<<Fal.at(j).getModelo()<<"\t"<<endl;
                                    }
                                }
                                break;
                        }
                    }
                    break;
                case '4':
                    cout<<"Ingresa la marca que buscas"<<endl;
                    cin>>Marca;
                    for (int i = 0; i < 7; ++i) {
                        switch (i) {
                            case 0:
                                cout<<"Televisores"<<endl;
                                cout<<"Marca\t"<<"Color\t"<<"Tamanio\t"<<"Definición\t"<<"Descripcion\t"<<endl;
                                for (int j = 0; j < (Tel.size()); ++j) {
                                    if (Tel.at(j).getMarca() == Marca){
                                        cout <<Tel.at(j).getPrecio() << "\t";
                                        cout <<Tel.at(j).getColor() << "\t";
                                        cout <<Tel.at(j).getTam() <<"\t";
                                        cout <<Tel.at(j).getDef() <<"\t\t";
                                        cout <<Tel.at(j).getDescripcion() <<"\t";
                                        cout<<endl;
                                    }
                                }
                                break;
                            case 1:
                                cout<<"Componentes"<<endl;
                                cout<<"Precio\t"<<"Color\t"<<"Potencia\t"<<"Modelo\t"<<"Descripcion\t\t";
                                cout<<"Compativilidad\t"<<"Conectividad\t"<<"#Aux\t"<<"#USB"<<endl;
                                for (int j = 0; j < (Comp.size()); ++j) {
                                    if (Comp.at(j).getMarca() == Marca){
                                        cout <<Comp.at(j).getPrecio()<<"\t";
                                        cout <<Comp.at(j).getColor()<<"\t";
                                        cout <<Comp.at(j).getPot()<<"\t\t";
                                        cout <<Comp.at(j).getModelo()<<"\t";
                                        cout <<Comp.at(j).getDescripcion()<<"\t";
                                        cout <<Comp.at(j).getCompativilidad()<<"\t";
                                        cout <<Comp.at(j).getConectividad()<<"\t";
                                        cout <<Comp.at(j).getNumPuertAux()<<"\t";
                                        cout <<Comp.at(j).getNumPuertUSB()<<"\t"<<endl;
                                    }

                                }
                                break;
                            case 2:
                                cout<<"Altavoces"<<endl;
                                cout<<"Precio\t"<<"Color\t"<<"Potencia\t"<<"Modelo\t"<<"Descripcion\t\t";
                                cout<<"Compativilidad\t"<<"Conectividad\t"<<"#Aux\t"<<"#USB\t"<<"Tipo"<<endl;
                                for (int j = 0; j < Alta.size(); ++j) {
                                    if (Alta.at(j).getMarca() == Marca){
                                        cout <<Alta.at(j).getPrecio()<<"\t";
                                        cout <<Alta.at(j).getColor()<<"\t";
                                        cout <<Alta.at(j).getPot()<<"\t\t";
                                        cout <<Alta.at(j).getModelo()<<"\t";
                                        cout <<Alta.at(j).getDescripcion()<<"\t";
                                        cout <<Alta.at(j).getCompativilidad()<<"\t";
                                        cout <<Alta.at(j).getConectividad()<<"\t";
                                        cout <<Alta.at(j).getNumPuertAux()<<"\t";
                                        cout <<Alta.at(j).getNumPuertUSB()<<"\t";
                                        cout <<Alta.at(j).getTipo()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 3:
                                cout<<"Zapapatos"<<endl;
                                cout<<"Precio\t"<<"Tamanio\t"<<"Tipo de Zapato\t"<<"Color\t"<<"Corte Exterior\t"<<"Corte Interior\t"<<"Tipo de Suela\t"<<endl;
                                for (int j = 0; j < Zap.size(); ++j) {
                                    if (Zap.at(j).getMarca() == Marca){
                                        cout<<Zap.at(j).getPrecio()<<"\t";
                                        cout<<Zap.at(j).getTam()<<"\t";
                                        cout<<Zap.at(j).getTipZa()<<"\t";
                                        cout<<Zap.at(j).getColor()<<"\t";
                                        cout<<Zap.at(j).getCortExt()<<"\t";
                                        cout<<Zap.at(j).getCortInt()<<"\t";
                                        cout<<Zap.at(j).getTipSue()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 4:
                                cout<<"Tenis"<<endl;
                                cout<<"Precio\t"<<"Tamanio\t"<<"Tipo de Zapato\t"<<"Color\t"<<"Corte Exterior\t"<<"Corte Interior\t"<<"Tipo de Suela\t"<<endl;
                                for (int j = 0; j < Ten.size(); ++j) {
                                    if (Ten.at(j).getMarca() == Marca){
                                        cout<<Ten.at(j).getPrecio()<<"\t";
                                        cout<<Ten.at(j).getTam()<<"\t";
                                        cout<<Ten.at(j).getTipoTenis()<<"\t";
                                        cout<<Ten.at(j).getColor()<<"\t";
                                        cout<<Ten.at(j).getCortExt()<<"\t";
                                        cout<<Ten.at(j).getCortInt()<<"\t";
                                        cout<<Ten.at(j).getTipSue()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 5:
                                cout<<"Pantalon"<<endl;
                                cout<<"Precio\t"<<"Tamanio\t"<<"Tipo\t"<<"Dama o Caballero"<<endl;
                                for (int j = 0; j < Pant.size(); ++j) {
                                    if(Pant.at(j).getMarca() == Marca){
                                        cout<<Pant.at(j).getPrecio()<<"\t";
                                        cout<<Pant.at(j).getTam()<<"\t";
                                        cout<<Pant.at(j).getTipo()<<"\t";
                                        cout<<Pant.at(j).getDamCab()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 6:
                                cout<<"Falda"<<endl;
                                cout<<"Precio\t"<<"Tamanio\t"<<"Modelo"<<endl;
                                for (int j = 0; j < Fal.size(); ++j) {
                                    if (Fal.at(j).getMarca() == Marca){
                                        cout<<Fal.at(j).getPrecio()<<"\t";
                                        cout<<Fal.at(j).getTam()<<"\t";
                                        cout<<Fal.at(j).getModelo()<<"\t"<<endl;
                                    }
                                }
                                break;
                        }
                    }
                    break;
                case 'E':
                    cout<<"Chao Chao"<<endl;
                    break;
                default:
                    cout<<"Que estas haciendo animal!?!?!?!"<<endl;
                    break;
            }
        } else{
            switch (OPC) {
                case '1':
                    //Aqui se declaran todos los atributos de los objetos para el catalogo general
                    for (int i = 0; i < 7; ++i) {
                        switch (i) {
                            case 0:
                                cout<<"Televisores"<<endl;
                                cout<<"ID\tMarca\t"<<"Color\t"<<"Precio\t"<<"Tamanio\t"<<"Definición\t"<<"Descripcion\t"<<endl;
                                for (int j = 0; j < (Tel.size()); ++j) {
                                    cout<<j<<"\t";
                                    cout<<Tel.at(j).getMarca() << "\t";
                                    cout <<Tel.at(j).getColor() << "\t";
                                    cout <<Tel.at(j).getPrecio() << "\t";
                                    cout <<Tel.at(j).getTam() <<"\t";
                                    cout <<Tel.at(j).getDef() <<"\t\t";
                                    cout <<Tel.at(j).getDescripcion() <<"\t";
                                    cout<<endl;
                                }
                                cout<<endl;
                                break;
                            case 1:
                                cout<<"Componentes"<<endl;
                                cout<<"ID\tMarca\t"<<"Color\t"<<"Precio\t"<<"Potencia\t"<<"Modelo\t"<<"Descripcion\t\t";
                                cout<<"Compativilidad\t"<<"Conectividad\t"<<"#Aux\t"<<"#USB"<<endl;
                                for (int j = 0; j < (Comp.size()); ++j) {
                                    cout<<j<<"\t";
                                    cout <<Comp.at(j).getMarca()<<"\t";
                                    cout <<Comp.at(j).getColor()<<"\t";
                                    cout <<Comp.at(j).getPrecio()<<"\t";
                                    cout <<Comp.at(j).getPot()<<"\t\t";
                                    cout <<Comp.at(j).getModelo()<<"\t";
                                    cout <<Comp.at(j).getDescripcion()<<"\t";
                                    cout <<Comp.at(j).getCompativilidad()<<"\t";
                                    cout <<Comp.at(j).getConectividad()<<"\t";
                                    cout <<Comp.at(j).getNumPuertAux()<<"\t";
                                    cout <<Comp.at(j).getNumPuertUSB()<<"\t"<<endl;
                                }
                                cout<<endl;
                                break;
                            case 2:
                                cout<<"Altavoces"<<endl;
                                cout<<"ID\tMarca\t"<<"Color\t"<<"Precio\t"<<"Potencia\t"<<"Modelo\t"<<"Descripcion\t\t";
                                cout<<"Compativilidad\t"<<"Conectividad\t"<<"#Aux\t"<<"#USB\t"<<"Tipo"<<endl;
                                for (int j = 0; j < (Alta.size()); ++j) {
                                    cout<<j<<"\t";
                                    cout <<Alta.at(j).getMarca()<<"\t";
                                    cout <<Alta.at(j).getColor()<<"\t";
                                    cout <<Alta.at(j).getPrecio()<<"\t";
                                    cout <<Alta.at(j).getPot()<<"\t\t";
                                    cout <<Alta.at(j).getModelo()<<"\t";
                                    cout <<Alta.at(j).getDescripcion()<<"\t";
                                    cout <<Alta.at(j).getCompativilidad()<<"\t";
                                    cout <<Alta.at(j).getConectividad()<<"\t";
                                    cout <<Alta.at(j).getNumPuertAux()<<"\t";
                                    cout <<Alta.at(j).getNumPuertUSB()<<"\t";
                                    cout <<Alta.at(j).getTipo()<<"\t"<<endl;
                                }
                                cout<<endl;
                                break;
                            case 3:
                                cout<<"Zapapatos"<<endl;
                                cout<<"ID\tMarca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo de Zapato\t"<<"Color\t"<<"Corte Exterior\t"<<"Corte Interior\t"<<"Tipo de Suela\t"<<endl;
                                for (int j = 0; j < (Zap.size()); ++j) {
                                    cout<<j<<"\t";
                                    cout<<Zap.at(j).getMarca()<<"\t";
                                    cout<<Zap.at(j).getTam()<<"\t";
                                    cout<<Zap.at(j).getPrecio()<<"\t";
                                    cout<<Zap.at(j).getTipZa()<<"\t";
                                    cout<<Zap.at(j).getColor()<<"\t";
                                    cout<<Zap.at(j).getCortExt()<<"\t";
                                    cout<<Zap.at(j).getCortInt()<<"\t";
                                    cout<<Zap.at(j).getTipZa()<<"\t"<<endl;
                                }
                                cout<<endl;
                                break;
                            case 4:
                                cout<<"Tenis"<<endl;
                                cout<<"ID\tMarca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo de Zapato\t"<<"Color\t"<<"Corte Exterior\t"<<"Corte Interior\t"<<"Tipo de Suela\t"<<endl;
                                for (int j = 0; j < (Ten.size()); ++j) {
                                    cout<<j<<"\t";
                                    cout<<Ten.at(j).getMarca()<<"\t";
                                    cout<<Ten.at(j).getTam()<<"\t";
                                    cout<<Ten.at(j).getPrecio()<<"\t";
                                    cout<<Ten.at(j).getTipoTenis()<<"\t";
                                    cout<<Ten.at(j).getColor()<<"\t";
                                    cout<<Ten.at(j).getCortExt()<<"\t";
                                    cout<<Ten.at(j).getCortInt()<<"\t";
                                    cout<<Ten.at(j).getTipoTenis()<<"\t"<<endl;
                                }
                                cout<<endl;
                                break;
                            case 5:
                                cout<<"Pantalon"<<endl;
                                cout<<"ID\tMarca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo\t"<<"Dama o Caballero"<<endl;
                                for (int j = 0; j < Pant.size(); ++j) {
                                    cout<<j<<"\t";
                                    cout<<Pant.at(j).getMarca()<<"\t";
                                    cout<<Pant.at(j).getTam()<<"\t";
                                    cout<<Pant.at(j).getPrecio()<<"\t";
                                    cout<<Pant.at(j).getTipo()<<"\t";
                                    cout<<Pant.at(j).getDamCab()<<"\t"<<endl;
                                }
                                cout<<endl;
                                break;
                            case 6:
                                cout<<"Falda"<<endl;
                                cout<<"ID\tMarca\t"<<"Tamanio\t"<<"Precio\t"<<"Modelo"<<endl;
                                for (int j = 0; j < Fal.size(); ++j) {
                                    cout<<j<<"\t";
                                    cout<<Fal.at(j).getMarca()<<"\t";
                                    cout<<Fal.at(j).getTam()<<"\t";
                                    cout<<Fal.at(j).getPrecio()<<"\t";
                                    cout<<Fal.at(j).getModelo()<<"\t"<<endl;
                                }
                                cout<<endl;
                                break;
                        }
                    }
                    break;
                case '2':
                    CatalogoCat();
                    break;
                case '3':
                    cout<<"Ingresa el precio que buscas"<<endl;
                    cin>>Precio;
                    for (int i = 0; i < 7; ++i) {
                        switch (i) {
                            case 0:
                                cout<<"Televisores"<<endl;
                                cout<<"ID\tMarca\t"<<"Color\t"<<"Tamanio\t"<<"Definición\t"<<"Descripcion\t"<<endl;
                                for (int j = 0; j < (Tel.size()); ++j) {
                                    if (Tel.at(j).getPrecio() == Precio){
                                        cout<<j<<"\t";
                                        cout <<Tel.at(j).getMarca() << "\t";
                                        cout <<Tel.at(j).getColor() << "\t";
                                        cout <<Tel.at(j).getTam() <<"\t";
                                        cout <<Tel.at(j).getDef() <<"\t\t";
                                        cout <<Tel.at(j).getDescripcion() <<"\t";
                                        cout<<endl;
                                    }
                                }
                                break;
                            case 1:
                                cout<<"Componentes"<<endl;
                                cout<<"ID\tMarca\t"<<"Color\t"<<"Potencia\t"<<"Modelo\t"<<"Descripcion\t\t";
                                cout<<"Compativilidad\t"<<"Conectividad\t"<<"#Aux\t"<<"#USB"<<endl;
                                for (int j = 0; j < (Comp.size()); ++j) {
                                    if (Comp.at(j).getPrecio() == Precio){
                                        cout<<j<<"\t";
                                        cout <<Comp.at(j).getMarca()<<"\t";
                                        cout <<Comp.at(j).getColor()<<"\t";
                                        cout <<Comp.at(j).getPot()<<"\t\t";
                                        cout <<Comp.at(j).getModelo()<<"\t";
                                        cout <<Comp.at(j).getDescripcion()<<"\t";
                                        cout <<Comp.at(j).getCompativilidad()<<"\t";
                                        cout <<Comp.at(j).getConectividad()<<"\t";
                                        cout <<Comp.at(j).getNumPuertAux()<<"\t";
                                        cout <<Comp.at(j).getNumPuertUSB()<<"\t"<<endl;
                                    }

                                }
                                break;
                            case 2:
                                cout<<"Altavoces"<<endl;
                                cout<<"ID\tMarca\t"<<"Color\t"<<"Precio\t"<<"Potencia\t"<<"Modelo\t"<<"Descripcion\t\t";
                                cout<<"Compativilidad\t"<<"Conectividad\t"<<"#Aux\t"<<"#USB\t"<<"Tipo"<<endl;
                                for (int j = 0; j < Alta.size(); ++j) {
                                    if (Alta.at(j).getPrecio() == Precio){
                                        cout<<j<<"\t";
                                        cout <<Alta.at(j).getMarca()<<"\t";
                                        cout <<Alta.at(j).getColor()<<"\t";
                                        cout <<Alta.at(j).getPot()<<"\t\t";
                                        cout <<Alta.at(j).getModelo()<<"\t";
                                        cout <<Alta.at(j).getDescripcion()<<"\t";
                                        cout <<Alta.at(j).getCompativilidad()<<"\t";
                                        cout <<Alta.at(j).getConectividad()<<"\t";
                                        cout <<Alta.at(j).getNumPuertAux()<<"\t";
                                        cout <<Alta.at(j).getNumPuertUSB()<<"\t";
                                        cout <<Alta.at(j).getTipo()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 3:
                                cout<<"Zapapatos"<<endl;
                                cout<<"ID\tMarca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo de Zapato\t"<<"Color\t"<<"Corte Exterior\t"<<"Corte Interior\t"<<"Tipo de Suela\t"<<endl;
                                for (int j = 0; j < Zap.size(); ++j) {
                                    if (Zap.at(j).getPrecio() == Precio){
                                        cout<<j<<"\t";
                                        cout<<Zap.at(j).getMarca()<<"\t";
                                        cout<<Zap.at(j).getTam()<<"\t";
                                        cout<<Zap.at(j).getTipZa()<<"\t";
                                        cout<<Zap.at(j).getColor()<<"\t";
                                        cout<<Zap.at(j).getCortExt()<<"\t";
                                        cout<<Zap.at(j).getCortInt()<<"\t";
                                        cout<<Zap.at(j).getTipSue()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 4:
                                cout<<"Tenis"<<endl;
                                cout<<"ID\tMarca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo de Zapato\t"<<"Color\t"<<"Corte Exterior\t"<<"Corte Interior\t"<<"Tipo de Suela\t"<<endl;
                                for (int j = 0; j < Ten.size(); ++j) {
                                    if (Ten.at(j).getPrecio() == Precio){
                                        cout<<j<<"\t";
                                        cout<<Ten.at(j).getMarca()<<"\t";
                                        cout<<Ten.at(j).getTam()<<"\t";
                                        cout<<Ten.at(j).getTipoTenis()<<"\t";
                                        cout<<Ten.at(j).getColor()<<"\t";
                                        cout<<Ten.at(j).getCortExt()<<"\t";
                                        cout<<Ten.at(j).getCortInt()<<"\t";
                                        cout<<Ten.at(j).getTipSue()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 5:
                                cout<<"Pantalon"<<endl;
                                cout<<"ID\tMarca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo\t"<<"Dama o Caballero"<<endl;
                                for (int j = 0; j < Pant.size(); ++j) {
                                    if(Pant.at(j).getPrecio() == Precio){
                                        cout<<j<<"\t";
                                        cout<<Pant.at(j).getMarca()<<"\t";
                                        cout<<Pant.at(j).getTam()<<"\t";
                                        cout<<Pant.at(j).getTipo()<<"\t";
                                        cout<<Pant.at(j).getDamCab()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 6:
                                cout<<"Falda"<<endl;
                                cout<<"ID\tMarca\t"<<"Tamanio\t"<<"Precio\t"<<"Modelo"<<endl;
                                for (int j = 0; j < Fal.size(); ++j) {
                                    if (Fal.at(j).getPrecio() == Precio){
                                        cout<<j<<"\t";
                                        cout<<Fal.at(j).getMarca()<<"\t";
                                        cout<<Fal.at(j).getTam()<<"\t";
                                        cout<<Fal.at(j).getModelo()<<"\t"<<endl;
                                    }
                                }
                                break;
                        }
                    }
                    break;
                case '4':
                    cout<<"Ingresa la marca que buscas"<<endl;
                    cin>>Marca;
                    for (int i = 0; i < 7; ++i) {
                        switch (i) {
                            case 0:
                                cout<<"Televisores"<<endl;
                                cout<<"ID\tMarca\t"<<"Color\t"<<"Tamanio\t"<<"Definición\t"<<"Descripcion\t"<<endl;
                                for (int j = 0; j < (Tel.size()); ++j) {
                                    if (Tel.at(j).getMarca() == Marca){
                                        cout<<j<<"\t";
                                        cout <<Tel.at(j).getPrecio() << "\t";
                                        cout <<Tel.at(j).getColor() << "\t";
                                        cout <<Tel.at(j).getTam() <<"\t";
                                        cout <<Tel.at(j).getDef() <<"\t\t";
                                        cout <<Tel.at(j).getDescripcion() <<"\t";
                                        cout<<endl;
                                    }
                                }
                                break;
                            case 1:
                                cout<<"Componentes"<<endl;
                                cout<<"ID\tPrecio\t"<<"Color\t"<<"Potencia\t"<<"Modelo\t"<<"Descripcion\t\t";
                                cout<<"Compativilidad\t"<<"Conectividad\t"<<"#Aux\t"<<"#USB"<<endl;
                                for (int j = 0; j < (Comp.size()); ++j) {
                                    if (Comp.at(j).getMarca() == Marca){
                                        cout<<j<<"\t";
                                        cout <<Comp.at(j).getPrecio()<<"\t";
                                        cout <<Comp.at(j).getColor()<<"\t";
                                        cout <<Comp.at(j).getPot()<<"\t\t";
                                        cout <<Comp.at(j).getModelo()<<"\t";
                                        cout <<Comp.at(j).getDescripcion()<<"\t";
                                        cout <<Comp.at(j).getCompativilidad()<<"\t";
                                        cout <<Comp.at(j).getConectividad()<<"\t";
                                        cout <<Comp.at(j).getNumPuertAux()<<"\t";
                                        cout <<Comp.at(j).getNumPuertUSB()<<"\t"<<endl;
                                    }

                                }
                                break;
                            case 2:
                                cout<<"Altavoces"<<endl;
                                cout<<"ID\tPrecio\t"<<"Color\t"<<"Potencia\t"<<"Modelo\t"<<"Descripcion\t\t";
                                cout<<"Compativilidad\t"<<"Conectividad\t"<<"#Aux\t"<<"#USB\t"<<"Tipo"<<endl;
                                for (int j = 0; j < Alta.size(); ++j) {
                                    if (Alta.at(j).getMarca() == Marca){
                                        cout <<j<<"\t";
                                        cout <<Alta.at(j).getPrecio()<<"\t";
                                        cout <<Alta.at(j).getColor()<<"\t";
                                        cout <<Alta.at(j).getPot()<<"\t\t";
                                        cout <<Alta.at(j).getModelo()<<"\t";
                                        cout <<Alta.at(j).getDescripcion()<<"\t";
                                        cout <<Alta.at(j).getCompativilidad()<<"\t";
                                        cout <<Alta.at(j).getConectividad()<<"\t";
                                        cout <<Alta.at(j).getNumPuertAux()<<"\t";
                                        cout <<Alta.at(j).getNumPuertUSB()<<"\t";
                                        cout <<Alta.at(j).getTipo()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 3:
                                cout<<"Zapapatos"<<endl;
                                cout<<"ID\tPrecio\t"<<"Tamanio\t"<<"Tipo de Zapato\t"<<"Color\t"<<"Corte Exterior\t"<<"Corte Interior\t"<<"Tipo de Suela\t"<<endl;
                                for (int j = 0; j < Zap.size(); ++j) {
                                    if (Zap.at(j).getMarca() == Marca){
                                        cout<<j<<"\t";
                                        cout<<Zap.at(j).getPrecio()<<"\t";
                                        cout<<Zap.at(j).getTam()<<"\t";
                                        cout<<Zap.at(j).getTipZa()<<"\t";
                                        cout<<Zap.at(j).getColor()<<"\t";
                                        cout<<Zap.at(j).getCortExt()<<"\t";
                                        cout<<Zap.at(j).getCortInt()<<"\t";
                                        cout<<Zap.at(j).getTipSue()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 4:
                                cout<<"Tenis"<<endl;
                                cout<<"ID\tPrecio\t"<<"Tamanio\t"<<"Tipo de Zapato\t"<<"Color\t"<<"Corte Exterior\t"<<"Corte Interior\t"<<"Tipo de Suela\t"<<endl;
                                for (int j = 0; j < Ten.size(); ++j) {
                                    if (Ten.at(j).getMarca() == Marca){
                                        cout<<j<<"\t";
                                        cout<<Ten.at(j).getPrecio()<<"\t";
                                        cout<<Ten.at(j).getTam()<<"\t";
                                        cout<<Ten.at(j).getTipoTenis()<<"\t";
                                        cout<<Ten.at(j).getColor()<<"\t";
                                        cout<<Ten.at(j).getCortExt()<<"\t";
                                        cout<<Ten.at(j).getCortInt()<<"\t";
                                        cout<<Ten.at(j).getTipSue()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 5:
                                cout<<"Pantalon"<<endl;
                                cout<<"ID\tPrecio\t"<<"Tamanio\t"<<"Tipo\t"<<"Dama o Caballero"<<endl;
                                for (int j = 0; j < Pant.size(); ++j) {
                                    if(Pant.at(j).getMarca() == Marca){
                                        cout<<j<<"\t";
                                        cout<<Pant.at(j).getPrecio()<<"\t";
                                        cout<<Pant.at(j).getTam()<<"\t";
                                        cout<<Pant.at(j).getTipo()<<"\t";
                                        cout<<Pant.at(j).getDamCab()<<"\t"<<endl;
                                    }
                                }
                                break;
                            case 6:
                                cout<<"Falda"<<endl;
                                cout<<"ID\tPrecio\t"<<"Tamanio\t"<<"Modelo"<<endl;
                                for (int j = 0; j < Fal.size(); ++j) {
                                    if (Fal.at(j).getMarca() == Marca){
                                        cout<<j<<"\t";
                                        cout<<Fal.at(j).getPrecio()<<"\t";
                                        cout<<Fal.at(j).getTam()<<"\t";
                                        cout<<Fal.at(j).getModelo()<<"\t"<<endl;
                                    }
                                }
                                break;
                        }
                    }
                    break;
                case 'E':
                    cout<<"Chao Chao"<<endl;
                    break;
                default:
                    cout<<"Que estas haciendo animal!?!?!?!"<<endl;
                    break;
            }
            Compra();
        }

    }while(OPC != 'E');
}

void CatalogoCat(){
    char Opc;
    do {
        cout<<"1.Electronicos"<<endl<<"2.Ropa"<<endl<<"3.Calzado"<<endl<<"E.Regresar"<<endl;
        cin>>Opc;

        switch (Opc) {
            case '1':
                cout<<"Televisores"<<endl;
                cout<<"ID\tMarca\t"<<"Color\t"<<"Precio\t"<<"Tamanio\t"<<endl;
                for (int j = 0; j < (Tel.size()); ++j) {
                    cout<<j<<"\t";
                    cout <<Tel.at(j).getMarca() << "\t";
                    cout <<Tel.at(j).getColor() << "\t";
                    cout <<Tel.at(j).getPrecio() << "\t";
                    cout <<Tel.at(j).getTam() <<"\t";
                    cout<<endl;
                }
                cout<<endl;

                cout<<"Componentes"<<endl;
                cout<<"ID\tColor\t"<<"Precio\t"<<endl;
                for (int j = 0; j < (Comp.size()); ++j) {
                    cout <<j<<"\t";
                    cout <<Comp.at(j).getColor()<<"\t";
                    cout <<Comp.at(j).getPrecio()<<"\t";
                    cout<<endl;
                }
                cout<<endl;
                break;
            case '2':
                cout<<"Pantalon"<<endl;
                cout<<"ID\tMarca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo\t"<<"Dama o Caballero"<<endl;
                for (int j = 0; j < Pant.size(); ++j) {
                    cout<<j<<"\t";
                    cout<<Pant.at(j).getMarca()<<"\t";
                    cout<<Pant.at(j).getTam()<<"\t";
                    cout<<Pant.at(j).getPrecio()<<"\t";
                    cout<<Pant.at(j).getTipo()<<"\t";
                    cout<<Pant.at(j).getDamCab()<<"\t"<<endl;
                }
                cout<<endl;

                cout<<"Falda"<<endl;
                cout<<"ID\tMarca\t"<<"Tamanio\t"<<"Precio\t"<<"Modelo"<<endl;
                for (int j = 0; j < Fal.size(); ++j) {
                    cout<<j<<"\t";
                    cout<<Fal.at(j).getMarca()<<"\t";
                    cout<<Fal.at(j).getTam()<<"\t";
                    cout<<Fal.at(j).getPrecio()<<"\t";
                    cout<<Fal.at(j).getModelo()<<"\t"<<endl;
                }
                cout<<endl;
                break;
            case '3':
                cout<<"Zapapatos"<<endl;
                cout<<"ID\tMarca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo de Zapato\t"<<"Color\t"<<"Corte Exterior\t"<<"Corte Interior\t"<<"Tipo de Suela\t"<<endl;
                for (int j = 0; j < (Zap.size()); ++j) {
                    cout<<j<<"\t";
                    cout<<Zap.at(j).getMarca()<<"\t";
                    cout<<Zap.at(j).getTam()<<"\t";
                    cout<<Zap.at(j).getPrecio()<<"\t";
                    cout<<Zap.at(j).getTipZa()<<"\t";
                    cout<<Zap.at(j).getColor()<<"\t";
                    cout<<Zap.at(j).getCortExt()<<"\t";
                    cout<<Zap.at(j).getCortInt()<<"\t";
                    cout<<Zap.at(j).getTipSue()<<"\t"<<endl;
                }
                cout<<endl;

                cout<<"Tenis"<<endl;
                cout<<"ID\tMarca\t"<<"Tamanio\t"<<"Precio\t"<<"Tipo de Zapato\t"<<"Color\t"<<"Corte Exterior\t"<<"Corte Interior\t"<<"Tipo de Suela\t"<<endl;
                for (int j = 0; j < (Ten.size()); ++j) {
                    cout<<j<<"\t";
                    cout<<Ten.at(j).getMarca()<<"\t";
                    cout<<Ten.at(j).getTam()<<"\t";
                    cout<<Ten.at(j).getPrecio()<<"\t";
                    cout<<Ten.at(j).getTipoTenis()<<"\t";
                    cout<<Ten.at(j).getColor()<<"\t";
                    cout<<Ten.at(j).getCortExt()<<"\t";
                    cout<<Ten.at(j).getCortInt()<<"\t";
                    cout<<Ten.at(j).getTipSue()<<"\t"<<endl;
                }
                cout<<endl;
                break;
            case 'E':
                cout<<"Chao Chao"<<endl;
                break;
            default:
                cout<<"Que estas haciendo animal!?!?!?!?!?!"<<endl;
                break;
        }

    }while (Opc != 'E');
}

void Compra(){
    char opc;
    int ID;
    string cat;
    Ticket Ti("Erick");
    do {
        cout<<"Desea compar algo? S/N"<<endl;
        cin>>opc;

        switch(opc){
            case 'S':
                cout<<"Ingrese el ID del producto"<<endl;
                cin>>ID;
                cout<<"Ingresa la categoria del producto"<<endl;
                cin>>cat;

                for (int i = 0; i < cat.size(); ++i) {
                    cat[i] = tolower(cat[i]);
                }

                if (cat == "televisores") {
                    if (ID <= Tel.size()){
                        Ti.Generar_ticket(Tel.at(ID));
                    } else{
                        cout<<"Ese ID no existe en esta categoria"<<endl;
                    }
                }else if (cat == "componentes"){
                    if (ID <= Comp.size()){
                        Ti.Generar_ticket(ID, cat);
                    } else{
                        cout<<"Ese ID no existe en esta categoria"<<endl;
                    }
                }else if (cat == "altavoces"){
                    if (ID <= Alta.size()){
                        Ti.Generar_ticket(ID, cat);
                    } else{
                        cout<<"Ese ID no existe en esta categoria"<<endl;
                    }
                }else if (cat == "zapatos"){
                    if (ID <= Zap.size()){
                        Ti.Generar_ticket(ID, cat);
                    } else{
                        cout<<"Ese ID no existe en esta categoria"<<endl;
                    }
                }else if (cat == "tenis"){
                    if (ID <= Ten.size()){
                        Ti.Generar_ticket(ID, cat);
                    } else{
                        cout<<"Ese ID no existe en esta categoria"<<endl;
                    }
                }else if (cat == "pantalon"){
                    if (ID <= Pant.size()){
                        Ti.Generar_ticket(ID, cat);
                    } else{
                        cout<<"Ese ID no existe en esta categoria"<<endl;
                    }
                }else if (cat == "falda"){
                    if (ID <= Fal.size()){
                        Ti.Generar_ticket(ID, cat);
                    } else{
                        cout<<"Ese ID no existe en esta categoria"<<endl;
                    }
                } else{
                    cout<<"Que estas haciendo animal!?!?!?!"<<endl;
                }



                break;
            case 'N':
                cout<<"Si no va comprar que hace aqui?"<<endl;
                break;
            default:
                cout<<"Que estas haciendo animal?!?!?!?!"<<endl;
                break;
        }

    }while (opc != 'E');
}

//1 crear Tele
void CrearTele(){
    string Marca;
    float Tam;
    string Color;
    float Precio;
    string Def;
    string Modelo;
    string Desc;
    cout<<"Ingresa la marca del televisor"<<endl;
    cin>>Marca;
    cout<<"Ingresa el tamaño en pulgadas"<<endl;
    cin>>Tam;
    cout<<"Ingresa el color del televisor"<<endl;
    cin>>Color;
    cout<<"Ingresa el precio del televisor"<<endl;
    cin>>Precio;
    cout<<"Ingresa la definición del televisor"<<endl;
    cin>>Def;
    cout<<"Ingresa el modelo"<<endl;
    cin>>Modelo;
    cout<<"Ingresa una pequeña descripcion"<<endl;
    cin>>Desc;
    Televisor T1(Marca, Color, Modelo, Desc, Tam, Precio, Def);
    Tel.push_back(T1);
}

//2 crear Componente
void CrearComp(){
    string Marca;
    string Color;
    string Modelo;
    string Desc;
    string Conect;
    int NumPuertUSB;
    int NumPuertAux;
    string pot;
    string Compatibilidad;
    float precio;
    cout<<"Ingresa una Marca"<<endl;
    cin>>Marca;
    cout<<"Ingresa un Color"<<endl;
    cin>>Color;
    cout<<"Ingresa el modelo"<<endl;
    cin>>Modelo;
    cout<<"Ingresa una descripción"<<endl;
    cin>>Desc;
    cout<<"Tipo de conectividad"<<endl;
    cin>>Conect;
    cout<<"Numero PuertosUSB"<<endl;
    cin>>NumPuertUSB;
    cout<<"Numero Puertos AUX"<<endl;
    cin>>NumPuertAux;
    cout<<"Cual es su potencia"<<endl;
    cin>>pot;
    cout<<"Ingresa los sistemas operativos compatibles"<<endl;
    cin>>Compatibilidad;
    cout<<"El precio es de"<<endl;
    cin>>precio;
    Componente C1(Marca, Color, Modelo, Desc, Conect, NumPuertUSB, NumPuertAux, pot, Compatibilidad, precio);
    Comp.push_back(C1);
}

//3 Crear Altavoz
void CrearAltavoz(){
    string Marca;
    string Color;
    string Modelo;
    string Desc;
    string Conect;
    int NumPuertUSB;
    int NumPuertAux;
    string pot;
    string Compatibilidad;
    float precio;
    bool Tipo;
    cout<<"Ingresa una Marca: ";
    cin>>Marca;
    cout<<"Ingresa un Color: ";
    cin>>Color;
    cout<<"Ingresa el modelo: ";
    cin>>Modelo;
    cout<<"Ingresa una descripción: ";
    cin>>Desc;
    cout<<"Tipo de conectividad: ";
    cin>>Conect;
    cout<<"Numero PuertosUSB: ";
    cin>>NumPuertUSB;
    cout<<"Numero Puertos AUX: ";
    cin>>NumPuertAux;
    cout<<"Cual es su potencia: ";
    cin>>pot;
    cout<<"Ingresa los sistemas operativos compatibles: ";
    cin>>Compatibilidad;
    cout<<"El precio es de: ";
    cin>>precio;
    cout<<"Tipo de Altavoz ('Stereo', 'Mono'): ";
    cin>>Tipo;
    Altavoz Parl(Marca, Color, Modelo, Desc, Conect, NumPuertUSB, NumPuertAux, pot, Compatibilidad, precio, Tipo);
    Alta.push_back(Parl);
}

void CrearTen() {
    string Marca;
    string Tam;
    float Precio;
    string Color;
    string CortExt;
    string CortInt;
    string TipSue;
    string TipTen;

    cout<<"Ingresa la marca de los tenis"<<endl;
    cin>>Marca;
    cout<<"Ingresa el Tamanio de los tenis"<<endl;
    cin>>Tam;
    cout<<"Ingresar precio:"<<endl;
    cin>>Precio;
    cout<<"Ingresa el color de los tenis"<<endl;
    cin>>Color;
    cout<<"Ingresa el Tipo de piel externo del calzado"<<endl;
    cin>>CortExt;
    cout<<"Ingresa el Tipo de piel interna del calzado"<<endl;
    cin>>CortInt;
    cout<<"Ingresa el Tipo de suela"<<endl;
    cin>>TipSue;
    cout<<"Ingresa el tipo de tenis"<<endl;
    cin>>TipTen;

    Tenis T1(Marca, Tam, Precio, Color, CortExt, CortInt, TipSue, TipTen);
    Ten.push_back(T1);
}

void CrearZap(){
    string Marca;
    string Tam;
    float Precio;
    string Color;
    string CortExt;
    string CortInt;
    string TipSue;
    string TipZap;
    cout<<"Ingresa una Marca de calzado"<<endl;
    cin>>Marca;
    cout<<"Ingresa un Tamanio de calzado"<<endl;
    cin>>Tam;
    cout<<"Ingresar precio:"<<endl;
    cin>>Precio;
    cout<<"Ingresa un Color de calzado"<<endl;
    cin>>Color;
    cout<<"Ingresa el tipo de piel del calzado"<<endl;
    cin>>CortExt;
    cout<<"Ingresa el ripo de acabado del calzado"<<endl;
    cin>>CortInt;
    cout<<"Ingresa el tipo de suela de calzado"<<endl;
    cin>>TipSue;
    cout<<"Ingresa el tipo de zapato"<<endl;
    cin>>TipZap;
    Zapatos Z1(Marca, Tam, Precio, Color, CortExt, CortInt, TipSue, TipZap);
    Zap.push_back(Z1);
}

void CrearPant(){
    string Marca;
    string Tam;
    float Precio;
    string Tipo;
    string DamCab;

    cout<<"Ingrese la marca del pantalon"<<endl;
    cin>>Marca;
    cout<<"Ingresa la talla del pantalon"<<endl;
    cin>>Tam;
    cout<<"Ingresa el precio del pantalon"<<endl;
    cin>>Precio;
    cout<<"Ingresa el Tipo de pantalon"<<endl;
    cin>>Tipo;
    cout<<"Ingresa el DamCab(No sé que sea pero por si acaso XD)"<<endl;
    cin>>DamCab;

    Pantalon P1(Marca, Tam, Precio, Tipo, DamCab);
    Pant.push_back(P1);
}

void CrearFal(){
    string Marca;
    string Tam;
    float Precio;
    string Modelo;

    cout<<"Ingrese la marca de la falda"<<endl;
    cin>>Marca;
    cout<<"Ingrese la talla de la falda"<<endl;
    cin>>Tam;
    cout<<"Ingrese el precio de la falda"<<endl;
    cin>>Precio;
    cout<<"Ingrese el modelo de la falda"<<endl;
    cin>>Modelo;

    Falda F1(Marca, Tam, Precio, Modelo);
    Fal.push_back(F1);
}

void CrearArch(string Nombre, int Operacion){
    string NomUser;
    string Pass[2];
    if (Operacion == 1) {
        remove("D:\\JetBrains\\Proyect\\untitled\\BD.csv");
        fstream  Arch("D:\\JetBrains\\Proyect\\untitled\\"+Nombre, ios::in);

        if (!Arch){
            fstream CArch("D:\\JetBrains\\Proyect\\untitled\\"+Nombre, ios::out);

            CArch<<"TELEVISORES"<<endl;
            for (int i = 0; i < Tel.size(); ++i) {
                CArch<<Tel.at(i).getMarca()<<","<<Tel.at(i).getColor()<<",";
                CArch<<Tel.at(i).getModelo()<<","<<Tel.at(i).getDescripcion()<<",";
                CArch<<Tel.at(i).getTam()<<","<<Tel.at(i).getPrecio()<<","<<Tel.at(i).getDef()<<endl;
            }

            CArch<<"COMPONENTES"<<endl;
            for (int i = 0; i < Comp.size(); ++i) {
                CArch<<Comp.at(i).getMarca()<<","<<Comp.at(i).getColor()<<",";
                CArch<<Comp.at(i).getModelo()<<","<<Comp.at(i).getDescripcion()<<",";
                CArch<<Comp.at(i).getConectividad()<<","<<Comp.at(i).getNumPuertUSB()<<",";
                CArch<<Comp.at(i).getNumPuertAux()<<","<<Comp.at(i).getPot()<<",";
                CArch<<Comp.at(i).getCompativilidad()<<","<<Comp.at(i).getPrecio()<<endl;
            }

            CArch<<"ALTAVOZ"<<endl;
            for (int i = 0; i < Alta.size(); ++i) {
                CArch<<Alta.at(i).getMarca()<<","<<Alta.at(i).getColor()<<",";
                CArch<<Alta.at(i).getModelo()<<","<<Alta.at(i).getDescripcion()<<",";
                CArch<<Alta.at(i).getConectividad()<<","<<Alta.at(i).getNumPuertUSB()<<",";
                CArch<<Alta.at(i).getNumPuertAux()<<","<<Alta.at(i).getPot()<<",";
                CArch<<Alta.at(i).getCompativilidad()<<","<<Alta.at(i).getPrecio()<<endl;
                CArch<<Alta.at(i).getTipo()<<endl;
            }

            CArch<<"ZAPATOS"<<endl;
            for (int i = 0; i < Zap.size(); ++i) {
                CArch<<Zap.at(i).getMarca()<<","<<Zap.at(i).getTam()<<","<<Zap.at(i).getPrecio()<<",";
                CArch<<Zap.at(i).getColor()<<","<<Zap.at(i).getCortExt()<<","<<Zap.at(i).getCortInt()<<",";
                CArch<<Zap.at(i).getTipSue()<<","<<Zap.at(i).getTipZa()<<endl;
            }

            CArch<<"TENIS"<<endl;
            for (int i = 0; i < Ten.size(); ++i) {
                CArch<<Ten.at(i).getMarca()<<","<<Ten.at(i).getTam()<<","<<Ten.at(i).getPrecio()<<",";
                CArch<<Ten.at(i).getColor()<<","<<Ten.at(i).getCortExt()<<","<<Ten.at(i).getCortInt()<<",";
                CArch<<Ten.at(i).getTipSue()<<","<<Ten.at(i).getTipoTenis()<<endl;
            }

            CArch<<"PANTALONES"<<endl;
            for (int i = 0; i < Pant.size(); ++i) {
                CArch<<Pant.at(i).getMarca()<<","<<Pant.at(i).getTam()<<","<<Pant.at(i).getPrecio()<<",";
                CArch<<Pant.at(i).getTipo()<<","<<Pant.at(i).getDamCab()<<endl;
            }

            CArch<<"FALDAS"<<endl;
            for (int i = 0; i < Fal.size(); ++i) {
                CArch<<Fal.at(i).getMarca()<<","<<Fal.at(i).getTam()<<","<<Fal.at(i).getPrecio()<<",";
                CArch<<Fal.at(i).getModelo()<<endl;
            }
            CArch<<"---"<<endl;
        }
    } else if (Operacion == 2){
        fstream  arch("D:\\JetBrains\\Proyect\\untitled\\"+Nombre, ios::in);
        if (!arch){
            cout<<"Creando Archivo..."<<endl;
            fstream arch("D:\\JetBrains\\Proyect\\untitled\\"+Nombre, ios::out);

            cout<<"Ingrese un nombre de usuario"<<endl;
            cin>>NomUser;
            cout<<"Ingrese una contraseña"<<endl;
            cin>>Pass[0];
            cout<<"Confirme su contraseña"<<endl;
            cin>>Pass[1];

            if (Pass[0] == Pass[1]){
                cout<<"Creando Credenciales ROOT"<<endl;
                arch<<"ROOT"<<endl;
                arch<<NomUser<<endl;
                arch<<Pass[0]<<endl;
            }
        }else{
            CopyArch(2);
        }

    }else{
        remove("D:\\JetBrains\\Proyect\\untitled\\Clientes.csv");
        fstream  Arch("D:\\JetBrains\\Proyect\\untitled\\"+Nombre, ios::in);

        if (!Arch){
            fstream CArch("D:\\JetBrains\\Proyect\\untitled\\"+Nombre, ios::out);

            for (int i = 0; i < Cli.size(); ++i) {
                CArch<<"CLIENTE"<<endl;
                CArch<<Cli.at(i).getNombre()<<",";
                CArch<<Cli.at(i).getAP()<<",";
                CArch<<Cli.at(i).getAM()<<",";
                CArch<<Cli.at(i).getCorreo()<<",";
                CArch<<Cli.at(i).getCelular()<<",";
                CArch<<Cli.at(i).getCalle()<<",";
                CArch<<Cli.at(i).getNumInt()<<",";
                CArch<<Cli.at(i).getNumExt()<<",";
                CArch<<Cli.at(i).getCiudad()<<",";
                CArch<<Cli.at(i).getContra()<<endl;
            }
            CArch<<"---"<<endl;
        }
    }
}

#endif //UNTITLED_METODOS_H