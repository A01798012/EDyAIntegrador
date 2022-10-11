#include "Bitacora.hpp"

#include <string>
#include <iostream>
#include <map>

map<string, string> meses = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"},
                             {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dic", "12"}};

using namespace std;

string Bitacora::getMes(){
    return this->mes;
}
string Bitacora::getDia(){
    return this->dia;
}

int Bitacora::generarClave(){

    this->mes = meses[mes];
    string concatenado = mes + dia;
    return stoi(concatenado);
}

int Bitacora::getClave(){
    return clave;
}

Bitacora::Bitacora(string mes, string dia, string hora, string IP,
                 string puerto, string problemID){
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->IP = IP;
    this->puerto = puerto;
    this->problemID = problemID;
    this->clave = generarClave();
}
