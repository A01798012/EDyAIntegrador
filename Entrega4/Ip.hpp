#ifndef IP_HPP 
#define IP_HPP
#include <string>

using namespace std;
class Ip{
    private:
        string direccionIp;
        int cantidad; 
    public:
        Ip();
        Ip(string direccionIp, int cantidad){
            this->direccionIp = direccionIp;
            this->cantidad = cantidad;
        }
        string getdireccionIp(){ return this->direccionIp; }
        int getCanidad(){ return this->cantidad; }
        void setCantidad(int cantidad){ this->cantidad = cantidad; }

};
#endif