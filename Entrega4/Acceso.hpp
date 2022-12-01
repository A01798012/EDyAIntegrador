#ifndef ACCESO_HPP_
#define ACCESO_HPP_
#include <string>
#include "ListaDL.hpp"
#include "Ip.hpp"

using namespace std;

class Acceso
{
private:
    int cantidad;
    ListaDL<string> *direccionesIp;

public:
    Acceso(Ip * ipInicial)
    {
        this->direccionesIp = new ListaDL<string>();
        this->direccionesIp->agregarInicio(ipInicial->getDireccionIp());
        this->cantidad = ipInicial->getCantidad();
    };

    // Sobrecarga del operador == con un int
    bool operator==(int cant)
    {
        return (this->getCantidad()==cant);
    }

    // Sobrecarga del operador > con un objeto del tipo IP
    bool operator>(Ip *ip)
    {
        return (this->getCantidad() > ip->getCantidad());
    }

    // Sobrecarga del operador < con un objeto del tipo IP
    bool operator<(Ip *ip)
    {
        return (this->getCantidad() < ip->getCantidad());
    }

    // Sobrecarga del operador > con un int
    bool operator>(int cant)
    {
        return (this->getCantidad() > cant);
    }

    // Sobrecarga del operador < con un int
    bool operator<(int cant)
    {
        return (this->getCantidad() < cant);
    }

    string display()
    {
        // Función para generar y devolver un string con la info del acceso (cantidad y direcciones IP)

        string mensaje = "";
        Nodo<string> *ipActual = this->direccionesIp->getHead();
        for (int i = 0; i < this->direccionesIp->getTam(); i++)
        {
            mensaje += ipActual->getDato()+"\n";
            ipActual = ipActual->getSiguiente();
        }

        mensaje += "\n";
        return mensaje;
    }

    void agregarIp(string ip)
    {
        this->direccionesIp->agregarInicio(ip);
    }

    int getCantidad() { return this->cantidad; }
};
#endif