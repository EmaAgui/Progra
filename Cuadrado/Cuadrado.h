#ifndef CUADRADO_H
#define CUADRADO_H

#include <iostream>

using namespace std;

class Cuadrado
{
private:
    float lado;

public:
    Cuadrado();
    Cuadrado(float lado);
    Cuadrado(const Cuadrado& cuadrado);
    ~Cuadrado();

    float perimetro() const;
    float area() const;
    Cuadrado& mostrar();

    Cuadrado operator ++(int);
    Cuadrado &operator =(const Cuadrado& cuadrado);

    friend ostream& operator <<(ostream &os, const Cuadrado &cuadrado);
    friend istream& operator >>(istream &is, Cuadrado &cuadrado);
};

#endif // CUADRADO_H
