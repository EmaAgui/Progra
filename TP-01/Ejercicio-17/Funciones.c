#include "Funciones.h"


int esBisiesto(int anio);
int cantDiasMes(int mes, int anio);



Fecha restarNDias(const Fecha *f, int dias)
{
    int sum, res, cdm;

    Fecha fec = *f;

    cdm = cantDiasMes(fec.mes, fec.anio);

    sum = fec.dia - dias;

    while(sum < cdm)
    {
        res = sum + cdm;
        sum = res;

        if(fec.mes == 1)
            {
                fec.anio--;
                fec.mes = 1;
            }

        cdm = cantDiasMes(fec.mes, fec.anio);
        fec.mes--;
    }
    fec.dia = sum - cdm;

    return fec;
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
