#include "Registro.hpp"

#include <string>
#include <iostream>
#include <map>


using namespace std;

map<string, string> meses = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"},
                             {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};


string Registro::getMes(){return this->mes;}
string Registro::getDia(){return this->dia;}
string Registro::getHora(){return this->hora;}
string Registro::getIP(){return this->IP;}
string Registro::getPuerto(){return this->puerto;}
string Registro::getProblemID(){return this->problemID;}
int Registro::getClave(){return this->clave;}

int Registro::generarClave(){
    string concatenado = meses[this->mes] + this->dia;
    return stoi(concatenado);
}



string Registro::display(){
    return (this->getMes() + " " + this->getDia() + " " + this->getHora() + " " + this->getIP() + ":" + this->getPuerto() + " " + this->getProblemID()  + "\n");
}

Registro::Registro(string mes, string dia, string hora, string IP,
                 string puerto, string problemID){
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->IP = IP;
    this->puerto = puerto;
    this->problemID = problemID;
    this->clave = generarClave();
}


