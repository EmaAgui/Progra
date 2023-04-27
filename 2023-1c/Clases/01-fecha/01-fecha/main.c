#include <stdio.h>
#include <stdlib.h>

#define TAM 5
#define ES_BISIESTO(A) ((A) % 400 == 0 || ((A) % 100 != 0 && (A) % 4 == 0))


typedef struct
{
    int dia, mes, anio;
}Fecha;

int esfechaValida(const Fecha *f);
int cantDiasMes(int mes, int anio);


/**
    HACER DIFERENCIA EN DIAS FECHAS
    SACAR EL DIA DE LA FECHA(L, M, M, J, V, S, D)
**/
int diferenciaEntreDiasFechas(const Fecha *f1, const Fecha *f2);
char *diaSemana(const Fecha *fecha);
int cantDiasAnio(int anio);
int diaDelAnio(const Fecha* f);


int main()
{
    Fecha f = {15, 6, 2023};
    Fecha f2 = {24, 8, 2023};

    if(esfechaValida(&f))
        printf("\nFecha Valida");
    else
        printf("\nFecha Invalida");

    printf("\n%d", diferenciaEntreDiasFechas(&f, &f2));

    printf("\n%s", diaSemana(&f));
    return 0;
}


char *diaSemana(const Fecha *fecha)
{
    static const char dias[][10] =
    {
        {"DOMINGO"}, {"LUNES"}, {"MARTES"}, {"MIERCOLES"}, {"JUEVES"}, {"VIERNES"}, {"SABADO"}
    };
    int dia, anio = 1601;

    for(int i = anio; i < fecha->anio; i++)
    {
        dia += cantDiasAnio(anio);
        anio++;
    }

    dia += diaDelAnio(fecha);

    return dias[(dia % 7)];
}


int cantDiasAnio(int anio)
{
    return ES_BISIESTO(anio)? 366:365;
}


int diaDelAnio(const Fecha* f)
{
    static const int acumuladoMesesNoBisiesto[] ={0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    static const int acumuladoMesesBisiesto[] ={0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

    return ES_BISIESTO(f->anio)? acumuladoMesesBisiesto [f->mes] : acumuladoMesesNoBisiesto[f->mes] + f->dia;
}


int diferenciaEntreDiasFechas(const Fecha *f1, const Fecha *f2)
{
    int dif = diaDelAnio(f2) - diaDelAnio(f1);

    for(int i = f1->anio; i < f2->anio;i++)
        dif+=cantDiasAnio(i);

    return dif;
}



int cantDiasMes(int mes, int anio)
{
    ///static queda siempre en la memoria, no es global
    static int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return mes == 2 && ES_BISIESTO(anio)? 29 : diasMes[mes];
}

////////////////

int esfechaValida(const Fecha *f)
{
    if(f->anio >= 1601)
        if(f->mes >= 1 && f->mes <= 12)
            if(f->dia >= 1 && f->dia <= cantDiasMes(f->mes, f->anio))
                return 1;

    return 0;
}
