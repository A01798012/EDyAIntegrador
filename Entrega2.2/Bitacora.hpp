#ifndef BITACORA_HPP_
#define BITACORA_HPP_

#include <vector>
#include <string>
#include "Registro.hpp"
#include "listasCDL.hpp"
#include "listasdl.hpp"
#include "Falla.hpp"


using namespace std;

class Bitacora{
    private:
        ListaCDL<Registro*> registros;
        //TODO implementar en el cpp
        ListaDL<Falla*> fallas;
        int particionQuickSort(int inicio, int fin);
        int busquedaBinaria(int clave, int n);
        int buscarInicio(int clave, int n);
        int buscarFinal(int clave, int n);

    public:
        Bitacora();
        int getTotalRegistros();
        void leerArchivo(string direccionArchivo);
        void ordenarQuickSort(int inicio, int fin);
        void displayAndWriteAll(string direccionArchivo);
        void displayAndWriteRange(int fechaInicio, int fechaFin, string direccionArchivo);
};

#endif
