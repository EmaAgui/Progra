#include <string.h>
#include "Cadena.h"

Cadena::Cadena()
{
    this->cadenaC = new char[1]; ///creo memoria dinaamica con new(operador), como es cadena vacia creo un espacio de memoria
    cadenaC[0] = '\0';
}


Cadena::Cadena(const char *cadenaC)///Recibe una cadena de c
{
    this->cadenaC = new char[strlen(cadenaC) + 1]; ///creo el tamaño justo, strlen no cuenta el caracter nulo
    strcpy(this->cadenaC, cadenaC);///copia la cadena de c a la cadena de c++(this->cadenaC)
}


Cadena::Cadena(const Cadena &otra)
{
    this->cadenaC = new char[strlen(otra.cadenaC) + 1]; ///creo el tamaño justo, strlen no cuenta el caracter nulo
    strcpy(this->cadenaC, otra.cadenaC);///copia la cadena de c a la cadena de c++(this->cadenaC)
}


Cadena::~Cadena()
{
    cout << "Ejecutando destructor... " << endl;
    delete [] this->cadenaC; ///libero la memoria dinamica
}


Cadena& Cadena::operator =(const Cadena &otra)
{
    if(this == &otra)///si no es la misma cadena, ej c1 = c1.
        return *this;

    if(strlen(this->cadenaC) != strlen(otra.cadenaC))///si no es la misma longitud
    {
        delete[] this->cadenaC;///libero la memoria dinamica
        this->cadenaC = new char[strlen(otra.cadenaC) + 1];///creo el tamaño justo
    }

    strcpy(this->cadenaC, otra.cadenaC);///copia la cadena de c a la cadena de c++(this->cadenaC)

    return *this; ///devuelvo el objeto llamador
}


Cadena Cadena::operator +(const Cadena &otra)const
{
    Cadena concat;
    delete[] concat.cadenaC; ///borro la cadena vacia que se creo en el constructor
    concat.cadenaC = new char[strlen(this->cadenaC) + strlen(otra.cadenaC) + 1]; ///creo el tamaño justo, strlen no cuenta el caracter nulo
    strcpy(concat.cadenaC, this->cadenaC); ///copio la cadena de c++ a la cadena de c++(concat.cadenaC)
    strcat(concat.cadenaC, otra.cadenaC); ///concateno la cadena de c++ con la cadena de c++(otra.cadenaC)

    return concat;
}


const char* Cadena::getCadena()const
{
    return this->cadenaC;
}


ostream& operator <<(ostream &os, const Cadena &cadena)
{
    os << cadena.cadenaC;
    return os;
}
