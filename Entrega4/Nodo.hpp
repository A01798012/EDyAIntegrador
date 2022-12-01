#ifndef NODO_H_
#define NODO_H_

template <typename T>
class Nodo
{
    // Atributos
    T dato;
    Nodo<T> *siguiente;
    Nodo<T> *anterior;

public:
    // get
    T getDato() { return this->dato; }
    Nodo<T> *getSiguiente() { return this->siguiente; }
    Nodo<T> *getAnterior() { return this->anterior; }
    // set
    void setDato(T dato) { this->dato = dato; }
    void setSiguiente(Nodo<T> *siguiente) { this->siguiente = siguiente; }
    void setAnterior(Nodo<T> *anterior) { this->anterior = anterior; }
    // constructor
    Nodo(T dato, Nodo<T> *siguiente, Nodo<T> *anterior)
    {
        this->dato = dato;
        this->siguiente = siguiente;
        this->anterior = anterior;
    }
};

#endif // NODO_H_
