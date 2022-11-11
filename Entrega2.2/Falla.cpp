#include "Falla.hpp"
#include <string>

using namespace std;

Falla::Falla(){}

Falla::Falla(string mesFallaInicial, string mensaje) {
    this->mensaje = mensaje;
    this->cantidad = 0;
    this->agregarOcurrencia(mesFallaInicial);
}

string Falla::getMensaje() { return this->mensaje; }

void Falla::agregarOcurrencia(string mesDeLaFalla){
/*Función para agregar una ocurrencia a un tipo de falla
Se aumenta en uno la cantidad de ocurrencias totales
Se aumenta en uno la cantidad de ocurrencias del mes en el array ocurrenciasPorMes*/

    this->cantidad += 1;

    if (mesDeLaFalla == "Jan")
    {
        this->ocurrenciasPorMes[0] += 1;
    }
    else if (mesDeLaFalla == "Feb")
    {
        this->ocurrenciasPorMes[1] += 1;
    }
    else if (mesDeLaFalla == "Mar")
    {
        this->ocurrenciasPorMes[2] += 1;
    }
    else if (mesDeLaFalla == "Apr")
    {
        this->ocurrenciasPorMes[3] += 1;
    }
    else if (mesDeLaFalla == "May")
    {
        this->ocurrenciasPorMes[4] += 1;
    }
    else if (mesDeLaFalla == "Jun")
    {
        this->ocurrenciasPorMes[5] += 1;
    }
    else if (mesDeLaFalla == "Jul")
    {
        this->ocurrenciasPorMes[6] += 1;
    }
    else if (mesDeLaFalla == "Aug")
    {
        this->ocurrenciasPorMes[7] += 1;
    }
    else if (mesDeLaFalla == "Sep")
    {
        this->ocurrenciasPorMes[8] += 1;
    }
    else if (mesDeLaFalla == "Oct")
    {
        this->ocurrenciasPorMes[9] += 1;
    }
    else if (mesDeLaFalla == "Nov")
    {
        this->ocurrenciasPorMes[10] += 1;
    }
    else if (mesDeLaFalla == "Dec")
    {
        this->ocurrenciasPorMes[11] += 1;
    }
}

string Falla::display(){
/*Función para generar y devolver un string con toda la info
del tipo de falla (ocurrencias totales y ocurrencias por mes)*/

    string mensaje = "";

    mensaje += "Error: " + getMensaje() + "\n";
    mensaje += "Ocurrencias totales: " + to_string(this->cantidad) + "\n";
    mensaje += "Enero: " + to_string(this->ocurrenciasPorMes[0]) + "\n";
    mensaje += "Febrero: " + to_string(this->ocurrenciasPorMes[1]) + "\n";
    mensaje += "Marzo: " + to_string(this->ocurrenciasPorMes[2]) + "\n";
    mensaje += "Abril: " + to_string(this->ocurrenciasPorMes[3]) + "\n";
    mensaje += "Mayo: " + to_string(this->ocurrenciasPorMes[4]) + "\n";
    mensaje += "Junio: " + to_string(this->ocurrenciasPorMes[5]) + "\n";
    mensaje += "Julio: " + to_string(this->ocurrenciasPorMes[6]) + "\n";
    mensaje += "Agosto: " + to_string(this->ocurrenciasPorMes[7]) + "\n";
    mensaje += "Septiembre: " + to_string(this->ocurrenciasPorMes[8]) + "\n";
    mensaje += "Octumbre: " + to_string(this->ocurrenciasPorMes[9]) + "\n";
    mensaje += "Noviembre: " + to_string(this->ocurrenciasPorMes[10]) + "\n";
    mensaje += "Diciembre: " + to_string(this->ocurrenciasPorMes[11]) + "\n";

    return mensaje;
}
