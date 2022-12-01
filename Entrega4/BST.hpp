#include "NodoBST.hpp"
#include "Ip.hpp"
#include "Acceso.hpp"

template <typename T>
class BST
{
private:
    NodoBST<T> *raiz;
    int numNodos;

public:
    BST()
    {
        this->raiz = nullptr;
        this->numNodos = 0;
    }

    // getters y setters
    NodoBST<T> *getRaiz() { return this->raiz; }
    int getNumNodos() { return this->numNodos; }
    void setRaiz(NodoBST<T> *raiz) { this->raiz = raiz; }
    void setNumNodos(int numNodos) { this->numNodos = numNodos; }

    void agregarNodo(Ip *dato)
    {
        /*Función para agregar un Nodo al arbol
        Complejidad : O(nivel)*/

        NodoBST<T> *actual = this->raiz;
        NodoBST<T> *padre;
        if (this->raiz)
        { // Arbol no esta vacio

            NodoBST<T> *nodoExistente = this->buscarNodo(dato->getCantidad());

            if (nodoExistente)
            { // YA EXISTE EL NODO
                nodoExistente->getDato()->agregarIp(dato->getDireccionIp());
            }
            else
            {
                // Encontrar al nodo padre
                while (actual)
                {
                    padre = actual;
                    // Relación de orden (izq menor o der mayor)
                    if (*(actual->getDato()) > dato)
                        actual = actual->getIzq();

                    else
                        actual = actual->getDer();
                }

                Acceso *nuevoAcceso = new Acceso(dato);
                NodoBST<T> *nuevoNodo = new NodoBST<T>(padre, nuevoAcceso);
                *(padre->getDato()) > dato ? padre->setIzq(nuevoNodo) : padre->setDer(nuevoNodo);
                this->numNodos++;
            }
        }
        else
        { // Arbol esta vacio
            Acceso *nuevoAcceso = new Acceso(dato);
            NodoBST<T> *nuevoNodo = new NodoBST<T>(nullptr, nuevoAcceso);
            this->raiz = nuevoNodo;
            this->numNodos++;
        }
    }

    NodoBST<T> *buscarNodo(int dato)
    {
        /*Función para buscar un Nodo en el arbol
        Complejidad : O(nivel)*/

        // Crear el apuntado a nodo raiz
        NodoBST<T> *actual = this->raiz;
        while (actual)
        {
            // Si el dato del nodo actual es el valor que busco
            if (*(actual->getDato()) == dato)
                return actual;
            else
                actual = *(actual->getDato()) > dato ? actual->getIzq() : actual->getDer();
        }
        return nullptr;
    }

    void imprimirPreOrder()
    {
        /*Función para imprimir el árbol en preorden
        Complejidad : O(n)*/
        NodoBST<T>::recorridoPreOrden(this->raiz);
        cout << endl;
    }

    void imprimirInOrder()
    {
        /*Función para imprimir el árbol en orden
        Complejidad : O(n)*/

        NodoBST<T>::recorridoInOrden(this->raiz);
        cout << endl;
    }
};