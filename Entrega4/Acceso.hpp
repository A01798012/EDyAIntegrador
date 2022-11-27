#ifndef ACCESO_HPP_ 
#define ACCESO_HPP_
#include <string>
#include "ListaDL.hpp"

using namespace std;

class Acceso{
    private:
        int cantidad;
        ListaDL<string*>* direccionesIp;
    public:
        int getCantidad(){return this->cantidad;}
};
#endif