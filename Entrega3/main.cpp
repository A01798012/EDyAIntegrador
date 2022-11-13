#include "BST.hpp"


int main(){
    BST<int> * arbol = new BST<int>();
    arbol -> agregarNodo(21);
    arbol -> agregarNodo(13);
    arbol -> agregarNodo(10);
    arbol -> agregarNodo(18);
    arbol -> agregarNodo(33);
    arbol -> agregarNodo(25);
    arbol -> agregarNodo(2);
    return 0;
}