#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class NodoBST{
    private:
        T dato;
        NodoBST<T> * izq;
        NodoBST<T> * der;
        NodoBST<T> * padre;
        int nivel;
    public:
        T getDato(){return this->dato;}        
        NodoBST<T> * getIzq(){return this->izq;}       
        NodoBST<T> * getDer(){return this->der;}      
        NodoBST<T> * getPadre(){return this->padre;}
        int getNivel(){return this->nivel;}
        void setDato(T dato){this->dato=dato;}
        void setIzq(NodoBST<T> * izq){this->izq=izq;}
        void setDer(NodoBST<T> * der){this->der=der;}
        void setPadre(NodoBST<T> * padre){this->padre=padre;}
        void setNivel(int nivel){this->nivel =nivel;}

        //Constructores        
        NodoBST(NodoBST<T> * padre, T dato, int nivel){
            this->padre=padre;
            this->dato=dato;
            this -> nivel = nivel;
        }

        //-Destructores
        ~NodoBST(){
            cout<<"Destrucción"<<endl;
        }

        static void recorridoPreOrden(NodoBST<T> * actual){
            if(actual){//O(n)
                cout<<actual->getDato()<<" ";
                recorridoPreOrden(actual->getIzq());
                recorridoPreOrden(actual->getDer());
            }
        }

        static void recorridoInOrden(NodoBST<T> * actual){
            if(actual){//O(n)
                recorridoInOrden(actual->getIzq());
                cout<<actual->getDato()<<" ";
                recorridoInOrden(actual->getDer());
            }
        }

        static void recorridoPostOrden(NodoBST<T> * actual){
            if(actual){//O(n)
                recorridoPostOrden(actual->getIzq());
                recorridoPostOrden(actual->getDer());
                cout<<actual->getDato()<<" ";
            }
        }
        static void recorridoLevelByLevel(NodoBST<T>* raiz){
            if(raiz){//O(n)
                queue<NodoBST<T>*> cola;
                cola.push(raiz);
                while(!cola.empty()){
                    if(cola.front()->getIzq())
                        cola.push(cola.front()->getIzq());
                    if(cola.front()->getDer())
                        cola.push(cola.front()->getDer());
                    cout << cola.front()->getDato() << " ";
                    cola.pop();
                }
            }
        }

        static NodoBST<T> * valorMayor(NodoBST<T> *actual){//O(n)
            if(actual)
                while(actual->getDer())
                    actual=actual->getDer();
            return actual;
        }
};
