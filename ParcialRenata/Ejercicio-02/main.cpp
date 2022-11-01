#include <iostream>
#include "Lugar.h"

using namespace std;

int main()
{
    Lugar l1("Estacion Ramos Mejia", -34.640544, -58.56196);
    Lugar l2("Unlam", -34.671031, -58.563009);
    Lugar l3("Estacion El Palomar", -34.60511, -58.595339);


    cout << "la distancia entre " << l1.descripcionn() << " y "  << l2.descripcionn() << " es " << l1 - l2 << "kms" << endl;
    cout << "la distancia entre " << l1.descripcionn() << " y " << l3.descripcionn() << " es " << l1 - l3 << "kms" << endl;

    l1.agregraEstrella().agregraEstrella().agregraEstrella();
    l3.calificar(3);
    l2.calificar(5);
    l2.calificar(10);

    cout << l1 << endl;
    cout << l2 << endl;
    cout << l3 << endl;
    return 0;
}
