#include "Bitacora.hpp"
#include "Registro.hpp"
#include "Nodo.hpp"
#include "Falla.hpp"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

Bitacora::Bitacora(){
    this->registros = new ListaCDL<Registro *>();
    this->fallas = new ListaDL<Falla *>();
}

int Bitacora::getTotalRegistros(){return this->registros->getTam();}

void Bitacora::leerArchivo(string direccionArchivo){
/*Función para leer un archivo .txt y almacenar los registros en la
lista circular doblemente ligada (registros) de la bitacora 
Complejidad: O(n)
*/

    ifstream datos;
    datos.open(direccionArchivo);
    string mes,dia,hora,ip,puerto,falla;

    while(datos.good()){
        getline(datos,mes,' ');
        getline(datos,dia,' ');
        getline(datos,hora,' ');
        getline(datos,ip,':');
        getline(datos,puerto,' ');
        getline(datos, falla);

        if (falla.back()=='\r'){
            falla.pop_back();
        }
        this->registros->agregarFinal(new Registro(mes,dia,hora,ip,puerto,falla));
    }

    datos.close();

}

void Bitacora::almacenarFallas(){
/*Función para almacenar los distintos tipos de fallas en la
lista doblemente ligada (fallas) conforme los registros almacenados en la
lista circular doblemente ligada (registros)
Si ya existe un fallo del mismo tipo (mensaje), simplemente se manda a
aumentar la ocurrencia conforme el mes
Si no existe un fallo del mismo tipo (mensaje), se crea un nuevo tipo
de fallo y se agrega a la lista de fallos (con su mes inicial)
Complejidad: O(n^2)
*/

    Nodo <Registro *> * registroActual = this->registros->getHead();

    for (int i = 0; i < this->getTotalRegistros(); i++){

        bool yaExisteFalla=false;

        Nodo <Falla *> *fallaActual = this->fallas->getHead();

        for (int j = 0; j < this->fallas->getTam(); j++){
            
            if (registroActual->getDato()->getProblemID()==fallaActual->getDato()->getMensaje()){

                yaExisteFalla=true;
                fallaActual->getDato()->agregarOcurrencia(registroActual->getDato()->getMes());
                break;
            }

            fallaActual = fallaActual->getSiguiente();
        }

        if (!yaExisteFalla){

            Falla * nuevaFalla = new Falla(registroActual->getDato()->getMes(), registroActual->getDato()->getProblemID());
            this->fallas->agregarInicio(nuevaFalla);
        }

        registroActual=registroActual->getSiguiente();
    }
}

void Bitacora::almacenarDireccionesIp(){
    Nodo <Registro *> * registroActual = this->registros->getHead();

    for (int i = 0; i < this->getTotalRegistros(); i++){

        bool yaExisteFalla=false;

        Nodo <Ip *> *ipActual = this->direccionesIp->getHead();

        for (int j = 0; j < this->fallas->getTam(); j++){
            
            if (registroActual->getDato()->getIP()==ipActual->getDato()->getdireccionIp()){

                yaExisteFalla=true;
                ipActual->getDato()->setCantidad(ipActual->getDato()->getCanidad()+1);
                break;
            }

            ipActual = ipActual->getSiguiente();
        }

        if (!yaExisteFalla){

            Ip * nuevaIp = new Ip(registroActual->getDato()->getIP(), 1);
            this->direccionesIp->agregarInicio(nuevaIp);
        }

        registroActual=registroActual->getSiguiente();
    }
}

void Bitacora::imprimirYGuardarPorFalla(string tipoDeFalla, string direccionArchivo){
/*Función para imprimir en terminal y guardar en un archivo todas
las ocurrencias de un tipo de falla en específico de la bitacora
Complejidad: O(n)
*/

    Nodo<Falla *> *fallaActual = this->fallas->getHead();

    ofstream archivo(direccionArchivo);


    for (int i = 0; i < this->fallas->getTam(); i++) {

        if (fallaActual->getDato()->getMensaje()==tipoDeFalla){

            cout << fallaActual->getDato()->display();
            archivo << fallaActual->getDato()->display();

            archivo.close();
            return; 
        }

        fallaActual=fallaActual->getSiguiente();
    }

    
    cout << "No existe ningún registro con la falla: " << tipoDeFalla << endl;
    archivo << "No existe ningún registro con la falla: " << tipoDeFalla << endl;

    archivo.close();
}

void Bitacora::imprimirFallas(){ 
    //Complejidad: O(n)
    Nodo<Falla*> * fallaActual = this->fallas->getHead();
    for(int i = 0; i < this->fallas->getTam(); i++){
        cout << fallaActual->getDato()->getMensaje() << "\n";
        fallaActual = fallaActual->getSiguiente();
    }
    cout << "\n";
}

void Bitacora::imprimirYGuardarPorHora(string hora, string direccionArchivo){
/*Función para imprimir en terminal y guardar en un archivo todos
los registros de la bitacora que sucedieron en una hora en específico
Complejidad: O(n)
*/

    Nodo<Registro *> *registroActual = this->registros->getHead();

    ofstream archivo(direccionArchivo);

    for (int i = 0; i < this->getTotalRegistros(); i++){

        string horaRegistroActual = registroActual->getDato()->getHora().substr(0, 2);

        if (horaRegistroActual==hora){
            cout << registroActual->getDato()->display();
            archivo << registroActual->getDato()->display();
        }

        registroActual=registroActual->getSiguiente();

    }
}

void Bitacora::imprimirRegistros(){
    /*Esta funcion imprime los registros
    Complejidad = O(n)
    */
    Nodo<Registro *> *registroActual = this->registros->getHead();
    for(int i = 0; i < this -> registros -> getTam(); i++){
        cout << registroActual -> getDato() ->display();
        registroActual = registroActual -> getSiguiente();
    }
    cout<<endl;

}