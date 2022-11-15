#include "BST.hpp"


int main(){
    BST<int> * arbol = new BST<int>();
    /*arbol->agregarNodo(21);
    arbol->agregarNodo(13);
    arbol->agregarNodo(10);
    arbol->agregarNodo(18);
    arbol->agregarNodo(33);
    arbol->agregarNodo(25);
    arbol->agregarNodo(40);

    arbol->imprimirPreOrder();
    arbol->imprimirInOrder();
    arbol->imprimirPostOrder();
    */
    arbol->agregarNodo(21);
    arbol->agregarNodo(13);
    arbol->agregarNodo(10);
    arbol->agregarNodo(18);
    arbol->agregarNodo(33);
    arbol->agregarNodo(25);
    arbol->agregarNodo(40);
    cout << "Altura: " << arbol ->height() << endl;
    arbol->agregarNodo(44);
    cout << "Altura: " << arbol ->height() << endl;
    arbol->imprimirPreOrder();
    arbol->imprimirInOrder();
    arbol->imprimirPostOrder();
    arbol->eliminarNodo(18);
    arbol->imprimirInOrder();
    arbol->eliminarNodo(13);
    arbol->imprimirInOrder();
    arbol->eliminarNodo(33);
    arbol->imprimirInOrder();
    arbol->eliminarNodo(17);


   

    return 0;
}