#include <stdio.h>
#include <stdlib.h>

#define COL      3
#define TODO_MAL 0
#define TODO_OK  1


int esCorrecta(int mat[][COL], int ce);
void mostrarVec(int *vec, int ce);
void cargarVecDeMat(int mat[][COL], int filc, int *vec1);


int main()
{

    int mat[][COL] =
    {
        {0, 1, 3},
        {1, 0, 3},
        {0, 0, 0},
    };
    int vec[COL] = {0, 0, 0};


    if(esCorrecta(mat, COL))
    {
        printf("\nEs Correcta");
        cargarVecDeMat( mat, COL,vec);
        printf("\nEquipo 1:%d", *vec);
        printf("\nEquipo 1:%d", *(vec + 1));
        printf("\nEquipo 1:%d", *(vec + 2));

    }
    else
    {
        printf("\nEs Incorrecta");

    }

    return 0;
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

int esCorrecta(int mat[][COL], int ce)
{
    int i, j;

    for(i = 0; i < ce; i++)
    {
        for(j = 0; j < ce; j++)
        {
            if(i == j )
            {
                if(mat[i][j] != 0)
                    return TODO_MAL;
            }
            else
            {

                switch(mat[i][j])
                {
                case 3:
                    if(mat[j][i] != 0)
                        return TODO_MAL;
                    break;
                case 1:
                    if(mat[j][i] != 1)
                        return TODO_MAL;
                    break;
                case 0:
                    if(mat[j][i] != 3)
                        return TODO_MAL;
                    break;
                default:
                    return TODO_MAL;
                }
            }
        }
    }

    return TODO_OK;
}
