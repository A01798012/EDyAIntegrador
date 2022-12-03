#ifndef   NODET
#define   NODET


#include <iostream>
using namespace std;


template <typename T>  //T va almacer el tipo de dato 
class NodoT{
    T dato;
    NodoT * siguiente;
    public:
        T getDato(){return this->dato;}
        void setDato(T dato){this->dato=dato;}
        NodoT * getSiguiente(){return this->siguiente;}
        void setSiguiente(NodoT * siguiente){this->siguiente=siguiente;}
    
    NodoT(){
        this->dato=NULL;
    }

    NodoT(T dato,NodoT * siguiente){
        this->dato=dato;
        this->siguiente=siguiente;
    }
};

#endif