#include "ListaSimple.hpp"

template <typename T>
class Pila{ //Stack
    ListaSimple<T> * pila;
    public:
        Pila(){
            this->pila=new ListaSimple<T>();
        }
        void push(T valor){
            this->pila->agregarInicio(valor);
        }

        NodoT<T> * pop(){
            return this->pila->eliminarInicio();
        }       

        NodoT<T> * top(){
            return this->pila->getHead(); 
        }

        void imprimirPila(){
            this->pila->imprimirLista();
        }

};