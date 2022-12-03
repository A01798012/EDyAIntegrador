#include "NodoGrafo.hpp"

template <typename T>
class Grafo{
    private:
        int tam;
        ListaSimple<NodoGrafo<T> *> * nodos;
    public:
        Grafo(){
            this->tam=0;
            this->nodos = new ListaSimple<NodoGrafo<T> *>();
        }
        //buscarNodoGrafo

        NodoGrafo<T> * buscarNodoGrafo(T valor){
            NodoT<NodoGrafo<T>*> * actual= this->nodos->getHead();
            while(actual){
                //Busqueda del valor dentro de los NodoT
                if(actual->getDato()->getValor()==valor)
                    return actual->getDato();
                actual=actual->getSiguiente();
            }
            return nullptr;
        }

        //insertarNodoGrafo
        void insertarNodoGrafo(T valor){
            //Si el nodo no existe
            if(!this->buscarNodoGrafo(valor)){
                this->nodos->agregarInicio(new NodoGrafo<T>(valor));
                this->tam++;
            }else
                cout<<"Nodo existente"<<endl;
        }

        //AgregarArco
        void agregarArco(T valorNodoOrigen, T valorNodoDestino, int peso){
            //Validar la existencia de los nodos origen y destino
            NodoGrafo<T> * origen=this->buscarNodoGrafo(valorNodoOrigen);
            NodoGrafo<T> * destino=this->buscarNodoGrafo(valorNodoDestino);
            if(origen&&destino)
                origen->getArcos()->agregarInicio(new Arco<T>(valorNodoDestino,peso));
            else    
                cout<<"Ambos nodos origen y destino deben de existir"<<endl;
        }

        //Imprimir grafo
        /*
        void imprimirGrafo(){
            NodoT<NodoGrafo<T>*> * actual = this->nodos->getHead();
            while(actual){
                cout << actual->getDato()->getValor() << ": ";
                ListaSimple<Arco<T>*>* arcosActuales = actual->getDato()->getArcos();
                NodoT<Arco<T>*>* lista = arcosActuales->getHead();
                while(lista){
                    cout << lista->getDato()->getValor() << "->";
                    lista = lista->getSiguiente();
                }
                cout << endl;
                actual = actual->getSiguiente();
            }
        }
        */

        void imprimirGrafo(){
            NodoT<NodoGrafo<T>*>* actual = nodos->getHead();
            while(actual){
                cout << actual->getDato()->getValor() << "->";
                NodoT<Arco<T>*>*lista = actual->getDato()->getArcos()->getHead();
                while(lista){
                    cout << lista->getDato()->getValor() << "->";
                    lista = lista->getSiguiente();
                }
                cout << "\n";
                actual = actual->getSiguiente();
            }
        }
    
};
