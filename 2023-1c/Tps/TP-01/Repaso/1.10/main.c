#include <stdio.h>
#include <stdlib.h>

double sumaMatrizSinSupCuadrada(double mat[][4], int n);
double sumaMatrizSinSecCuadrada(double mat[][4], int n);


int main()
{
    double mat[][4] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3},
        {4, 5, 6, 7},
    };

    printf("%.f\n", sumaMatrizSinSupCuadrada(mat, 4));
    printf("%.f", sumaMatrizSinSecCuadrada(mat, 4));
    return 0;
}


double sumaMatrizSinSecCuadrada(double mat[][4], int n)
{
    double res = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n && j < i; j++)
        {
            printf("%f ", mat[i][j]);
            res += mat[i][j];
        }
    }

    return res;
}


double sumaMatrizSinSupCuadrada(double mat[][4], int n)
{
    double res = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n && j > i; j++)
        {
            printf("%f ", mat[i][j]);
            res += mat[i][j];
        }
    }

    return res;
}
