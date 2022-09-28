#include "Bitacora.hpp"

#include <string>
#include <iostream>

using namespace std;

string Bitacora::getMes()
{
    return mes;
}
string Bitacora::getDia()
{
    return dia;
}

int Bitacora::generarClave()
{
    string concatenado = mes + dia;
    return stoi(concatenado);
}

Bitacora::Bitacora()
{
    clave = generarClave();
}