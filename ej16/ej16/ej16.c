#include "ej16.h"

int EsBisiesto(t_fecha fecha)
{
    int a=0;
    if((fecha.anio%4==0)&&(!(fecha.anio%100==0)||(fecha.anio%400==0)))
        a=1;
    return a;
}
t_fecha Cargar()
{
    t_fecha fecha;
    do{
        printf("INGRESE EL A%cO(aaaa): ",164);
        scanf("%d",&fecha.anio);
    }while(fecha.anio>2999||fecha.anio<=0);
    printf("\n");
    if(EsBisiesto(fecha))
    {
        do{
            printf("INGRESE EL MES(mm): ");
            scanf("%d",&fecha.mes);
        }while(fecha.mes<=0||fecha.mes>12);
        switch(fecha.mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            do{
                printf("\n");
                printf("INGRESE EL DIA(dd): ");
                scanf("%d",&fecha.dia);
            }while(fecha.dia<=0||fecha.dia>31);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            do{
                printf("\n");
                printf("INGRESE EL DIA(dd): ");
                scanf("%d",&fecha.dia);
            }while(fecha.dia<=0|| fecha.dia>30);
            break;
        case 2:
            do{
                printf("\n");
                printf("INGRESE EL DIA(dd): ");
                scanf("%d",&fecha.dia);
            }while(fecha.dia<=0||fecha.dia>29);
            break;
        }
    }
    else
    {
        do{
            printf("INGRESE EL MES(mm): ");
            scanf("%d",&fecha.mes);
        }while(fecha.mes<=0||fecha.mes>12);
        switch(fecha.mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            do{
                printf("\n");
                printf("INGRESE EL DIA(dd): ");
                scanf("%d",&fecha.dia);
            }while(fecha.dia<=0||fecha.dia>31);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            do{
                printf("\n");
                printf("INGRESE EL DIA(dd): ");
                scanf("%d",&fecha.dia);
            }while(fecha.dia<=0|| fecha.dia>30);
            break;
        case 2:
            do{
                printf("\n");
                printf("INGRESE EL DIA(dd): ");
                scanf("%d",&fecha.dia);
            }while(fecha.dia<=0||fecha.dia>28);
            break;
        }
    }
    return fecha;
}
void mostrarFecha(t_fecha fecha)
{
    printf("%d/%d/%d ",fecha.dia,fecha.mes,fecha.anio);
}
t_fecha Ndias(t_fecha fecha, int n)
{
    t_fecha fecha1=fecha;
    for(int i=0;i<n;i++)
    {
        switch(fecha1.mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if(fecha1.dia<31)
                fecha1.dia++;
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
            if(fecha1.dia<30)
                 fecha1.dia++;
            else
            {
                fecha1.mes++;
                fecha1.dia=1;
            }
            break;
        case 12:
            if(fecha1.dia<31)
                fecha1.dia++;
            else
            {
                fecha1.anio++;
                fecha1.mes=fecha1.dia=1;
            }
            break;

        case 2:
        {
            if(EsBisiesto(fecha1))
            {
                if(fecha1.dia<29)
                    fecha1.dia++;
                else
                {
                    fecha1.mes++;
                    fecha1.dia=1;
                }
            }
            else
            {
                if(fecha1.dia<28)
                    fecha1.dia++;
                else
                {
                    fecha1.mes++;
                    fecha1.dia=1;
                }
            }
        }
        break;
        }
    }
    return fecha1;
}
