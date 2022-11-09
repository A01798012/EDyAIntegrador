#include <iostream>
//Listas

using namespace std;

template <typename T>
class NodoA{
    //Atributos
    T dato;
    NodoA<T> * siguiente;
    NodoA<T> * anterior;
    public:
        //get
        T getDato(){return this->dato;}
        NodoA<T> * getSiguiente(){return this->siguiente;}
        NodoA<T> * getAnterior(){return this->anterior;}
        //set
        void setDato(T dato){this->dato=dato;}
        void setSiguiente(NodoA<T> * siguiente){this->siguiente=siguiente;}
        void setAnterior(NodoA<T> * anterior){this->anterior=anterior;}
        //constructor
        NodoA(T dato, NodoA<T> * siguiente,NodoA<T> *anterior){
            this->dato=dato;
            this->siguiente=siguiente;
            this->anterior=anterior;
        }
};

template <typename T>
class ListaDL{
    NodoA<T> * head;
    int tam;
    public:
        NodoA<T> * getHead(){return this->head;}
        int getTam(){return this->tam;}
        void setHead(NodoA<T> * head){this->head=head;}
        void setTam(int tam){this->tam=tam;}

        ListaDL(){
            this->head=nullptr;
            this->tam=0;
        }

        void agregarInicio(T valor){
            NodoA<T> * nuevo=new NodoA<T>(valor,this->getHead(),nullptr); // Creando el nuevo nodo
            if(this->getHead())
                this->getHead()->setAnterior(nuevo);
            this->setHead(nuevo); //Actualizar la head de la lista
            this->setTam(this->getTam()+1); //Actualizamos el tamaño
        }

        void agregarFinal(T valor){
            NodoA<T> * nuevo=new NodoA<T>(valor,nullptr,nullptr);
            NodoA<T> * elemento=this->getHead();
            while(elemento->getSiguiente()){
               elemento=elemento->getSiguiente();
            }
            elemento->setSiguiente(nuevo);
            nuevo->setAnterior(elemento);
            this->setTam(this->getTam()+1);
        }

        NodoA<T> *read(T dato)//O(n)
        {
        NodoA<T> *nodo = this->head;
        int i = 0;
        bool existe = false;
        while (i < tam)
        {
            if (nodo->getDato() == dato)
            {
                return nodo;
            }
            nodo = nodo->getSiguiente();
            i++;
        }
        return nullptr;
    }
        
        void imprimirLista(){
            NodoA<T> * elemento=this->getHead();
            while(elemento){
                cout<<elemento->getValor()<<" ";
                elemento=elemento->getSiguiente();
            }
            cout<<endl;
        }

        void imprimirListaRev(){
            NodoA<T> * elemento=this->getHead();
            while(elemento->getSiguiente())
                elemento=elemento->getSiguiente();
            

            while(elemento){
                cout<<elemento->getValor()<<" ";
                elemento=elemento->getAnterior();
            }
            cout<<endl;
        }

};