#include <stdio.h>
#include <stdlib.h>

#define FIL 4
#define COL 4

/**
    hacer digo pcpal
    hacer digo secun

    triangulo 1
    triangulo 2

    suma arriba diago pcpal
    suma abajo diago pcpal

    determiante
    producto de matrices

    siEsSimetrica
    siEsIdentidad

    matrizTraspuesta
**/


void cargarMatriz(int mat[][4], int filas, int columnas);

void mostrarMatriz(int mat[][FIL], int filas, int columnas);
void mostrarDiagonalPrincipal(int mat[][4], int filas, int columnas);
void mostrarDiagonalSecundaria(int mat[][4], int filas, int columnas);

int sumaDiagonalSinPrincipal(int mat[][4], int filas, int columnas);
int sumaDiagonalConPrincipalAbajo(int mat[][4], int filas, int columnas);

int sumasAribaDeDiagonalSecundariaCon(int m[][4], int filas, int columnas);
int sumaDebajoDeDiagonalSecunadariaCon(int m[][4], int filas, int columnas);


int sumaDeNumerosArribaDeDiagonalPrincipal(int m[][4], int filas, int columnas);


int esCuadrada(int mat[][4], int filas, int columnas);
int esIdentidad(int mat[][4], int filas, int columnas);
int esDiagonal(int mat[][4], int filas, int columnas);

int traza(int mat[][4], int filas, int columnas);
int trazaSecundaria(int mat[][4], int filas, int columnas);


int productoDeMatrices(int mat1[][COL], int mat2[][COL], int mat3[][COL], int filas1, int columnas1, int filas2, int columnas2);

int esSimetrica(int m[][4], int filas, int columnas);
void trasponerMatriz(int m[][4], int filas, int columnas);

int main()
{
    int mat1[][COL] =
    {
        {1, 4, 2, 1},
        {9, 2, 8, 6},
        {6, 1, 4, 4},
        {4, 6, 4, 3},
    };

    int iden[][COL] =
    {
        {4, 0, 0, 0},
        {0, 5, 0, 0},
        {0, 0, 5, 0},
        {0, 0, 0, 4},
    };

    int cant = sizeof(mat1) / sizeof(mat1[0]);

    printf("\n%d\n", cant);

//    int mat2[FIL][COL] = {10, 20};

    mostrarMatriz(mat1, COL, FIL);
//
//    int mat3[FIL][COL] = {{0}};
//    cargarMatriz(mat3, FIL, COL);
//    mostrarMatriz(mat1, COL, FIL);

    printf("Diagonal Principal: \n");
    mostrarDiagonalPrincipal(mat1, COL, FIL);

    printf("\n%d\n", sumaDiagonalConPrincipalAbajo(mat1, COL, FIL));

    printf("\nDiagonal Secunadaria");
    mostrarDiagonalSecundaria(mat1, COL, FIL);

    printf("\nSuma Diagonal Debajo diagonal Secundaria: %d", sumaDebajoDeDiagonalSecunadariaCon(mat1, COL, FIL));

    printf("\nSuma Diagonal Arriba diagonal Secundaria: %d", sumasAribaDeDiagonalSecundariaCon(mat1, COL, FIL));

    if(esIdentidad(iden, COL, FIL))
        printf("\nEs Identidad\n");
    else
        printf("\nNo es idedntidad\n");

    int prod[][COL] =
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    if(productoDeMatrices(mat1, iden, prod, FIL, COL, FIL, COL))
        mostrarMatriz(prod, FIL, COL);

    if(esDiagonal(iden, FIL, COL))
        printf("\nEs diagonal");
    else
        printf("\nNo Es diagonal");

    if(esSimetrica(iden, FIL, COL))
        printf("\nEs simetrica");
    return 0;
}


/**
      j  j  j  j
  i  00 01 02 03
  i  10 11 12 13
  i  20 21 22 23
  i  30 31 32 33
**/
void trasponerMatriz(int m[][4], int filas, int columnas)
{
    int i, j, copia;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            copia  = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = copia;
        }
        printf("\n");
    }

    mostrarMatriz(m, filas, columnas);
}


int esSimetrica(int m[][4], int filas, int columnas)
{
    int i, j;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if(m[i][j] != m[j][i])
            {
                return 0;
            }
        }
    }

    return 1;
}


int esDiagonal(int mat[][4], int filas, int columnas)
{
    int i, j;

    if(!esCuadrada(mat, filas, columnas))
        return 0;

    for(i = 0; i < filas; i++)
        for(j = 0; j < columnas; j++)
        {
            if((i == j && mat[i][j] == 0) || (i != j && mat[i][j] != 0))
                return 0;
        }
    return 1;
}


int trazaSecundaria(int mat[][4], int filas, int columnas)
{
    int i, sum;

    for(i = 0; i < filas; i++)
        sum += mat[i][filas - 1 - i];

    return sum;
}



int traza(int mat[][4], int filas, int columnas)
{
    int i, sum = 0;

    for(i = 0; i < filas; i++)
        sum += mat[i][i];

    return sum;
}

/**
      j  j  j  j
  i  00 01 02 03
  i  10 11 12 13
  i  20 21 22 23
  i  30 31 32 33

      j  j  j  j
  i  00 01 02 03
  i  10 11 12 13
  i  20 21 22 23
  i  30 31 32 33

      j  j  j  j
  i  00 01 02 03
  i  10 11 12 13
  i  20 21 22 23
  i  30 31 32 33
**/
int productoDeMatrices(int mat1[][COL], int mat2[][COL], int mat3[][COL], int filas1, int columnas1, int filas2, int columnas2)
{
    int i, j, k;

    if(columnas1 != filas2)
        return 0;

    for(i = 0; i < filas1; i++)
    {
        for(j = 0; j < columnas2; j++)
        {
            for(k = 0; k < columnas1; k++)
            {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return 1;
}


int esIdentidad(int mat[][4], int filas, int columnas)
{
    int i, j;

    if(!esCuadrada(mat, filas, columnas))
        return 0;

    for(i = 0; i < filas; i++)
        for(j = 0; j < columnas; j++)
        {
            if((i == j && mat[i][j] != 1) || (i != j && mat[i][j] != 0))
                return 0;
        }
    return 1;
}


int esCuadrada(int mat[][4], int filas, int columnas)
{
    return filas == columnas;
}


int sumasAribaDeDiagonalSecundariaCon(int m[][4], int filas, int columnas)
{
    int i, j, suma = 0;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (i + j == filas - 1 || i + j < filas )
            {
                suma += m[i][j];
            }
        }
    }

    return suma;
}


int sumaDebajoDeDiagonalSecunadariaCon(int m[][4], int filas, int columnas)
{
    int i, j, suma = 0;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (i + j == filas - 1 || i + j >= filas )
            {
                suma += m[i][j];
            }
        }
    }

    return suma;
}


int sumaDiagonalConPrincipalAbajo(int mat[][4], int filas, int columnas)
{
    int i, j, sum = 0;

    for(i = 0; i < filas; i++)
        for(j = 0; j < columnas; j++)
        {
            if(i <= j)
                sum += mat[i][j];
        }
    return sum;
}


/**
      j  j  j  j
  i  00 01 02 03
  i  10 11 12 13
  i  20 21 22 23
  i  30 31 32 33
**/
int sumaDeNumerosArribaDeDiagonalPrincipal(int m[][4], int filas, int columnas)
{
    int i, j, suma = 0;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (i < j)
            {
                suma = suma + m[i][j];
            }
        }
    }

    return suma;
}



int sumaDiagonalSinPrincipalAbajo(int mat[][4], int filas, int columnas)
{
    int i, j, sum = 0;

    for(i = 0; i < filas; i++)
        for(j = 0; j < columnas; j++)
        {
            if(i < j)
                sum += mat[i][j];
        }
    return sum;
}


void mostrarDiagonalSecundaria(int mat[][4], int filas, int columnas)
{
    int i;

    for(i = 0; i < filas; i++)
        printf("\n%d", mat[i][filas - 1 - i]);

}


void mostrarDiagonalPrincipal(int mat[][4], int filas, int columnas)
{
    int i;

    for(i = 0; i < filas; i++)
        printf("%d", mat[i][i]);
}


void cargarMatriz(int mat[][4], int filas, int columnas)
{
    int i, j;

    for(i = 0; i < filas; i++)
        for(j = 0; j < columnas; j++)
        {
            printf("Ingrese un valor para la pos [%d] [%d]", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
}


void mostrarMatriz(int mat[][COL], int filas, int columnas)
{
    int i, j;

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
            printf(" |%d", mat[i][j]);
        printf("|\n");
    }
}






