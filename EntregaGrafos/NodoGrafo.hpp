#include "Arco.hpp"

#include "ListaSimple.hpp"

template <typename T>
class NodoGrafo{
    private:
        T valor;
        ListaSimple<Arco<T> *> * arcos;
        bool procesado;
    public:
        T getValor(){return this->valor;}
        ListaSimple<Arco<T>*> * getArcos(){return this->arcos;}
        bool getProcesado(){return this->procesado;}
        void setProcesado(bool procesado){this->procesado=procesado;}
        NodoGrafo(T valor){
            this->valor=valor;
            this->arcos= new ListaSimple<Arco<T>*>();
            this->procesado=false;
        }

};