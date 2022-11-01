#include "Cuadrado.h"

#include <iostream>

using namespace std;

int main()
{
    float l;
    Cuadrado cuad1;
    cout << "Ingrese un lado del cuadrado" << endl;
    cin >> l;

    Cuadrado cuad3;
    Cuadrado cuad2(cuad1);
    cuad1 = l; //da valor al lado del cuadrado
    cuad2 = cuad1++; //incrementa el aldo del cuadrado en una unidad

    cout <<"El perimetro del cuadrado es:"<<cuad1.perimetro()<<endl;
    //el perimetro del cuadrado es 1+1+1+1

    cout<<"El area del cuadrado es:"<< cuad1.area() <<endl;
    //el area es 1*1

    cout << cuad3.mostrar() << endl; //debe mostar el lado del cuadrado
    cin >> cuad1;
    cout << cuad1.mostrar(); //debe mostrar el lado del cuadrado

    return 0;
}
