#include "Funciones.h"


int esBisiesto(int anio);
int cantDiasMes(int mes, int anio);


int diferenciaDeDiasEntreFechas(const Fecha* f1, const Fecha* f2)
{
    int dif = (diaDelAnio(f1) - diaDelAnio(f2));
    int anioAct = f1->anio;

    while(anioAct < f2->anio)
    {
        dif += cantDiasAnio(anioAct);
        anioAct++;
    }

    return dif;
}


int cantDiasAnio(int anio)
{
    return esBisiesto(anio)? 366 : 365;
}


int diaDelAnio(const Fecha* f)
{
    int diaA = f->dia;
    int mesAct = 1;

    while(mesAct < f->mes)
    {
        diaA += cantDiasMes(mesAct, f->anio);
        mesAct++;
    }

    return diaA;
}


Fecha ingresarFecha()
{
    Fecha fecha;
    printf("\nIngrese Fecha(dd/mm/aaaa): ");
    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

    while(!esFechaValida(&fecha))
    {
        printf("\nLa fecha es invalida, ingrese nuevamente(dd/mm/aaaa): ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    }
    return fecha;
}


int esFechaValida(Fecha *f)
{
    return  f->anio > 1600 &&
            f->mes >= 1 && f->mes <= 12 &&
            f->dia >= 1 && f->dia <= cantDiasMes(f->mes, f->anio);
}


int cantDiasMes(int mes, int anio)
{
    int cdm[] ={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(mes == 2 && esBisiesto(anio))
        return 29;

    return cdm[mes];
}


int esBisiesto(int anio)
{
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}
