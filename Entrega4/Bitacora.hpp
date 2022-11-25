#ifndef BITACORA_H
#define BITACORA_H

#include <vector>
#include <string>
#include "Registro.hpp"


using namespace std;

class Bitacora{
    private:
        vector<Registro*> registros;
        int particionQuickSort(int inicio, int fin);
        int busquedaBinaria(int clave, int n);
        int buscarInicio(int clave, int n);
        int buscarFinal(int clave, int n);

    public:
        Bitacora();
        int getTotalRegistros();
        void leerArchivo(string direccionArchivo);
        void contarIP();
        void ordenarQuickSort(int inicio, int fin);
        void displayAndWriteAll(string direccionArchivo);
        void displayAndWriteRange(int fechaInicio, int fechaFin, string direccionArchivo);
};

#endif
