#ifndef LISTADL_HPP_
#define LISTADL_HPP_
#include <iostream>
#include "Nodo.hpp"
// Listas

using namespace std;

template <typename T>
class ListaDL
{
    Nodo<T> *head;
    int tam;

public:
    Nodo<T> *getHead() { return this->head; }
    int getTam() { return this->tam; }
    void setHead(Nodo<T> *head) { this->head = head; }
    void setTam(int tam) { this->tam = tam; }

    ListaDL()
    {
        this->head = nullptr;
        this->tam = 0;
    }

    void agregarInicio(T valor)
    {
        Nodo<T> *nuevo = new Nodo<T>(valor, this->getHead(), nullptr); // Creando el nuevo nodo
        if (this->getHead())
            this->getHead()->setAnterior(nuevo);
        this->setHead(nuevo);             // Actualizar la head de la lista
        this->setTam(this->getTam() + 1); // Actualizamos el tamaño
    }

    void agregarFinal(T valor)
    {
        Nodo<T> *nuevo = new Nodo<T>(valor, nullptr, nullptr);
        Nodo<T> *elemento = this->getHead();
        while (elemento->getSiguiente())
        {
            elemento = elemento->getSiguiente();
        }
        elemento->setSiguiente(nuevo);
        nuevo->setAnterior(elemento);
        this->setTam(this->getTam() + 1);
    }

    Nodo<T> *read(T dato) // O(n)
    {
        Nodo<T> *nodo = this->head;
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

    void imprimirLista()
    {
        Nodo<T> *elemento = this->getHead();
        while (elemento)
        {
            cout << elemento->getDato() << " ";
            elemento = elemento->getSiguiente();
        }
        cout << endl;
    }

    void imprimirListaRev()
    {
        Nodo<T> *elemento = this->getHead();
        while (elemento->getSiguiente())
            elemento = elemento->getSiguiente();

        while (elemento)
        {
            cout << elemento->getValor() << " ";
            elemento = elemento->getAnterior();
        }
        cout << endl;
    }
};
#endif
