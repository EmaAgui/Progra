#include <stdio.h>
#include <stdlib.h>

#define COL 5
#define FIL 3

#define ORD 6

/**
    Matriz: arrays bidimensionales, consecutivos en memoria.
    i=1, j=1 = mat + col*i + j
**/

void elementosDebajoDiagPrinc(int mat[][ORD], int col);

int main()
{
    int mat[FIL][COL] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int mat3[][ORD] =
    {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36},
    };

    elementosDebajoDiagPrinc(mat3, 6);
    return 0;
}

///i = j
void elementosDebajoDiagPrinc(int mat[][ORD], int col)
{
    int i, j;
    for(i = 1; i < col; i++)
    {
        for(j = 0; j < i; j++)
        {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
}
