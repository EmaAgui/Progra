#ifndef FECHA_H
#define FECHA_H

#include <iostream>

///La fecha base es 1/1/1601

#define ANIO_BASE 1601
#define FECHA_INVALIDA 1

using namespace std;

class Fecha
{
private:
    int diaRel;

    static const int cdm[13]; ///Static solo se inicia una sola vez
    static const int acumDiasMes[14];
    static const int acumDiasMesBisiesto[14];

    static inline bool esBisiesto(int anio) { return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0); }; ///inline es tipo define

///Metodo static no trabaja con los campos de la clase, solo con los parametros, no necesita un objeto para ser invocado.
/// Si trabaja solo con los parametros del metodo es static

    static inline int cantDiasMes(int mes, int anio) { return mes == 2 && esBisiesto(anio)? 29 : cdm[mes]; };

    static inline bool esFechaValida(int dia, int mes, int anio)
        { return anio >= ANIO_BASE && mes >= 1 && mes <= 12 && dia >= 1 && dia <= cantDiasMes(mes, anio); };

    static inline int diaDelAnio(int dia, int mes, int anio)
        {return (esBisiesto(anio)? acumDiasMesBisiesto[mes] : acumDiasMes[mes]) + dia; };

    static void diaDelAnioADiaMes(int diaDelAnio, int anio, int &dia, int &mes);

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    Fecha operator +(int dias) const;///El primer operarndo es el objeto llamador, accedo mediante this
    Fecha &operator ++(); ///Preincremento, ++fecha
    Fecha operator ++(int); ///Postincremento, int es para diferenciarlo del preincremento
    int operator -(const Fecha &fecha) const; ///const para que no modifique a la variable, & para que no se copie el objeto
    Fecha operator-(int dias) const;


    ///TODO
    ///Fecha &operator --(); ///Predecremento, --fecha
    ///Fecha operator --(int); ///Postdecremento, int es para diferenciarlo del predecremento
    ///Fecha &operator +=(int dias);
    ///Fecha &operator -=(int dias);
    ///bool operator ==(const Fecha &fecha) const;
    ///bool operator !=(const Fecha &fecha) const;
    ///bool operator <(const Fecha &fecha) const;
    ///bool operator <=(const Fecha &fecha) const;
    ///bool operator >(const Fecha &fecha) const;
    ///bool operator >=(const Fecha &fecha) const;


    ///const al final la funcion no modifica el objeto que la llame
    int diaDeLaSemana() const;
    void getDma(int &dia, int &mes, int &anio)const;
    void setDma(int dia, int mes, int anio);
};


///geters y seters solo para exponer los campos de la clase al usuario
///funciones amigas de la clase, obtienen acceso a los campos privados de la clase
ostream& operator <<(ostream &os, const Fecha &fecha);
istream& operator >>(istream &is, Fecha &fecha);

#endif // FECHA_H
