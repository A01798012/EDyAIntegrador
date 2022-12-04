//Representar el arco de un nodo origen a un nodo destino con su peso
template <typename T>
class Arco{
    private:
        T valorNodoDestino;
        int peso;
    public: 
        Arco(T valorNodoDestino,int peso){
            this->valorNodoDestino=valorNodoDestino;
            this->peso=peso;
        }
        T getValor(){return this->valorNodoDestino;}
        int getPeso(){return this->peso;}
        void setPeso(int peso){this->peso = peso;}
};
