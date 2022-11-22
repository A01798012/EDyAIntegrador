#include "BST.hpp"
//hola

int main(){
    BST<int> * arbol1 = new BST<int>();
    BST<int> * arbol4 = new BST<int>();
    int a1[7] = {21, 13, 10, 18, 33, 25, 40};
    int a4[15] = {-5, 66, -4, 38, -46, 53, -25, -1, -2, -26, -66, 59, -69, -52, 1};

    for(int i = 0; i <  7; i++) arbol1->agregarNodo(a1[i]);
    for(int i = 0; i <  15; i++) arbol4->agregarNodo(a4[i]);





    cout << "############  ARBOL 1 ############\n";
    arbol1-> visit(1);
    arbol1-> visit(2);
    arbol1-> visit(3);
    cout << endl;
    cout << "Altura: " << arbol1 ->getAltura() << endl;
    cout << "El sucesor del 33 es: " << arbol1->sucesor(33)->getDato() << endl;
    arbol1->whatLevelAmI(25);
    cout << endl;

    arbol1->eliminarNodo(33);
    arbol1-> visit(1);
    arbol1-> visit(2);
    arbol1-> visit(3);
    cout << "Altura: " << arbol1 ->getAltura() << endl;
    cout << "El sucesor del 25 es: " << arbol1->sucesor(25)->getDato() << endl;
    arbol1->whatLevelAmI(25); // 2 WLA
    cout << endl;

    arbol1->whatLevelAmI(40);
    arbol1->eliminarNodo(25);
    arbol1-> visit(1);
    arbol1-> visit(2);
    arbol1-> visit(3);
    cout << "Altura: " << arbol1 ->getAltura() << endl; // 2 A
    cout << "El sucesor del 13 es: " << arbol1->sucesor(13)->getDato() << endl; // 2 S
    cout << "El sucesor del 21 es: " << arbol1->sucesor(21)->getDato() << endl; // 3 S
    arbol1->whatLevelAmI(40);
    cout << endl;

    arbol1->eliminarNodo(18);
    arbol1->eliminarNodo(10);
    arbol1-> visit(1);
    arbol1-> visit(2);
    arbol1-> visit(3);
    cout << "Altura: " << arbol1 ->getAltura() << endl; // 2 A
    arbol1->sucesor(13);
    cout << "El sucesor del 21 es: " << arbol1->sucesor(21)->getDato() << endl; // 3 S
    arbol1->whatLevelAmI(13);
    cout << endl;



    return 0;
}
