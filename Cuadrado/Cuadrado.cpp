#include "Cuadrado.h"

Cuadrado::Cuadrado()
{
    this->lado = 1;
}

Cuadrado::Cuadrado(float lado)
{
    this->lado = lado;
}

Cuadrado::Cuadrado(const Cuadrado &cuadrado)
{
    this->lado = cuadrado.lado;
}

Cuadrado::~Cuadrado()
{
    //dtor
}


float Cuadrado::perimetro() const
{
    return this->lado * 4;
}


float Cuadrado::area() const
{
    return this->lado * this->lado;
}


Cuadrado Cuadrado::operator ++(int)
{
    Cuadrado cuadra(*this);
    this->lado++;
    return cuadra;
}


Cuadrado& Cuadrado::operator =(const Cuadrado& cuadrado)
{
    this->lado = cuadrado.lado;
    return *this;
}

ostream& operator <<(ostream &os, const Cuadrado &cuadrado)
{
    os << cuadrado.lado;
    return os;
}

istream& operator >>(istream &is, Cuadrado &cuadrado)
{
    is >> cuadrado.lado;
    return is;
}


Cuadrado& Cuadrado::mostrar()
{
    return *this;
}

