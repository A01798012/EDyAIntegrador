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
        Bitacora(string mes, string dia, string hora, string IP,
                 string puerto, string problemID);
    };

#endif
