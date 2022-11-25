#include "Bitacora.hpp"
#include "Registro.hpp"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

Bitacora::Bitacora(){}
int Bitacora::getTotalRegistros(){return this->registros.size();}

void Bitacora::leerArchivo(string direccionArchivo){

    ifstream datos;
    datos.open(direccionArchivo);
    string mes,dia,hora,ip,puerto,falla;

    while(datos.good()){
        getline(datos,mes,' ');
        getline(datos,dia,' ');
        getline(datos,hora,' ');
        getline(datos,ip,':');
        getline(datos,puerto,' ');
        getline(datos,falla);
        this->registros.push_back(new Registro(mes,dia,hora,ip,puerto,falla));
    }

    datos.close();

}



int Bitacora::particionQuickSort(int inicio, int fin){
    int pivote = this->registros[inicio]->getClave();
    int indicePivote = fin + 1;

    for (int j = fin; j > inicio; j--){
        if (this->registros[j]->getClave() > pivote){
            indicePivote--;
            std::swap(this->registros[indicePivote], this->registros[j]);
        }
    }
    indicePivote--;
    std::swap(this->registros[indicePivote], this->registros[inicio]);
    return indicePivote;
}

void Bitacora::ordenarQuickSort(int inicio, int fin){
    //Caso recursivo
    if (inicio<fin){
        int pivote = particionQuickSort(inicio, fin);
        // particion izquierda
        ordenarQuickSort(inicio, pivote - 1);
        // particion derecha
        ordenarQuickSort(pivote + 1, fin);
    }
}

int Bitacora::busquedaBinaria(int clave, int n){
    int inicio,mitad,fin, valorCentral;
    inicio=0;
    //ya se le resto uno al size()
    fin=n;
    while(inicio<=fin){
        mitad=(inicio+fin)/2;
        valorCentral = this->registros[mitad]->getClave();
        if(clave==valorCentral)
            return mitad;
        else if(clave<valorCentral) //izq
            fin=mitad-1;
        else //der
            inicio=mitad+1;
    }
    return -1;
}

void Bitacora::displayAndWriteRange(int fechaInicio, int fechaFin, string direccionArchivo){

    int tam = this->getTotalRegistros() - 1;

    if(fechaInicio <= fechaFin && fechaFin <= this->registros[tam]->getClave() && fechaInicio >= this->registros[0]->getClave()){
        ofstream archivo(direccionArchivo);
        int indiceInicio = -1;
        while(indiceInicio == -1){
            indiceInicio = busquedaBinaria(fechaInicio, tam);
            fechaInicio++;
        }

        for (int i = indiceInicio; i <= tam; i++){
            if(this->registros[i]->getClave() > fechaFin){
                break;
            }else{
                cout << this->registros[i]->display();
                archivo << this->registros[i]->display();
            }

        }
    }else if(fechaInicio > fechaFin)
        cout << "ERROR DE FORMATO: La fecha de inicio no puede ser mayor a la fecha final" << endl;
    else if(fechaFin > this->registros[tam]->getClave())
        cout << "ERROR DE FORMATO: La fecha final excede la fecha de registros" << endl;
    else if(fechaInicio < this->registros[0]->getClave())
        cout << "ERROR DE FORMATO: La fecha de inicio es menor a la fecha de registros" << endl;
}
void Bitacora::displayAndWriteAll(string direccionArchivo){

    ofstream archivo(direccionArchivo);

    for (int i=0; i < this->registros.size(); i++){

        cout << this->registros[i]->display();
        archivo << this->registros[i]->display();

    }

    archivo.close();
}
