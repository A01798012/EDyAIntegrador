#include "NodoGrafo.hpp"
#include <vector>
#include <stack>
#include <sstream>

template <typename T>
class Grafo{
    private:
        int tam;
        ListaSimple<NodoGrafo<T> *> * nodos;
        vector<NodoGrafo<T>*> ipQueRecibenMasFallas;
        vector<NodoGrafo<T>*> ipQueGeneraMasFallas;
        int cantMayorFallasRecibidas;
        int cantMayorFallasGeneradas;
        int mayorPesoArcos;

        string obtenerColorGradiente(int peso){
            /*En formato hex
            DE VERDE A ROJO
            VERDE = ARCO CON PESO DE 1
            ROJO = ARCO CON MAYOR PESO*/

            float inicioGradiente[3] = {0, 255, 0};
            float finalGradiente[3] = {255, 0, 0};

            float porcentaje = float(peso) / float(this->mayorPesoArcos);
            float porcentajeInverso = 1 - porcentaje;
            int r, g, b;
            r = (porcentaje * finalGradiente[0]) + (porcentajeInverso * inicioGradiente[0]);
            g = (porcentaje * finalGradiente[1]) + (porcentajeInverso * inicioGradiente[1]);
            b = (porcentaje * finalGradiente[2]) + (porcentajeInverso * inicioGradiente[2]);

            // Conversión a hex
            char hexColor[8];
            snprintf(hexColor, 8, "#%02x%02x%02x", r, g, b);
            return hexColor;
        }

    public:
        Grafo(){
            this->tam=0;
            this->nodos = new ListaSimple<NodoGrafo<T> *>();
            this->ipQueRecibenMasFallas = {};
            this->ipQueGeneraMasFallas = {};
            this->cantMayorFallasRecibidas = 0;
            this->cantMayorFallasGeneradas = 0;
            this->mayorPesoArcos = 0;
        }

        ListaSimple<NodoGrafo<T> *> * getLista(){
            return this -> nodos;
        }
        
        //buscarNodoGrafo
        NodoGrafo<T> * buscarNodoGrafo(T valor){
            //Complejidad O(n)
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
            // Complejidad O(n) por la búsqueda del nodo
            // O(1) la acción de insertar el nodo
            //Si el nodo no existe
            if(!this->buscarNodoGrafo(valor)){
                this->nodos->agregarInicio(new NodoGrafo<T>(valor));
                this->tam++;
            }//else
//                cout<<"Nodo existente"<<endl;
        }

        void agregarArco(T valorNodoOrigen, T valorNodoDestino){
            // Complejidad O(nxm)
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
                arcoNuevo = new Arco<T>(valorNodoDestino, 1);
                origen->getArcos()->agregarInicio(arcoNuevo);
            }else{
                arcoNuevo->setPeso(arcoNuevo->getPeso() + 1);
            }

            if (arcoNuevo->getPeso() > this->mayorPesoArcos)
                this->mayorPesoArcos = arcoNuevo->getPeso();

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

        void imprimirGrafo(){
            // Complejidad O(nxm)
            NodoT<NodoGrafo<T>*>* actual = nodos->getHead();
            while(actual){
                cout << actual->getDato()->getValor() << ": ";
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
            // Complejidad O(1)
            cout << "El maximo numero de fallas generadas fue " << this->cantMayorFallasGeneradas <<" por:  ";
            for(NodoGrafo<T>* nodo: this->ipQueGeneraMasFallas){
                cout << nodo->getValor() << " ";
            }
            cout << "\n";
        }
        void imprimirMasFallasRecibidas(){
            // Complejidad O(1)
            cout << "El maximo numero de fallas recibidas fue " << this->cantMayorFallasRecibidas << " en: ";
            for(NodoGrafo<T>* nodo: this->ipQueRecibenMasFallas){
                cout << nodo->getValor() << " ";
            }
            cout << "\n";

        }

        string DepthFirst(NodoGrafo<T> * nodoG){
            // Complejidad O(n)
            string recorrido = "";

            //Verificamos que el grafo tenga nodos
            int cont = 0;
            if(this -> nodos ->getHead()){
                //Creo la pila
                stack<NodoGrafo<T>*> pila;
                pila.push(nodoG);
                while (!pila.empty()){
                    NodoGrafo<T> * aux = pila.top();
                    pila.pop();
                    if(aux->getProcesado()==false){
                        //Tostring
                        recorrido += aux->getValor() + " -> ";
                        aux->setProcesado(true);
                    }
                    NodoT<Arco<T>*> * nodeT = aux -> getArcos() -> getHead();
                    while (nodeT){
                        
                        NodoGrafo<T> * vecino = this -> buscarNodoGrafo(nodeT->getDato()->getValor());

                        if(vecino->getProcesado()==false){
                            pila.push(vecino);
                        }
                        nodeT = nodeT -> getSiguiente();
                    }
                }
                recorrido += '\n';
            }else{
                recorrido += "Grafo vacio\n";
            }

            return recorrido;
        }

        string obtenerVisualGrafoDot(){
            // Complejidad O(nxm)
            /*Función para obtener un código .dot para generar un visual del gráfico
            devuelve un string con el código*/

            string codigo = "digraph G {\n";

            for(NodoGrafo<T>* nodo: this->ipQueRecibenMasFallas){
                codigo += "\"" + nodo->getValor() + "\" [height=1.5 width=1.5 shape=doublecircle color=blue];" + "\n";
            }

            for(NodoGrafo<T>* nodo: this->ipQueGeneraMasFallas){
                codigo += "\"" + nodo->getValor() + "\" [height=1.5 width=1.5 shape=doubleoctagon color=purple];" + "\n";
            }


            NodoT<NodoGrafo<T> *> *actual = nodos->getHead();
            while (actual)
            {
                string ipOrigen = actual->getDato()->getValor();
                NodoT<Arco<T> *> *lista = actual->getDato()->getArcos()->getHead();
                while (lista)
                {
                    string ipDestino = lista->getDato()->getValor();
                    int pesoArco = lista->getDato()->getPeso();
                    string colorArco = obtenerColorGradiente(pesoArco);
                    codigo += "\"" + ipOrigen + "\"" + " -> " + "\"" + ipDestino + "\" [" + "color=\"" + colorArco + "\"];" + "\n";
                    lista = lista->getSiguiente();
                }
                actual = actual->getSiguiente();
            }

            codigo += '}';

            return codigo;
        }
};
