#include <iostream>
#include "Bitacora.hpp"

using namespace std;

int main() {

    Bitacora prueba("Jan", "09", "16:09:15", "skjf", "akljf", "kajf");
    Bitacora * kk;
    kk = new Bitacora("Jan", "09", "16:09:15", "skjf", "akljf", "kajf");

    cout << prueba.getClave() << endl;
    cout << kk->getClave() << endl;



    return 0;
}
