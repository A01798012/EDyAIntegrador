#ifndef FALLA_HPP_
#define FALLA_HPP_
#include <iostream>
#include <string>
using namespace std;

class Falla{
    private:
        string mensaje;
        int cantidad;
        int ocurrenciasPorMes[12] = {0};
    public:
        Falla();
        Falla(string mesFallaInicial, string mensaje);
        string getMensaje();
        void agregarOcurrencia(string mesDeLaFalla);
        string display();
};

#endif
