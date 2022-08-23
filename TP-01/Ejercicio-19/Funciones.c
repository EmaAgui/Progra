#include "Funciones.h"


int esBisiesto(int anio);
int cantDiasMes(int mes, int anio);


void diaDeLaSemana(const Fecha *f1)
{
    int dia;

    dia = cantDiasDesde1601(f1) % 7;

    switch(dia)
    {
        case 1:
        printf("\nLunes\n");
        break;

        case 2:
        printf("\nMartes\n");
        break;

        case 3:
        printf("\nMiercoles\n");
        break;
        case 4:
        printf("\nJueves\n");
        break;

        case 5:
        printf("\nViernes\n");
        break;

        case 6:
        printf("\nSabado\n");
        break;
        case 7:
        printf("\nDomingo\n");
        break;
    }
}



int cantDiasDesde1601(const Fecha *f)
{
    Fecha fecha = *f;
    int cant;
    int cantAnios = fecha.anio - 1601;
	int diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;

	cant = diasAniosCompl + diaDelAnio(&fecha);

	return cant;
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
