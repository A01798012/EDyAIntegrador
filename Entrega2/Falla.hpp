#include <iostream>
#include <string>
using namespace std;

class Falla{
    private:
        string nombre;
        int num;

    public:
        string getNombre(){return this -> nombre;}
        int getNum(){return this -> num;}
        void setNombre(string nombre){this -> nombre = nombre;}
        void setNum(int num){this -> num = num;}
        Falla(){
            this -> nombre = "nada";
            this -> num = 0;
        }
        Falla(string nombre, int num){
            this -> nombre = nombre;
            this -> num = num;
        }
};