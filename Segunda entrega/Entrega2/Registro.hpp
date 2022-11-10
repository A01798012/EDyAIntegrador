#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>

using namespace std;

class Registro{
    private:
        string mes, dia, hora, IP, puerto, problemID;

        int clave;

    public:
        string getMes();
        string getDia();
        string getHora();
        string getIP();
        string getPuerto();
        string getProblemID();
        int generarClave();
        int getClave();
        string display();

        Registro(string mes, string dia, string hora, string IP,
                 string puerto, string problemID);
        
    };

#endif
