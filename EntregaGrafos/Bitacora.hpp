#ifndef BITACORA_H_
#define BITACORA_H_
#include <string>
#include <fstream>
#include "Grafo.hpp"
#include <unistd.h>
using namespace std;

class Bitacora{
    private:
        Grafo<string>* grafoDeIps;
    public:
        Bitacora(){
            grafoDeIps = new Grafo<string>();
        }
        void leerYCrearGrafo(string direccionArchivo){

            ifstream datos;
            datos.open(direccionArchivo);
            string mes,dia,hora,ipOrigen, ipDestino,puerto,falla;
            while(datos.good()){
                getline(datos,mes,' ');
                getline(datos,dia,' ');
                getline(datos,hora,' ');
                getline(datos,ipOrigen,' ');
                getline(datos,ipDestino,' ');
                getline(datos,falla);
                if(datos.eof()) break;
                this->grafoDeIps->insertarNodoGrafo(ipOrigen);
                this->grafoDeIps->insertarNodoGrafo(ipDestino);
                this->grafoDeIps->agregarArco(ipOrigen, ipDestino);
            }

            datos.close();



    }
        void imprimirBitacora(){
            this->grafoDeIps->imprimirGrafo();
        }

        void imprimirFallasRecibidas(){
            this->grafoDeIps->imprimirMasFallasRecibidas();
        }
        void imprimirFallasGeneradas(){
            this->grafoDeIps->imprimirMasFallasGeneradas();
        }
        void guardarDFS(string direccionArchivo){
            ofstream archivo(direccionArchivo);
            archivo << this->grafoDeIps->DepthFirst(grafoDeIps->getLista()->getHead()->getDato());
            archivo.close();
        }

        void generarImagenGrafo(string direccionArchivoImagen){

            string archivoGrafoDot = "grafo.dot";

            ofstream archivoCodigoGrafo(archivoGrafoDot);
            archivoCodigoGrafo << this->grafoDeIps->obtenerVisualGrafoDot();
            archivoCodigoGrafo.close();

            system(("dot -Tpng " + archivoGrafoDot + " -o "+direccionArchivoImagen).data());
        }
};



#endif // BITACORA_H_
