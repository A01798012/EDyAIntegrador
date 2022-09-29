#include "Bitacora.hpp"

#include <string>
#include <iostream>

using namespace std;

string Bitacora::getMes(){
    return mes;
}
string Bitacora::getDia(){
    return dia;
}

int Bitacora::generarClave(){
    if(mes == "Jan"){
        mes = "01";
    }else if(mes == "Feb"){
        mes = "02";
    }else if(mes == "Mar"){
        mes = "03";
    }else if(mes == "Apr"){
        mes = "04";
    }else if(mes == "May"){
        mes = "05";
    }else if(mes == "Jun"){
        mes = "06";
    }else if(mes == "Jul"){
        mes = "07";
    }else if(mes == "Aug"){
        mes = "08";
    }else if(mes == "Sep"){
        mes = "09";
    }else if(mes == "Oct"){
        mes = "10";
    }else if(mes == "Nov"){
        mes = "11";
    }else{
        mes = "12";
    }
    string concatenado = mes + dia;
    return stoi(concatenado);
}

int Bitacora::getClave(){
    return clave;
}

Bitacora::Bitacora(string m, string d, string h, string ip,
                 string puer, string pID){
    mes = m;
    dia = d;
    hora = h;
    IP = ip;
    puerto = puer;
    problemID = pID;
    clave = generarClave();
}
