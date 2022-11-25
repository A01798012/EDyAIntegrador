#ifndef LISTACDL_HPP_
#define LISTACDL_HPP_
#include <iostream>
#include "Nodo.hpp"
using namespace std;

template <typename T>
class ListaCDL{
    int tam;
    Nodo<T> *head;
    public:
        int getTam(){return this->tam;}
        Nodo<T> * getHead(){return this->head;}
        void setN(int tam){this->tam=tam;}
        void setHead(Nodo<T> * head){this->head=head;}
        ListaCDL(){
            this->tam=0;
            this->head=nullptr;
        };
        
        void agregarVacio(T val){
            Nodo<T> * nuevo =new Nodo<T>(val,nullptr,nullptr);
            nuevo->setSiguiente(nuevo);
            nuevo->setAnterior(nuevo);
            this->head=nuevo;
        }
        
        void agregarInicio(T val){
            
            if(this->head!=nullptr){
                Nodo<T> * nuevo =new Nodo<T>(val,this->head,this->head->getAnterior());
                this->head->getAnterior()->setSiguiente(nuevo);
                this->head->setAnterior(nuevo);
                this->head=nuevo;
            }else{               
                this->agregarVacio(val);                
            }
            this->tam++;
        }

        void agregarFinal(T val){
            if(this->head){
                Nodo<T> * nuevo =new Nodo<T>(val,this->head,this->head->getAnterior());
                this->head->getAnterior()->setSiguiente(nuevo);
                this->head->setAnterior(nuevo);
            }else{
                this->agregarVacio(val);
            }
            this->tam++;
        }
        void imprimirLista(){
            if(this->head){
                Nodo<T> * elemento=this->head;
                do{
                    cout<<elemento->getDato()<<endl;
                    elemento=elemento->getSiguiente();

                }while(elemento!=this->head);
                cout<<endl;
            }else{
                cout<<"Lista vacía"<<endl;
            }   
        }

        void imprimirLista1(){
            if(this->head){
                Nodo<T> * elemento=this->head;
                do{
                    cout<<*elemento->getDato()<<endl;
                    elemento=elemento->getSiguiente();

                }while(elemento!=this->head);
                cout<<endl;
            }else{
                cout<<"Lista vacía"<<endl;
            }   
        }

        void imprimirListaReversa(){
            if(this->head){
                Nodo<T> * elemento=this->head->getAnterior();
                do{
                    cout<<elemento->getDato()<<endl;
                    elemento=elemento->getAnterior();

                }while(elemento!=this->head->getAnterior());
                cout<<endl;
            }else{
                cout<<"Lista vacía"<<endl;
            }   
        }

        Nodo<T> *read(T dato){
            Nodo<T> *nodo = this->head;
            int i = 0;
            bool existe = false;
            while (i < tam){
                if (nodo->getDato() == dato){
                    return nodo;
                }
                nodo = nodo->getSiguiente();
                i++;
            }
            return nullptr;
    }

};

#endif
