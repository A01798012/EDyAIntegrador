#include "NodoGrafo.hpp"
#include <vector>


template <typename T>
class Grafo{
    private:
        int tam;
        ListaSimple<NodoGrafo<T> *> * nodos;
        vector<NodoGrafo<T>*> ipQueRecibenMasFallas;
        vector<NodoGrafo<T>*> ipQueGeneraMasFallas;
        int cantMayorFallasRecibidas;
        int cantMayorFallasGeneradas;
    public:
        Grafo(){
            this->tam=0;
            this->nodos = new ListaSimple<NodoGrafo<T> *>();
            this->ipQueRecibenMasFallas = {};
            this->ipQueGeneraMasFallas = {};
            this->cantMayorFallasRecibidas = 0;
            this->cantMayorFallasGeneradas = 0;
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
            }//else
//                cout<<"Nodo existente"<<endl;
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
        void agregarArcoAlt(T valorNodoOrigen, T valorNodoDestino){
            NodoGrafo<T> * origen=this->buscarNodoGrafo(valorNodoOrigen);
            NodoGrafo<T> * destino=this->buscarNodoGrafo(valorNodoDestino);
            NodoT<Arco<T>*>* arcosOrigen = origen->getArcos()->getHead();
            Arco<T>* arcoNuevo = nullptr;
            while(arcosOrigen){
                if(arcosOrigen->getDato()->getValor() == destino->getValor()){
                    arcoNuevo = arcosOrigen->getDato();
                    break;
                }
                arcosOrigen = arcosOrigen->getSiguiente();
            }
            if(!arcoNuevo){
                //arcoNuevo = new Arco<T>(valorNodoDestino, 1);
                origen->getArcos()->agregarInicio(new Arco<T>(valorNodoDestino, 1));
            }else{
                arcoNuevo->setPeso(arcoNuevo->getPeso() + 1);
            }
            origen->setCantidadFallasGeneradas(origen->getCantidadFallasGeneradas()+1);
            destino->setCantidadFallasRecibidas(destino->getCantidadFallasRecibidas()+1);
            //cout << "o: " << origen->getValor() << "=" << origen->getCantidadFallasGeneradas() << " d: " << destino->getValor() << "="<< destino->getCantidadFallasRecibidas() << endl;

            if(origen->getCantidadFallasGeneradas() > this->cantMayorFallasGeneradas){
                this->ipQueGeneraMasFallas = {};
                this->ipQueGeneraMasFallas.push_back(origen);
                this->cantMayorFallasGeneradas = origen->getCantidadFallasGeneradas();
            }else if(origen->getCantidadFallasGeneradas() == this->cantMayorFallasGeneradas)
                this->ipQueGeneraMasFallas.push_back(origen);

            if(destino->getCantidadFallasRecibidas() > this->cantMayorFallasRecibidas){
                this->ipQueRecibenMasFallas= {};
                this->ipQueRecibenMasFallas.push_back(destino);
                this->cantMayorFallasRecibidas = destino->getCantidadFallasRecibidas();
            }else if(destino->getCantidadFallasRecibidas() == this->cantMayorFallasRecibidas)
                this->ipQueRecibenMasFallas.push_back(destino);

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
                    cout << lista->getDato()->getValor() << "[" << lista->getDato()->getPeso()<<"]" << "->";
                    lista = lista->getSiguiente();
                }
                cout << "\n";
                actual = actual->getSiguiente();
            }
        }

        void imprimirMasFallasGeneradas(){
            cout << "El maximo numero de fallas generadas fue " << this->cantMayorFallasGeneradas <<" por:  ";
            for(NodoGrafo<T>* nodo: this->ipQueGeneraMasFallas){
                cout << nodo->getValor() << " ";
            }
            cout << "\n";
        }
        void imprimirMasFallasRecibidas(){
            cout << "El maximo numero de fallas recibidas fue " << this->cantMayorFallasRecibidas << " en: ";
            for(NodoGrafo<T>* nodo: this->ipQueRecibenMasFallas){
                cout << nodo->getValor() << " ";
            }
            cout << "\n";

        }
    
};
