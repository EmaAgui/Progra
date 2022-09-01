#include <stdio.h>
#include <stdlib.h>


int sumaArribaSinDiagoPrincipal(int mat[][4], int filas, int columnas);
int sumaArribaConDiagoPrincipal(int mat[][4], int filas, int columnas);
void mostrarMatriz(int mat[][4], int filas, int columnas);


int main()
{
    int mat[][4] =
    {
        {1, 5, 6, 0},
        {1, 5, 6, 0},
        {1, 5, 6, 0},
        {1, 5, 6, 1}
    };

    printf("\n Suma Arriba Digonal Principal Excluida: %d", sumaArribaSinDiagoPrincipal(mat, 4, 4));
    printf("\n Suma Arriba Digonal Principal Incluida: %d", sumaArribaConDiagoPrincipal(mat, 4, 4));
    mostrarMatriz(mat, 4, 4);

    return 0;
}


void mostrarMatriz(int mat[][4], int filas, int columnas)
{
    int i, j;

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
            printf("%d ", mat[i][j]);

        printf("\n");
    }
}


int sumaArribaConDiagoPrincipal(int mat[][4], int filas, int columnas)
{
    int i, j, sum = 0;

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            if(j >= i)
                sum += mat[i][j];
        }
    }

    return sum;
}


int sumaArribaSinDiagoPrincipal(int mat[][4], int filas, int columnas)
{
    int i, j, sum = 0;

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            if(j > i)
                sum += mat[i][j];
        }
    }

    return sum;
}
