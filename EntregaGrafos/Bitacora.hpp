#ifndef BITACORA_H_
#define BITACORA_H_
#include <string>
#include <fstream>
#include "Grafo.hpp"
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
            }

            datos.close();



    }



};



#endif // BITACORA_H_
