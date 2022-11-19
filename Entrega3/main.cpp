#include "BST.hpp"
//hola

int main(){
    BST<int> * arbol1 = new BST<int>();
//    BST<int> * arbol4 = new BST<int>();
    int a1[7] = {21, 13, 10, 18, 33, 25, 40};

    for(int i = 0; i <  7; i++) arbol1->agregarNodo(a1[i]);

    cout << "######################### EJEMPLO 1 #########################\n";

    cout << "Altura: " << arbol1 ->getAltura() << endl;
    arbol1->agregarNodo(44);
    cout << "Altura: " << arbol1 ->getAltura() << endl;
    arbol1->imprimirPreOrder();
    arbol1->imprimirInOrder();
    arbol1->imprimirPostOrder();
    arbol1->imprimirLevelByLevel();
    arbol1->eliminarNodo(18);
    arbol1->imprimirLevelByLevel();
    arbol1->whatLevelAmI(10);
    arbol1->eliminarNodo(13);
    arbol1->whatLevelAmI(10);
    arbol1->imprimirLevelByLevel();
    cout << "------------\n";
    arbol1->whatLevelAmI(44);
    arbol1->eliminarNodo(33);
    arbol1->whatLevelAmI(44);
    cout << "Altura: " << arbol1 ->getAltura() << endl;
    arbol1->imprimirInOrder();
    arbol1->eliminarNodo(17);

    arbol1->eliminarNodo(44);
    arbol1->imprimirPreOrder();
    arbol1->eliminarNodo(40);
    arbol1->imprimirPreOrder();
    arbol1->whatLevelAmI(10);
    arbol1->whatLevelAmI(25);
    arbol1->whatLevelAmI(21);
    cout << "Altura: " << arbol1 ->getAltura() << endl;
    arbol1->whatLevelAmI(2991);
    arbol1->imprimirLevelByLevel();





   

    return 0;
}
