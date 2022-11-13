#include "BST.hpp"

//Constructor
template<class T>
BST<T>::BST(){
    this->raiz=nullptr;
    this->numNodos=0;
}

//getters y setters
template<class T>
NodoBST<T> * BST<T>::getRaiz(){return this->raiz;}
template<class T>
int BST<T>::getNumNodos(){return this->numNodos;}
template<class T>
void BST<T>::setRaiz(NodoBST<T> * raiz){this->raiz=raiz;}
template<class T>
void BST<T>::setNumNodos(int numNodos){this->numNodos=numNodos;}

template<class T>
void BST<T>::agregarNodo(T dato){
    NodoBST<T> * actual =  this -> raiz;
    NodoBST<T> * padre;

    if(this -> buscarNodo(dato))
        cout << "Nodo existente" << endl;
    else{
        if(this -> raiz){ //Arbol no esta vacio
            //Encontrar al nodo padre
            while(actual){
                padre = actual;
                if(dato < actual->getDato())
                    actual = actual->getIzq();
                else
                    actual = actual->getDer();
            }
            padre->getDato() > dato ? padre -> setIzq(new NodoBST<T>(padre, dato)) : padre -> setDer(new NodoBST<T>(padre, dato)) 
        }else{ //Arbol esta vacio
            this -> raiz = new NodoBST<T>(nullptr, dato);
            this->numNodos++;
        }
    }
}

template<class T>
NodoBST<T> * BST<T>::buscarNodo(T dato){
    //Crear el apuntador a nodo raiz
    NodoBST<T> * actual = this -> raiz;
    while (actual){
        if(actual -> getDato() == dato)
            return actual;
        else
            actual = actual -> getDato() > dato ? actual->getIzq():actual->getDer();
    }
    return nullptr;   
}

template<class T>
void BST<T>::imprimirPreOrden(){
    NodoBST<T>::recorridoPostorden(this->raiz);
    cout<<endl;
}

template<class T>
void BST<T>::imprimirOrden(){
    NodoBST<T>::recorridoPostorden(this->raiz);
    cout<<endl;
}
template<class T>
void BST<T>::imprimirPostOrden(){
    NodoBST<T>::recorridoPostorden(this->raiz);
    cout<<endl;
}

template<class T>
void BST<T>::eliminarNodo(T dato){
    NodoBST<T> * eliminar = this -> buscarNodo(dato);
    NodoBST<T> * padre = nullptr;
    if(eliminar){
        //Establecer el nodo padre
        padre = eliminar -> getPadre();
        //Caso 1: Eliminar un nodo hoja
        if(!eliminar->getIzq() && !eliminar -> getDer()){
            if(!padre)//Si el nodo a borrar es la raiz
                this -> raiz = nullptr;
            else if(padre -> getIzq() == eliminar)
                padre -> setIzq(nullptr);
            else
                padre -> setDer(nullptr);
            delete eliminar; 

        //Caso 2: nodo con hijo
        }else if ((eliminar -> getIzq() && !eliminar -> getDer()) || (!eliminar -> getIzq() && eliminar -> getDer())){ //Eliminar un nodo con hijo izquierdo
            //Actualizar apuntadores
            if(!padre)
                this -> raiz = eliminar -> getIzq() ? eliminar -> getIzq() : eliminar -> getDer();
            else if(padre -> getIzq() == eliminar) // El nodo con un hijo a eliminar es el izquierdo
                padre ->setIzq(eliminar -> getIzq() ? eliminar -> getIzq() : eliminar -> getDer());
            else // El nodo con un hijo a eliminar es el derecho
                padre ->setDer(eliminar -> getIzq() ? eliminar -> getIzq() : eliminar -> getDer());
            delete eliminar;
        }
        //Caso 3: Eliminar nodo con dos hijos
        else{
            NodoBST<T> * predecesor = NodoBST<T>::valorMayor(eliminar->getIzq());
            eliminar -> setDato(predecesor);
            if(predecesor -> padre -> getIzq() == predecesor){
                predecesor -> padre ->setIzq(predecesor->getIzq() ? predecesor -> getIzq : nullptr);
            }else {
                predecesor -> padre ->setDer(predecesor->getIzq() ? predecesor -> getIzq : nullptr);
            }
            delete predecesor;
        }
        this -> numNodos--;
    }else if(padre -> getIzq() == eliminar){
        cout << "Valor a eliminar"
    }
}