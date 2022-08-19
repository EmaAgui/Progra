#include <stdio.h>
#include <stdlib.h>


void mostrarCocienteYResto(int num1, int num2);


int main()
{
    int num1 = 1, num2 = 2;

    mostrarCocienteYResto(num1, num2);

    return 0;
}


void mostrarCocienteYResto(int num1, int num2)
{
    int cociente, resto;

    if(num2 == 0)
    {
        printf("No se puede dividir por cero.");
        return;
    }
    cociente = num1 / num2;
    resto = num1 % num2;

    printf("El cociente es: %d\n", cociente);
    printf("El resto es: %d\n", resto);
}



