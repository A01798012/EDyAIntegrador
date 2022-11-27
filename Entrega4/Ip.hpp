#ifndef IP_HPP 
#define IP_HPP
#include <string>

using namespace std;
class Ip{
    private:
        string direccionIp;
        int cantidad; 
    public:
        Ip(string direccionIp){
            this->direccionIp = direccionIp;
            this->cantidad = 1;
        };
        string getDireccionIp(){return this->direccionIp;}
        int getCantidad(){return this->cantidad;}
        void setCantidad(int cantidad){this->cantidad = cantidad;}

};
#endif