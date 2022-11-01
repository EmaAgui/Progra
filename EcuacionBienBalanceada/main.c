#include "Pila.h"

int buscarEnMat(char *caracter, char matExp[][3]);

int main()
{
    Pila pilaEcuacion;
    char ecuacion[] = "{[(5+4) + (5+7)]}";
    int cantEcu = (int)strlen(ecuacion);
    int i = 0;
    char tope;
    void *indice;
    const char matExp[][3] =
    {
        {'{', '[', '(' },
        {'}', ']', ')'}
    };

    crearPila(&pilaEcuacion);

    while (i < cantEcu)
    {
        if((indice = strchr(matExp[0], *(ecuacion + i))))
        {
            printf("%c\n", *((char*)(indice + (sizeof(char)))));
            apilar(&pilaEcuacion, ecuacion + i, sizeof(char));
            verTope(&pilaEcuacion, &tope, sizeof(char));
//            printf("%c\n", tope);
        }
        if(i > 0 && strchr(matExp[1], *(ecuacion + i)))
        {
            desapilar(&pilaEcuacion, &tope, sizeof(char));
            if(!strchr(matExp[1], tope))
                {
                    printf("\nNo Esta Balanceada");
                    return 0;
                }
        }

        i++;
    }
    printf("Esta Balancada");

//    while (!pilaVacia(&pilaEcuacion))
//    {
//        desapilar(&pilaEcuacion, &tope, sizeof(char));
//        printf("%c\n", tope);
//    }


    return 0;
}


int buscarEnMat(char *caracter, char matExp[][3])
{
    int i = 0;
    int j = 0;
    while (i < 2)
    {
        while (j < 3)
        {
            if(matExp[i][j] == *caracter)
                return j;
        }

        i++;
    }

    return -1;
}
