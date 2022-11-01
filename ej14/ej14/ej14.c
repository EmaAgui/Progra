#include "ej14.h"

int EsFechaValida(t_fecha fecha)
{
    if(fecha.anio>=1601)
    {
        if(fecha.mes>=1&&fecha.mes<=12)
        {
            if(fecha.dia>=1 && fecha.dia<=cantDiasMes(fecha.mes,fecha.anio))
            {
                return 1;
            }
        }
    }

    return 0;
}
int cantDiasMes(int mes,int anio)
{
    int cdm[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if(mes==2 && EsBisiesto(anio))
    {
        return 29;
    }
    return cdm[mes];
}

int EsBisiesto(int anio)
{
    int a=0;
    if((anio%4==0) && (!(anio%100==0)|| (anio%400==0)))
    {
        a=1;
    }
    return a;
}

t_fecha DiaSiguiente (t_fecha x)
{
    if(x.dia<cantDiasMes(x.mes,x.anio))
    {
        x.dia+=1;
        return x;
    }
    else
    {
        x.dia=1;
        if(x.mes==12)
        {
            x.mes=1;
            x.anio+=1;
            return x;
        }
        else
        {
            x.mes+=1;
            return x;
        }
    }
}
