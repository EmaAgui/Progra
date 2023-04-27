#include <stdio.h>
#include <stdlib.h>

#include "../Ejercicios/Funciones.h"
int main()
{
    int selec;
    int vec[] = {1, 4, 5, 9, 4};
    int ce = sizeof(vec) / sizeof(*vec);
    do{
        printf("\nIngrese el Ejercicio 1 - 13: \n");
        scanf("%d", &selec);
        while(selec != 0)
        {
            switch(selec)
            {
                case 1:
                    printf("Ejercicio 1: Factorial: %.f\n", factorial(17));
                    break;
                case 2:
                    printf("Ejercicio 2: Combinatoria: %d", combinatoria(6, 2));
                    break;
                case 3:
                    printf("Ejercicio 3: Exponente: %f", exponente(10));
                    break;                case 4:
                    break;
                case 5:
                    if(esFibonacci(8))
                        printf("Es Fibonacci\n");
                    else
                        printf("No es Fibonacci\n");
                    break;                case 6:
                    printf("Ejercicio 6: Sen(x): %f", senx(2));
                    break;
                case 7:
                    break;
                case 8:
                    printf("Ejercicio 7: Suma sucesiva: %d", sumaSucesiva(5,6));
                    break;
                case 9:
                    cociente(5,5);
                    break;
                case 10:
                    printf("Ejercicio 7: Suma de los primeros numeros naturales : %d",sumaPrimerosNumNat(10));
                    break;
                case 11:
                    printf("Ejercicio 7: Suma de los primeros numeros naturales Pares: %d",sumaPrimerosNumNatPares(10));
                    break;
                case 12:
                    break;
                case 13:
                    break;
                case 24:
                    mostrarVector(vec, ce);
                    eliminaUnaPosicion(vec, &ce, 3);
                    printf("\n");
                    mostrarVector(vec, ce);
                    break;
            }
            printf("\nIngrese el Ejercicio 1 - 13: \n");
            scanf("%d", &selec);
        }

    }while(selec > 24 || selec < 0);

    if(esPalindromo("anna"))
        printf("Es Palindromo");
    else
        printf("No es Palindromo");


    return 0;
}
