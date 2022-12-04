#include "Arco.hpp"

#include "ListaSimple.hpp"

template <typename T>
class NodoGrafo{
    private:
        T valor;
        ListaSimple<Arco<T> *> * arcos;
        bool procesado;
        int cantidadFallasRecibidas;
        int cantidadFallasGeneradas;
        
    public:
        T getValor(){return this->valor;}
        ListaSimple<Arco<T>*> * getArcos(){return this->arcos;}
        bool getProcesado(){return this->procesado;}
        void setProcesado(bool procesado){this->procesado=procesado;}
        NodoGrafo(T valor){
            this->valor=valor;
            this->arcos= new ListaSimple<Arco<T>*>();
            this->procesado=false;
            this->cantidadFallasGeneradas = 0;
            this->cantidadFallasRecibidas = 0;
        }
        int getCantidadFallasRecibidas(){return this->cantidadFallasRecibidas;}
        int getCantidadFallasGeneradas(){return this->cantidadFallasGeneradas;}
        void setCantidadFallasRecibidas(int cantidadFallasRecibidas){this->cantidadFallasRecibidas = cantidadFallasRecibidas;}
        void setCantidadFallasGeneradas(int cantidadFallasGeneradas){this->cantidadFallasGeneradas= cantidadFallasGeneradas;}
};
