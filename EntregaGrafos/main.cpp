#include "Bitacora.hpp"

int main()
{
    string archivo = "bitacoraTest1.txt";
    string archivoDFS = "dfs.txt";
    string archivoImagen = "bitacoraGrafo.png";
    Bitacora bitacora;
    
    // PUNTOS 1 Y 2:
    bitacora.leerYCrearGrafo(archivo);

    cout << "\nIMPRESIÓN DEL GRAFO:\n";
    bitacora.imprimirBitacora();

    // PUNTOS 3 Y 4:
    cout << "\n\n";
    bitacora.imprimirFallasGeneradas();
    bitacora.imprimirFallasRecibidas();

    // PUNTOS 5 Y 6;
    bitacora.guardarDFS(archivoDFS);

    char decision;
    cout << "\n*IMPORTANTE: ES NECESARIO TENER INSTALADA LA HERRAMIENTA GRAPHVIZ\n";
    cout << "https://graphviz.org/download/\n";
    cout << "¿Desea obtener una representación visual del grafo? (Y/N): ";
    cin >> decision;

    if (decision =='Y' || decision =='y'){
        bitacora.generarImagenGrafo(archivoImagen);
    }

    
}
