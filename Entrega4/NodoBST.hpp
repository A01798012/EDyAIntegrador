#include <iostream>
using namespace std;

template <typename T>
class NodoBST
{
private:
    T dato;
    NodoBST<T> *izq;
    NodoBST<T> *der;
    NodoBST<T> *padre;

public:
    T getDato() { return this->dato; }
    NodoBST<T> *getIzq() { return this->izq; }
    NodoBST<T> *getDer() { return this->der; }
    NodoBST<T> *getPadre() { return this->padre; }
    void setDato(T dato) { this->dato = dato; }
    void setIzq(NodoBST<T> *izq) { this->izq = izq; }
    void setDer(NodoBST<T> *der) { this->der = der; }
    void setPadre(NodoBST<T> *padre) { this->padre = padre; }

    // Constructores
    NodoBST(NodoBST<T> *padre, T dato)
    {
        this->padre = padre;
        this->dato = dato;
    }

    //-Destructores
    ~NodoBST()
    {
        cout << "Destrucción" << endl;
    }

    static void recorridoPreOrden(NodoBST<T> *actual)
    {
        if (actual)
        {
            cout << actual->getDato()->getCantidad() << " ";
            recorridoPreOrden(actual->getIzq());
            recorridoPreOrden(actual->getDer());
        }
    }

    static void recorridoInOrden(NodoBST<T> *actual)
    {
        if (actual)
        {
            recorridoInOrden(actual->getIzq());
            cout << actual->getDato()->getCantidad() << " ";
            recorridoInOrden(actual->getDer());
        }
    }

    static void recorridoPostOrden(NodoBST<T> *actual)
    {
        if (actual)
        {
            recorridoPostOrden(actual->getIzq());
            recorridoPostOrden(actual->getDer());
            cout << actual->getDato() << " ";
        }
    }

    static NodoBST<T> *valorMayor(NodoBST<T> *actual)
    {
        if (actual)
            while (actual->getDer())
                actual = actual->getDer();
        return actual;
    }
};