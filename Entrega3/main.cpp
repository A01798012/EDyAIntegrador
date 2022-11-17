#include "BST.hpp"


int main(){
    BST<int> * arbol1 = new BST<int>();
    BST<int> * arbol2 = new BST<int>();
    BST<int> * arbol3 = new BST<int>();
    BST<int> * arbol4 = new BST<int>();
    int a1[7] = {21, 13, 10, 18, 33, 25, 40};
    int a2[10] =  {38, 31, 35, 8, 57, 28, 3, 12, 65, 56};
    int a3[10] = {80, 55, 57, 59, 60, 81, 32, 63, 28, 30};
    int a4[15] = {-5, 66, -4, 38, -46, 53, -25, -1, -2, -26, -66, 59, -69, -52, 1};

    for(int i = 0; i <  7; i++) arbol1->agregarNodo(a1[i]);
    for(int i = 0; i <  10; i++) arbol2->agregarNodo(a2[i]);
    for(int i = 0; i <  10; i++) arbol3->agregarNodo(a3[i]);
    for(int i = 0; i <  15; i++) arbol4->agregarNodo(a4[i]);
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
    /*
    cout << "Altura: " << arbol1 ->getAltura() << endl;
    arbol1->agregarNodo(44);
    cout << "Altura: " << arbol1 ->getAltura() << endl;
    arbol1->imprimirPreOrder();
    arbol1->imprimirInOrder();
    arbol1->imprimirPostOrder();
    arbol1->eliminarNodo(18);
    arbol1->imprimirInOrder();
    arbol1->eliminarNodo(13);
    arbol1->imprimirInOrder();
    arbol1->eliminarNodo(33);
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
    */
    arbol4->agregarNodo(-100);
    arbol4->agregarNodo(0);
    arbol4->imprimirPreOrder();
    arbol4->whatLevelAmI(-66);
    arbol4->whatLevelAmI(-69);
    arbol4->whatLevelAmI(-100);
    arbol4->whatLevelAmI(-52);

    arbol4->eliminarNodo(-66);

    arbol4->whatLevelAmI(-69);
    arbol4->whatLevelAmI(-100);
    arbol4->whatLevelAmI(-52);

    cout << "\n";

    arbol4->whatLevelAmI(38);
    arbol4->whatLevelAmI(1);
    arbol4->whatLevelAmI(0);
    arbol4->whatLevelAmI(-2);

    arbol4->eliminarNodo(38);

    arbol4->whatLevelAmI(1);
    arbol4->whatLevelAmI(0);
    arbol4->whatLevelAmI(-2);

   

    return 0;
}
