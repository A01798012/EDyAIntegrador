#ifndef IP_HPP_
#define IP_HPP_
#include <string>

using namespace std;
class Ip
{
private:
    string direccionIp;
    int cantidad;

public:
    Ip(string direccionIp)
    {
        this->direccionIp = direccionIp;
        this->cantidad = 1;
    };
    string getDireccionIp() { return this->direccionIp; }
    int getCantidad() { return this->cantidad; }
    void setCantidad(int cantidad) { this->cantidad = cantidad; }
    string display()
    {
        // Función para generar y devolver un string con la info de la Ip (direcciónIp y cantidad)
        return (this->getDireccionIp() + " #" + to_string(this->getCantidad()));
    }
};
#endif