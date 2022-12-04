#include "Bitacora.hpp"


int main(){
    string archivo = "bitacoraTest1.txt";
    Bitacora kk;

    kk.leerYCrearGrafo(archivo);
    kk.imprimirBitacora();

    kk.imprimirFallasGeneradas();
    kk.imprimirFallasRecibidas();


}
