#include<iostream>
using namespace std;

template <typename T>
class NodoBST{
    private:
        T dato;
        NodoBST<T> * izq;
        NodoBST<T> * der;
        NodoBST<T> * padre;
    public:
        void setDato(T);
        void setIzq(NodoBST<T> *);
        void setDer(NodoBST<T> *);
        void setPadre(NodoBST<T> *);

        T getDato();
        NodoBST<T> * getIzq();
        NodoBST<T> * getDer();
        NodoBST<T> * getPadre();
        NodoBST(NodoBST<T> *, T); //new
        ~NodoBST();  // delete

        static void recorridoPreOrden(NodoBST<T>*);
        static void recorridoOrden(NodoBST<T>*);
        static void recorridoPostorden(NodoBST<T>*);

        static NodoBST<T> * valorMayor(NodoBST<T> * actual);

};