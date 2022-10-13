#include <iostream>
#include <string>

#include "Bitacora.hpp"

using namespace std;

int main() {

    string archivoLectura = "bitacoraPrincipal.txt";
    string archivoBitacoraOrdenada = "ordenamiento.txt";
    string archivoBitacoraBusqueda = "busqueda.txt";

    Bitacora bitacora; //En el stack puesto que solo habrá una bitácora
    bitacora.leerArchivo(archivoLectura);
    bitacora.ordenarQuickSort(0, bitacora.getTotalRegistros()-1);

    cout<<"REGISTROS ORDENADOS:"<<endl;
    bitacora.displayAndWriteAll(archivoBitacoraOrdenada);

    cout << endl <<"IMPORTANTE: INGRESA LAS FECHAS SIGUIENDO EL FORMATO MMDD"<<endl;
    cout << "EJEMPLO: ENERO 26 = 0126"<<endl<<endl;

    string inicio, fin;

    cout << "Ingresa la fecha de inicio para la búsqueda: ";
    cin >> inicio;
    cout << "Ingresa la fecha de fin para la búsqueda: ";
    cin >> fin;

    cout << endl;

    cout << "MOSTRANDO LOS REGISTROS DEL " << inicio<<" AL "<<fin<< " :"<< endl;
    bitacora.displayAndWriteRange(stoi(inicio), stoi(fin), archivoBitacoraBusqueda);

    return 0;
}
