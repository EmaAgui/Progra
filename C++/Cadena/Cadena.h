#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED


#include <iostream>

using namespace std;


class Cadena
{
private:
    char *cadenaC;

public:
    Cadena(); ///ctor default
    Cadena(const char *cadenaC);

    ///Siempre estos tres con mem din...
    Cadena(const Cadena &cadena); ///Constructor de copia
    ~Cadena(); ///destructor, libero memoria con delete = free.
    Cadena &operator =(const Cadena &cadena);///Siempre cuando hay memoria Dinamica, se debe sobrecargar el operador de asignacion porque sino, se copia la direccion de memoria y no el contenido de la memoria

    Cadena operator +(const Cadena &cadena)const;
    Cadena& operator +=(const Cadena &cadena);
    bool operator ==(const Cadena &cadena)const;
    bool operator !=(const Cadena &cadena)const;
    bool operator <(const Cadena &cadena)const;
    bool operator <=(const Cadena &cadena)const;
    bool operator >(const Cadena &cadena)const;
    bool operator >=(const Cadena &cadena)const;

    char& operator [](int indice); ///devuelvo la referencia al caracter
    const char& operator [](int subindice)const; ///Lo mismo que el de arriba pero con const

    const char *getCadena()const; ///Devuelve el contenido de la cadena.
    int getLongitud()const; ///Devuelve longitud de la cadena.

    ///Con friend se puede acceder a los atributos privados de la clase, siempre dentro de la clase
    friend ostream& operator <<(ostream &os, const Cadena &cadena); ///El objeto llamador es un cout
};


#endif // CADENA_H_INCLUDED

