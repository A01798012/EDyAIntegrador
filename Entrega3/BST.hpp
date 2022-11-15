#include "NodoBST.hpp"

template <typename T>
class BST{
    private:
        NodoBST<T> * raiz;
        int numNodos;
        int altura;
    public:
        BST(){
            this->raiz=nullptr;
            this->numNodos=0;
            this->altura=0;
        }

        //getters y setters        
        NodoBST<T> * getRaiz(){return this->raiz;}        
        int getNumNodos(){return this->numNodos;}
        int getAltura(){return this->altura;}        
        void setRaiz(NodoBST<T> * raiz){this->raiz=raiz;}        
        void setNumNodos(int numNodos){this->numNodos=numNodos;}
        void setAltura(int altura){this->altura=altura;}
        
        void agregarNodo(T dato){
            NodoBST<T> * actual = this->raiz;
            NodoBST<T> * padre;
            if(this->raiz){ //Arbol no esta vacio
                if(this->buscarNodo(dato))//
                    cout<<"Nodo existente"<<endl;
                else{
                    //Encontrar al nodo padre
                    while(actual){
                        padre=actual;
                        //Relación de orden (izq menor o der mayor)
                        if(dato<actual->getDato())
                            actual=actual->getIzq();
                        else
                            actual=actual->getDer();
                    }
                    //En esta linea modificamos para que el nivel siempre sea el del padre +1
                    padre->getDato()>dato?padre->setIzq(new NodoBST<T>(padre,dato,(padre->getNivel())+1)):padre->setDer(new NodoBST<T>(padre,dato,(padre->getNivel())+1));
                    this->numNodos++;
                    //Si el nivel del nodo agregado es mayor a la altura agragarlo
                    if(buscarNodo(dato)->getNivel() > altura){
                        altura = buscarNodo(dato)->getNivel();
                    }
                }
            }else{ //Arbol esta vacio
                this->raiz= new NodoBST<T>(nullptr,dato,0);
                this->numNodos++;
            } 
        }

        NodoBST<T> * buscarNodo(T dato){
            //Crear el apuntado a nodo raiz
            NodoBST<T> * actual = this->raiz;
            while(actual){
                //Si el dato del nodo actual es el valor que busco
                if(actual->getDato()==dato)
                    return actual;
                else
                    actual=actual->getDato()>dato?actual->getIzq():actual->getDer();        
            }
            return nullptr;
        }

        void whatLevelAmI(T dato){
            NodoBST<T>* nodo = this->buscarNodo(dato);
            cout << "El dato " << dato << " se encuentra en el nivel: " << nodo->getNivel() << "\n";
        }

        void imprimirPreOrder(){
            NodoBST<T>::recorridoPreOrden(this->raiz);
            cout<<endl;
        }
        
        void imprimirInOrder(){
            NodoBST<T>::recorridoInOrden(this->raiz);
            cout<<endl;
        }
        
        void imprimirPostOrder(){
            NodoBST<T>::recorridoPostOrden(this->raiz);
            cout<<endl;
        }

        void eliminarNodo(T dato){
            NodoBST<T> * eliminar = this->buscarNodo(dato);
            NodoBST<T> * padre = nullptr;
            if(eliminar){
                //Establecer el nodo padre
                padre=eliminar->getPadre();
                //Caso 1: eliminar un nodo hoja
                if(!eliminar->getIzq()&&!eliminar->getDer()){
                    //Actualizar la referencia del padre
                    if(!padre) //Si el nodo a borrar es la raiz
                        this->raiz=nullptr;
                    else if(padre->getIzq()==eliminar)
                        padre->setIzq(nullptr);
                    else
                        padre->setDer(nullptr);
                    delete eliminar;
                //Caso 2: nodo con un hijo            
                }else if((eliminar->getIzq()&&!eliminar->getDer())||(!eliminar->getIzq()&&eliminar->getDer())){
                    //Actualizar los apuntadores
                    if(!padre)
                        this->raiz=eliminar->getIzq()?eliminar->getIzq():eliminar->getDer();
                    else if(padre->getIzq()==eliminar) //El nodo cono un hijo a eliminar es el izq
                        padre->setIzq(eliminar->getIzq()?eliminar->getIzq():eliminar->getDer());
                    else
                        padre->setDer(eliminar->getIzq()?eliminar->getIzq():eliminar->getDer());
                    delete eliminar;
                //Caso 3: eliminar nodo con 2 hijos (predecesor)
                }else{
                    NodoBST<T> * predecesor = NodoBST<T>::valorMayor(eliminar->getIzq());
                    eliminar->setDato(predecesor->getDato());
                    if(predecesor->getPadre()->getIzq()==predecesor){ //el predecesor es hijo izq
                        predecesor->getPadre()->setIzq(predecesor->getIzq()?predecesor->getIzq():nullptr);
                    }else{
                        predecesor->getPadre()->setDer(predecesor->getIzq()?predecesor->getIzq():nullptr);
                    }
                    delete predecesor;
                }
                this->numNodos--;
            }else
                cout<<"Valor a eliminar inexistente"<<endl;    
        }

        int height(){
            return altura;
        }

};
