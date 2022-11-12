#include <iostream>
#include <string>
#include "Bitacora.hpp"


using namespace std;

int main() {

//    string archivoLectura = "bitacoraSecundaria.txt";
    string archivoLectura = "bitacoraPrincipal.txt";
    string archivoConsultaPorFalla = "consultaPorFalla.txt";
    string archivoConsultaPorHora = "consultaPorHora.txt";

    // PUNTO 1:
    Bitacora bitacora; // En el stack puesto que solo habrá una bitácora
    bitacora.leerArchivo(archivoLectura);

    // PUNTO 2:
    bitacora.almacenarFallas();

    // PUNTOS 3 y 4:
    string fallaPedida;
    cout << "Los tipos de fallas son:\n\n";
    bitacora.imprimirFallas();
    cout << "Ingrese el tipo de falla a buscar: ";
    getline(cin, fallaPedida);
    cout << endl;
    bitacora.imprimirYGuardarPorFalla(fallaPedida, archivoConsultaPorFalla);

    // PUNTOS 5 Y 6:
    string horaPedida;
    cout << endl << "Ingrese la hora a buscar (01,13,21,etc): ";
    cin >> horaPedida;
    cout << endl;
    bitacora.imprimirYGuardarPorHora(horaPedida, archivoConsultaPorHora);

    return 0;
}
