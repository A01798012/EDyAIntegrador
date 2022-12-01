#include <string>
#include "Bitacora.hpp"

using namespace std;

int main()
{

    string archivoBitacora = "bitacoraPrueba.txt";
    string archivoAccesos = "accesos.txt";

    // PUNTOS 1 Y 2:
    Bitacora bitacora; // En el stack puesto que solo habrá una bitácora
    bitacora.leerArchivo(archivoBitacora);

    // PUNTO 3:
    bitacora.guardarNumAccesoIps(archivoAccesos);

    // PUNTO 4:
    bitacora.crearArbol();

    // PUNTO 5:
    bitacora.imprimirPorNumAccesos(1);
    bitacora.imprimirPorNumAccesos(5);
    bitacora.imprimirPorNumAccesos(28);
    bitacora.imprimirPorNumAccesos(4);
    bitacora.imprimirPorNumAccesos(15);
    bitacora.imprimirPorNumAccesos(26);

    // IMPRESION DE ARBOL
    bitacora.imprimirArbol();

    return 0;
}
