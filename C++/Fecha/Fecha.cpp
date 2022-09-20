#include "Fecha.h"
#include "FechaInvalidaException.h"


const int Fecha::cdm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int Fecha::acumDiasMes[14] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

const int Fecha::acumDiasMesBisiesto[14] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};


Fecha::Fecha()
{
    this->diaRel = 1;
}


Fecha::Fecha(int dia, int mes, int anio)
{
    setDma(dia, mes, anio);///TODO
}


Fecha Fecha::operator +(int dias) const
{
    Fecha fechaSuma(*this); ///Copia del objeto llamador, se le pasa la dir de memoria del objeto llamador
    fechaSuma.diaRel += dias;

    return fechaSuma;
}


Fecha Fecha::operator-(int dias) const
{
    Fecha fechaResta(*this);
    fechaResta.diaRel -= dias;

    if(fechaResta.diaRel < 1)
        throw FechaInvalidaException("Fecha invalida: quiere restar mas dias de los permitidos."); ///objeto temporal

    return fechaResta;
}


int Fecha::operator -(const Fecha &fecha) const
{
    return this->diaRel - fecha.diaRel;
}


Fecha& Fecha::operator ++()///Preincremento
{
    ++this->diaRel;
    return *this;
}


Fecha Fecha::operator ++(int) //Postincremento
{
    Fecha fechaAnterior(*this);
    ++this->diaRel;

    return fechaAnterior;
}


int Fecha::diaDeLaSemana() const
{
    return (diaRel - 1) % 7;
}


void Fecha::setDma(int dia, int mes, int anio)
{
    if(!esFechaValida(dia, mes, anio))
       throw FECHA_INVALIDA;

    int cantAnios = anio - ANIO_BASE;
    int diasAnioCompleto = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
    this->diaRel = diasAnioCompleto + diaDelAnio(dia, mes, anio);
}


void Fecha::getDma(int &dia, int &mes, int &anio)const
{
    int cantAniosComplCal = this->diaRel / 365;
    int diasAniosComplCal = cantAniosComplCal * 365 + cantAniosComplCal / 4 - cantAniosComplCal / 100 + cantAniosComplCal / 400;

    while(diasAniosComplCal >= this->diaRel) ///
    {
        cantAniosComplCal--;
        diasAniosComplCal = cantAniosComplCal * 365 + cantAniosComplCal / 4 - cantAniosComplCal / 100 + cantAniosComplCal / 400;
    }

    anio = cantAniosComplCal + ANIO_BASE;

    int diaDelAnio = this->diaRel - diasAniosComplCal;

    diaDelAnioADiaMes(diaDelAnio, anio, dia, mes);
}


void Fecha::diaDelAnioADiaMes(int diaDelAnio, int anio, int &dia, int &mes)
{
    const int *acumDiasMes = esBisiesto(anio)? acumDiasMesBisiesto : Fecha::acumDiasMes; ///Uso un vector o el otro

    int m = 1;
    while(diaDelAnio > acumDiasMes[m]) ///Varible local
        m++;

    m--;
    mes = m;

    dia = diaDelAnio - acumDiasMes[m];

}


ostream& operator <<(ostream &os, const Fecha &fecha)
{
    int dia, mes, anio;
    fecha.getDma(dia, mes, anio);
    os << dia << '/' << mes << '/' << anio;
    return os;
}


