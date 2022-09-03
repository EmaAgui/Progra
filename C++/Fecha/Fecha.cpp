#include "Fecha.h"


const int Fecha::cdm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int Fecha::acumDiasMes[14] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

const int Fecha::acumDiasMesBisiesto[14] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};


Fecha::Fecha()
{
    this->diaRel = 1;
}


Fecha::Fecha(int dia, int mes, int anio)
{
    this->diaRel = dmaADiaRel(dia, mes, anio);///TODO
}


Fecha Fecha::sumarDias(int dias) const
{
    Fecha fechaSuma;
    fechaSuma.diaRel = this->diaRel + dias;

    return fechaSuma;
}


Fecha Fecha::restarDias(int dias) const
{
    Fecha fechaResta;
    fechaResta.diaRel = diaRel - dias;

    return fechaResta;
}


int Fecha::diferenciaDias( Fecha fecha) const
{
    return diaRel - fecha.diaRel;
}


// Dia de la semana, el primer dia es lunes, fecha base 1/1/1601
int Fecha::diaDeLaSemana() const
{
    return (diaRel - 1) % 7;
}


int Fecha::dmaADiaRel(int dia, int mes, int anio)
{
    if(!esFechaValida(dia, mes, anio))
       throw FECHA_INVALIDA;

    int cantAnios = anio - ANIO_BASE;
    int diasAnioCompleto = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
    int diaRel = diasAnioCompleto + diaDelAnio(dia, mes, anio);


    return diaRel;
}


void Fecha::diaRelADma(int diaRel, int *dia, int *mes, int *anio)
{
    int cantAniosComplCal = diaRel / 365;
    int diasAniosComplCal = cantAniosComplCal * 365 + cantAniosComplCal / 4 - cantAniosComplCal / 100 + cantAniosComplCal / 400;

    while(diasAniosComplCal >= diaRel) ///
    {
        cantAniosComplCal--;
        diasAniosComplCal = cantAniosComplCal * 365 + cantAniosComplCal / 4 - cantAniosComplCal / 100 + cantAniosComplCal / 400;
    }


    *anio = cantAniosComplCal + ANIO_BASE;

    int diaDelAnio = diaRel - diasAniosComplCal;

    diaDelAnioADiaMes(diaDelAnio, *anio, dia, mes);
}


void Fecha::diaDelAnioADiaMes(int diaDelAnio, int anio, int *dia, int *mes)
{
    const int *acumDiasMes = esBisiesto(anio)? acumDiasMesBisiesto : Fecha::acumDiasMes; ///Uso un vector o el otro

    int m = 1;
    while(diaDelAnio > acumDiasMes[m]) ///Varible local
        m++;

    m--;
    *mes = m;

    *dia = diaDelAnio - acumDiasMes[m];

}


void Fecha::getDma(int *dia, int *mes, int *anio) const
{
    diaRelADma(diaRel, dia, mes, anio);
}
