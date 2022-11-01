#ifndef LUGAR_H
#define LUGAR_H

#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;


class Lugar
{
private:
    char *descripcion;
    float latitud;
    float longitud;
    int calificacion;

public:
    Lugar();
    Lugar(const char *descripcion,float latitud, float longitud);

    Lugar(const Lugar& lug);
    ~Lugar();
    Lugar& operator = (const Lugar& lug);


    void calificar(int calificacion);
    const char* descripcionn();
    Lugar& agregraEstrella();

    float operator -(const Lugar& lug);


    friend ostream& operator <<(ostream &os, const Lugar &lug);
};

#endif // LUGAR_H
