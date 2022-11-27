#ifndef IP_HPP 
#define IP_HPP
#include <string>

using namespace std;
class Ip{
    private:
        string direccionIp;
        int cantidad; 
    public:
        Ip(string direccionIp);
        string getDireccionIp();
        int getCantidad();
        void setCantidad(int cantidad);

};
#endif