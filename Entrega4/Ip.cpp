#include "Ip.hpp"

Ip::Ip(string direccionIp){
    this->direccionIp = direccionIp;
    this->cantidad = 1;
}

string Ip::getDireccionIp(){ return this->direccionIp; }
int Ip::getCantidad(){ return this->cantidad; }

void Ip::setCantidad(int cantidad){ this->cantidad = cantidad; }