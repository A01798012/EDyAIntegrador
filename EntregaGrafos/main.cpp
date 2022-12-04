#include "Bitacora.hpp"


int main(){
    string archivo = "bitacoraCompleta1.txt";
    Bitacora kk;

    kk.leerYCrearGrafo(archivo);
    kk.imprimirBitacora();

    kk.imprimirFallasGeneradas();
    kk.imprimirFallasRecibidas();
    kk.DFS();
}
