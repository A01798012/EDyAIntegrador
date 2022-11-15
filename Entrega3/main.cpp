#include "BST.hpp"


int main(){
    BST<int> * arbol1 = new BST<int>();
    BST<int> * arbol2 = new BST<int>();
    BST<int> * arbol3 = new BST<int>();
    BST<int> * arbol4 = new BST<int>();
    int a1[7] = {21, 13, 10, 18, 33, 25, 40};
    int a2[15] =  {3, 14, 21, 22, 25, 27, 30, 33, 43, 47, 59, 60, 63, 78, 89};
    int a3[15] = {-48, -45, -41, -40, -35, -15, -8, -5, 3, 4, 12, 14, 17, 25, 38};
    int a4[8] = {29, 34, 42, 46, 47, 50, 53, 60};

    for(int i = 0; i <  7; i++) arbol1->agregarNodo(a1[i]);
    for(int i = 0; i <  15; i++) arbol2->agregarNodo(a2[i]);
    for(int i = 0; i <  15; i++) arbol3->agregarNodo(a3[i]);
    for(int i = 0; i <  8; i++) arbol4->agregarNodo(a4[i]);
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
    cout << "Altura: " << arbol1 ->height() << endl;
    arbol1->agregarNodo(44);
    cout << "Altura: " << arbol1 ->height() << endl;
    arbol1->imprimirPreOrder();
    arbol1->imprimirInOrder();
    arbol1->imprimirPostOrder();
    arbol1->eliminarNodo(18);
    arbol1->imprimirInOrder();
    arbol1->eliminarNodo(13);
    arbol1->imprimirInOrder();
    arbol1->eliminarNodo(33);
    cout << "Altura: " << arbol1 ->height() << endl;
    arbol1->imprimirInOrder();
    arbol1->eliminarNodo(17);

    arbol1->eliminarNodo(44);
    arbol1->imprimirPreOrder();
    arbol1->eliminarNodo(40);
    arbol1->imprimirPreOrder();
    arbol1->whatLevelAmI(10);
    arbol1->whatLevelAmI(25);
    arbol1->whatLevelAmI(21);
    cout << "Altura: " << arbol1 ->height() << endl;


   

    return 0;
}
