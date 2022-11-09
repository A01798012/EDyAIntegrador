#include <iostream>
//Listas

using namespace std;

class Nodo{
    //Atributos
    int valor;
    Nodo * siguiente;
    Nodo * anterior;
    public:
        //get
        int getValor(){return this->valor;}
        Nodo * getSiguiente(){return this->siguiente;}
        Nodo * getAnterior(){return this->anterior;}
        //set
        void setValor(int valor){this->valor=valor;}
        void setSiguiente(Nodo * siguiente){this->siguiente=siguiente;}
        void setAnterior(Nodo * anterior){this->anterior=anterior;}
        //constructor
        Nodo(int valor,Nodo * siguiente,Nodo *anterior){
            this->valor=valor;
            this->siguiente=siguiente;
            this->anterior=anterior;
        }
};

class ListaDL{
    Nodo * head;
    int tam;
    public:
        Nodo * getHead(){return this->head;}
        int getTam(){return this->tam;}
        void setHead(Nodo * head){this->head=head;}
        void setTam(int tam){this->tam=tam;}

        ListaDL(){
            this->head=nullptr;
            this->tam=0;
        }

        void agregarInicio(int valor){
            Nodo * nuevo=new Nodo(valor,this->getHead(),nullptr); // Creando el nuevo nodo
            if(this->getHead())
                this->getHead()->setAnterior(nuevo);
            this->setHead(nuevo); //Actualizar la head de la lista
            this->setTam(this->getTam()+1); //Actualizamos el tamaño
        }

        void agregarFinal(int valor){
            Nodo * nuevo=new Nodo(valor,nullptr,nullptr);
            Nodo * elemento=this->getHead();
            while(elemento->getSiguiente()){
               elemento=elemento->getSiguiente();
            }
            elemento->setSiguiente(nuevo);
            nuevo->setAnterior(elemento);
        }
        
        void imprimirLista(){
            Nodo * elemento=this->getHead();
            while(elemento){
                cout<<elemento->getValor()<<" ";
                elemento=elemento->getSiguiente();
            }
            cout<<endl;
        }

        void imprimirListaRev(){
            Nodo * elemento=this->getHead();
            while(elemento->getSiguiente())
                elemento=elemento->getSiguiente();
            

            while(elemento){
                cout<<elemento->getValor()<<" ";
                elemento=elemento->getAnterior();
            }
            cout<<endl;
        }

};