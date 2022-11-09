#include <iostream>
#include <string>
#include <fstream>
#include "Bitacora.hpp"
#include "listasCDL.hpp"
#include "listasdl.hpp"
#include "Falla.hpp"

using namespace std;


int main() {

    bool flag = true;
    vector<Registro*> b;

    string archivoLectura = "bitacoraPrincipal.txt";
    string archivoBitacoraOrdenada = "ordenamiento.txt";
    string archivoBitacoraBusqueda = "busqueda.txt";

    Bitacora bitacora; //En el stack puesto que solo habrá una bitácora
    
    b = bitacora.leerArchivo(archivoLectura);

    //Ejercicio 1
    
    ifstream datos;
    datos.open(archivoLectura);
    string mes,dia,hora,ip,puerto,falla;
    ListaCDL<Registro*> * list = new ListaCDL<Registro*>();
    ListaDL<Falla*> * fail = new ListaDL<Falla*>();

    while(datos.good()){
        getline(datos,mes,' ');
        getline(datos,dia,' ');
        getline(datos,hora,' ');
        getline(datos,ip,':');
        getline(datos,puerto,' ');
        getline(datos,falla);
        list -> agregarFinal(new Registro(mes,dia,hora,ip,puerto,falla));
    }
    datos.close();

    Nodo<Registro *> * elemento = list -> getHead();
    for(int i = 0; i < list ->getTam(); i++){
        cout << elemento -> getDato() -> display(); 
        elemento = elemento -> getSiguiente();
    }

    // Comparamos y ponemos los datos

    Nodo<Registro *> * pointer = list -> getHead();
    fail -> agregarInicio(new Falla(pointer -> getDato() -> getProblemID(), 1));
    pointer = pointer -> getSiguiente();

    NodoA<Falla *> * point = fail -> getHead();

    cout << endl;

    bool fg = true;
    int a = 0;
    string hi, original, nuevo;

    for(int i = 0; i < list -> getTam()-1; i++){
        //cout << "*********************** "<< "i: " << i << " ***********************"<<endl;
        for(int j = 0; j < fail -> getTam(); j++){
            //cout << "j: " << j << endl;
            
            original = pointer -> getDato() -> getProblemID();
            nuevo = point -> getDato() -> getNombre();

            /*cout << original + "." << endl;
            cout << nuevo + "."<< endl;
            cout << (original == nuevo) << endl;
            cout << endl;*/
            if((pointer -> getDato() -> getProblemID()) == (point -> getDato() ->getNombre())){
                //cout << "IF"<< endl;
                a = point -> getDato() ->getNum() + 1;
                point -> getDato() -> setNum(a);
                fg = false;
            }         
            point = point -> getSiguiente();
        }
        if (fg){
                hi = pointer -> getDato() -> getProblemID();
                fail ->agregarFinal(new Falla(hi, 1));  
            }
        pointer = pointer -> getSiguiente();
        point = fail -> getHead();
        fg = true;
    }

    cout << "Tamanio final: "<<fail -> getTam() <<endl;

    NodoA<Falla *> * help = fail -> getHead();

    for(int k = 0; k < fail -> getTam(); k++){
        cout << "Error: " << help -> getDato() ->getNombre() << endl;
        cout << "Cant: " << help -> getDato() ->getNum() << endl;
        cout << endl;
        help = help -> getSiguiente();
    }
    
    

    /////////////////////////////////////////////////////////////////////
    /**
    bitacora.ordenarQuickSort(0, bitacora.getTotalRegistros()-1);
    cout<<"REGISTROS ORDENADOS:"<<endl;
    bitacora.displayAndWriteAll(archivoBitacoraOrdenada);
    while(1){
        cout << endl <<"IMPORTANTE: INGRESA LAS FECHAS SIGUIENDO EL FORMATO MMDD"<<endl;
        cout << "EJEMPLO: ENERO 26 = 0126"<<endl<<endl;
        cout << "Si quiere salir del programa escriba -1" << endl;
        string inicio, fin;

        cout << "Ingresa la fecha de inicio para la búsqueda: ";
        cin >> inicio;
        if(stoi(inicio) == -1)
            break;
        cout << "Ingresa la fecha de fin para la búsqueda: ";
        cin >> fin;
        if(stoi(fin) == -1)
            break;

        cout << endl;

        cout << "MOSTRANDO LOS REGISTROS DEL " << inicio<<" AL "<<fin<< " :"<< endl;
        bitacora.displayAndWriteRange(stoi(inicio), stoi(fin), archivoBitacoraBusqueda);

    }
    */
    return 0;
}
