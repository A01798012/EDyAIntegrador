#include <iostream>
#include <string>
using namespace std;

class Falla{
    private:
        string nombre;
        int num;
        int fechas[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

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

        void modificarValor(string mes){
            if(mes == "Ene"){
                fechas[0] = fechas[0] + 1;
            }
            else if(mes == "Feb"){
                fechas[1] = fechas[1] + 1;
            }
            else if(mes == "Mar"){
                fechas[2] = fechas[2] + 1;
            }
            else if(mes == "Apr"){
                fechas[3] = fechas[3] + 1;
            }
            else if(mes == "May"){
                fechas[4] = fechas[4] + 1;
            }
            else if(mes == "Jun"){
                fechas[5] = fechas[5] + 1;
            }
            else if(mes == "Jul"){
                fechas[6] = fechas[6] + 1;
            }
            else if(mes == "Aug"){
                fechas[7] = fechas[7] + 1;
            }
            else if(mes == "Sep"){
                fechas[8] = fechas[8] + 1;
            }
            else if(mes == "Oct"){
                fechas[9] = fechas[9] + 1;
            }
            else if(mes == "Nov"){
                fechas[10] = fechas[10] + 1;
            }
            else if(mes == "Dec"){
                fechas[11] = fechas[11] + 1;
            }
        }
    
        void imprimirMes(){
            cout << "Enero: " << fechas[0] << endl;
            cout << "Febrero: " << fechas[1] << endl;
            cout << "Marzo: " << fechas[2] << endl;
            cout << "Abril: " << fechas[3] << endl;
            cout << "Mayo: " << fechas[4] << endl;
            cout << "Junio: " << fechas[5] << endl;
            cout << "Julio: " << fechas[6] << endl;
            cout << "Agosto: " << fechas[7] << endl;
            cout << "Septiembre: " << fechas[8] << endl;
            cout << "Octumbre: " << fechas[9] << endl;
            cout << "Noviembre: " << fechas[10] << endl;
            cout << "Diciembre: " << fechas[11] << endl;
        }
};
