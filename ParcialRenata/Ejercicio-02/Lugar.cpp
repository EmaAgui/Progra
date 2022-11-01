#include "Lugar.h"

Lugar::Lugar()
{
    this->descripcion = new char[1];
    this->descripcion[0] = '\0';

    this->latitud = 0;
    this->longitud = 0;
    this->calificacion = 0;
}


Lugar::Lugar(const Lugar& lug)
{
    this->descripcion = new char[strlen(lug.descripcion) + 1];
    strcpy(this->descripcion, lug.descripcion);

    this->latitud = lug.latitud;
    this->longitud = lug.longitud;
    this->calificacion = lug.calificacion;
}


Lugar& Lugar::operator = (const Lugar& lug)
{
    this->descripcion = new char[strlen(lug.descripcion) + 1];
    strcpy(this->descripcion, lug.descripcion);

    this->latitud = lug.latitud;
    this->longitud = lug.longitud;
    this->calificacion = lug.calificacion;

    return *this;
}


Lugar::Lugar(const char *descripcion, float latitud, float longitud)
{
    this->descripcion = new char[strlen(descripcion) + 1];
    strcpy(this->descripcion, descripcion);

    this->latitud = latitud;
    this->longitud = longitud;
    this->calificacion = 0;
}


Lugar::~Lugar()
{
    delete [] this->descripcion;
}


void Lugar::calificar(int calificacion)
{
    if(calificacion >= 0 && calificacion <= 5)
        this->calificacion = calificacion;

}


ostream& operator <<(ostream &os, const Lugar &lug)
{
    char cal[lug.calificacion + 1];
    for(int i = 0; i < lug.calificacion; i++)
        cal[i] = '*';

    cal[lug.calificacion] = '\0';

    os << lug.descripcion << ' ' << lug.latitud << ' ' << lug.longitud << ' ' << cal << endl;

    return os;
}


const char* Lugar::descripcionn()
{
    return this->descripcion;
}


float Lugar::operator -(const Lugar& lug)
{
    float l1 = this->longitud - lug.longitud;
    float l2 = this->latitud - lug.latitud;

    return sqrt(l1 * l1 + l2 * l2 ) * 111.12;

}


Lugar& Lugar::agregraEstrella()
{
    if(this->calificacion < 5)
        this->calificacion++;

    return *this;
}

