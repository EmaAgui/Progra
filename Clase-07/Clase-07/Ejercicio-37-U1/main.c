#include <stdio.h>
#include <stdlib.h>

#define COL      3
#define TODO_MAL 0
#define TODO_OK  1


int esCorrecta(int mat[][COL], int ce);
void mostrarVec(int *vec, int ce);
void cargarVecDeMat(int mat[][COL], int filc, int *vec1);
int compararInt(const void* dato1, const void* dato2);


int main()
{
    int mat[][COL] =
    {
        {0, 1, 3},
        {4, 0, 6},
        {3, 0, 0},
    };

    int vec[COL] = {0, 0, 0};
    int i;

    if(esCorrecta(mat, COL))
    {
        printf("Es Correcta");
        cargarVecDeMat( mat, COL, vec);

        for(i = 0; i < COL; i++)
            printf("\nEquipo %d: %d", i + 1, *(vec + i));
    }
    else
    {
        printf("\nEs Incorrecta");
    }

    return 0;
}


int compararInt(const void* dato1, const void* dato2)
{
   int d1 = *(int*)dato1;
   int d2 = *(int*)dato2;

   return d1 - d2;
}


void mostrarVec(int *vec, int ce)
{
    int i;
    for(i = 0; i < ce; i++, vec++)
        printf("%d ", *vec);
}


void cargarVecDeMat(int mat[][COL], int filc, int *vec)
{
    int i, j;
    for(i = 0; i < filc; i++)
    {
        for(j = 0; j < filc; j++)
        {
            if(i == 0)
            {
                vec[i] += mat[i][j];
            }
            if(i == 1)
            {
                vec[i] += mat[i][j];
            }
            if(i == 2)
                vec[i] += mat[i][j];
        }
    }
}


///int esCorrecta(int **mat, int ce)
int esCorrecta(int mat[][COL], int ce)
{
    int i, j;
    void *indice;
    int matPuntos[][6] =
    {
    ///  0  1  2  3  4  5
        {0, 1, 2, 3, 4, 6},
        {6, 4, 2, 3, 1, 0}
    };


    for(i = 0; i < ce; i++)
    {
        for(j = 0; j < ce; j++)
        {
            if(i == j)
            {
                if(mat[i][j] != 0)
                    return TODO_MAL;
            }
            else
            {
                if((indice = bsearch(&mat[i][j], matPuntos[0], 6, sizeof(int), compararInt)) == NULL)
                    return TODO_MAL;

//               printf("\n%d", *((int*)(indice+6*(sizeof(int)))));

                if(mat[j][i] != *((int*)(indice+6*(sizeof(int)))))
                    return TODO_MAL;
            }
        }
    }

    return TODO_OK;
}
