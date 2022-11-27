#include <iostream>
#include <string>
#include "Bitacora.hpp"


using namespace std;

int main() {

//    string archivoLectura = "bitacoraPrincipal.txt";
    string archivoLectura = "bitacoraSecundaria.txt";
    string archivoConsultaPorFalla = "consultaPorFalla.txt";
    string archivoConsultaPorHora = "consultaPorHora.txt";

    // PUNTO 1:
    Bitacora bitacora; // En el stack puesto que solo habrá una bitácora
    bitacora.leerArchivo(archivoLectura);

    //IMPRIME REGISTRO
    //bitacora.imprimirRegistros();

    // PUNTO 2:
 //   bitacora.almacenarFallas();
    bitacora.almacenarDireccionesIp();
    bitacora.imprimirDireccionesIp();

    // PUNTOS 3 y 4:
    

    return 0;
}
