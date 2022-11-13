#include "NodoBST.hpp"

template <typename T>
class BST{
    private:
        NodoBST<T> * raiz;
        int numNodos;
    public:
        NodoBST<T> * getRaiz();
        void setRaiz(NodoBST<T> *);
        int getNumNodos();
        void setNumNodos(int);

        BST();
        ~BST(); //Metodo destructor
        
        void agregarNodo(T);
        NodoBST<T> * buscarNodo(T);
        void imprimirPostOrden();
        void imprimirPreOrden();
        void imprimirOrden();
        void eliminarNodo(T);


};