#include "NodoBST.hpp"

template<class T>
T NodoBST<T>::getDato(){return this->dato;}

template<class T>
NodoBST<T> * NodoBST<T>::getIzq(){return this->izq;}

template<class T>
NodoBST<T> * NodoBST<T>::getDer(){return this->der;}

template<class T>
NodoBST<T> * NodoBST<T>::getPadre(){return this->padre;}

template<class T>
void NodoBST<T>::setDato(T dato){this->dato=dato;}

template<class T>
void NodoBST<T>::setIzq(NodoBST<T> * izq){this->izq=izq;}

template<class T>
void NodoBST<T>::setDer(NodoBST<T> * der){this->der=der;}

template<class T>
void NodoBST<T>::setPadre(NodoBST<T> * padre){this->padre=padre;}

//Constructores
template<class T>
NodoBST<T>::NodoBST(NodoBST<T> * padre, T dato){
    this->padre=padre;
    this->dato=dato;
}

//-Destructores
template<class T>
NodoBST<T>::~NodoBST(){
    cout<<"Destrucción"<<endl;
}

template<class T>
void NodoBST<T>::recorridoPreOrden(NodoBST<T> * actual){
    if(actual){
        cout << actual -> getDato() << " ";
        recorridoPreOrden(actual -> getIzq());
        recorridoPreOrden(actual -> getDer());
    }
}

template<class T>
void NodoBST<T>::recorridoPostorden(NodoBST<T> * actual){
    if(actual){
        recorridoPostorden(actual -> getIzq());
        recorridoPostorden(actual -> getDer());
        cout << actual -> getDato() << " ";
    }
}

template<class T>
void NodoBST<T>::recorridoOrden(NodoBST<T> * actual){
    if(actual){
        recorridoOrden(actual -> getIzq());
        cout << actual -> getDato() << " ";
        recorridoOrden(actual -> getDer());
    }
}

template<class T>
NodoBST<T> * NodoBST<T>::valorMayor(NodoBST<T> * actual){
    if(actual)
    while(actual->getDer())
        actual = actual ->getDer();
    return actual
}