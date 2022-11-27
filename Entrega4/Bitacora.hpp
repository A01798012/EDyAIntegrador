#ifndef BITACORA_HPP_
#define BITACORA_HPP_

#include <string>
#include <vector>
#include "Registro.hpp"
#include "ListaCDL.hpp"
#include "ListaDL.hpp"
#include "Falla.hpp"
#include "Ip.hpp"


using namespace std;

class Bitacora{
    private:
        ListaCDL<Registro*> * registros;
        ListaDL<Falla*> * fallas;
        ListaDL<Ip*>* direccionesIp;


    public:
        Bitacora();
        int getTotalRegistros();
        void leerArchivo(string direccionArchivo);
        void almacenarFallas();
        void almacenarDireccionesIp();
        void imprimirYGuardarPorFalla(string tipoDeFalla, string direccionArchivo);
        void imprimirYGuardarPorHora(string hora, string direccionArchivo);
        void imprimirFallas();
        void imprimirDireccionesIp();
        void imprimirRegistros();
};

#endif
