#ifndef BITACORA_H
#define BITACORA_H

#include <string>

using namespace std;

class Bitacora{
    private:
        string mes, dia, hora, IP, puerto, problemID;

        int clave;

    public:
        string getMes();
        string getDia();
        int generarClave();
        int getClave();
        Bitacora(string m, string d, string h, string ip,
                 string puer, string pID);
    };

#endif
