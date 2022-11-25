#ifndef BITACORA_HPP_
#define BITACORA_HPP_

#include <string>
#include "Registro.hpp"
#include "ListaCDL.hpp"
#include "ListaDL.hpp"
#include "Falla.hpp"


using namespace std;

class Bitacora{
    private:
        ListaCDL<Registro*> * registros;
        ListaDL<Falla*> * fallas;

    public:
        Bitacora();
        int getTotalRegistros();
        void leerArchivo(string direccionArchivo);
        void almacenarFallas();
        void imprimirYGuardarPorFalla(string tipoDeFalla, string direccionArchivo);
        void imprimirYGuardarPorHora(string hora, string direccionArchivo);
        void imprimirFallas();
        void imprimirRegistros();
};

#endif
