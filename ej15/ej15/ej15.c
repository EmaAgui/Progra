#include "ej15.h"

int EsBisiesto(t_fecha fecha)
{
    int a=0;
    if((fecha.anio%4==0) && (!(fecha.anio%100==0)|| (fecha.anio%400==0)))
    {
        a=1;
    }
    return a;
}
t_fecha CargaFecha()
{
    t_fecha fecha;


    do
    {
        printf("\nIngrese el A%cO(aaaa):",164);
        scanf("%d",&fecha.anio);
    }while(fecha.anio>2999 || fecha.anio<=1600);

    if(EsBisiesto(fecha))
    {
        do
        {
            printf("\nIngrese el MES(mm):");
            scanf("%d", &fecha.mes);
        }while(fecha.mes<=0 || fecha.mes >12);

        switch(fecha.mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            do
            {
                printf("\nIngrese el DIA(dd):");
                scanf("%d", &fecha.dia);
            }while(fecha.dia<=0 || fecha.dia>31);
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            do
            {
                printf("\nIngrese el DIA(dd):");
                scanf("%d", &fecha.dia);
            }while(fecha.dia<=0 || fecha.dia>=30);
            break;

        case 2:
            do
            {
                printf("\nIngrese el DIA(dd):");
                scanf("%d", &fecha.dia);
            }while(fecha.dia<=0 || fecha.dia>29);
            break;

        }
    }
    else
    {
      do
        {
            printf("\nIngrese el MES(mm):");
            scanf("%d", &fecha.mes);
        }while(fecha.mes<=0 || fecha.mes>12);

        switch(fecha.mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            do
            {
                printf("\nIngrese el DIA(dd):");
                scanf("%d", &fecha.dia);
            }while(fecha.dia<=0 || fecha.dia>31);
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            do
            {
                printf("\nIngrese el DIA(dd):");
                scanf("%d", &fecha.dia);
            }while(fecha.dia<=0 || fecha.dia>=30);
            break;

        case 2:
            do
            {
                printf("\nIngrese el DIA(dd):");
                scanf("%d", &fecha.dia);
            }while(fecha.dia<=0 || fecha.dia>28);
            break;

        }
    }

    return fecha;
}


t_fecha ProxDia(t_fecha fecha)
{
    t_fecha fecha1=fecha;

        switch(fecha.mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if(fecha.dia<31)
            {
                fecha1.dia++;
            }
            else
            {
                fecha1.mes++;
                fecha1.dia=1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(fecha.dia<30)
            {
                fecha1.dia++;
            }
            else
            {
                fecha1.mes++;
                fecha1.dia=1;
            }
            break;

        case 12:
            if(fecha.dia<31)
            {
              fecha1.dia++;
            }
            else
            {
                fecha1.anio++;
                fecha1.mes=fecha1.dia=1;
            }
        }

        if(fecha.mes==2)
        {
            if(EsBisiesto(fecha))
            {
                if(fecha.dia<29)
                {
                    fecha1.dia++;
                }
                else
                {
                    fecha1.mes++;
                    fecha1.dia=1;
                }
            }
            else
            {
                if(fecha.dia<28)
                {
                    fecha1.dia++;
                }
                else
                {
                    fecha1.mes++;
                    fecha1.dia=1;
                }

            }

        }

    return fecha1;
}


void mostrarFecha(t_fecha fecha)
{
    printf("%d/%d/%d", fecha.dia, fecha.mes, fecha.anio);
}
