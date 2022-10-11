#include "Bitacora.hpp"

#include <string>
#include <iostream>

using namespace std;

string Bitacora::getMes(){
    return this->mes;
}
string Bitacora::getDia(){
    return this->dia;
}

int Bitacora::generarClave(){
    if(this->mes == "Jan"){
        this->mes = "01";
    }else if(this->mes == "Feb"){
        this->mes = "02";
    }else if(this->mes == "Mar"){
        this->mes = "03";
    }else if(this->mes == "Apr"){
        this->mes = "04";
    }else if(this->mes == "May"){
        this->mes = "05";
    }else if(this->mes == "Jun"){
        this->mes = "06";
    }else if(this->mes == "Jul"){
        this->mes = "07";
    }else if(this->mes == "Aug"){
        this->mes = "08";
    }else if(this->mes == "Sep"){
        this->mes = "09";
    }else if(this->mes == "Oct"){
        this->mes = "10";
    }else if(this->mes == "Nov"){
        this->mes = "11";
    }else{
        this->mes = "12";
    }
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
