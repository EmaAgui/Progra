
///Vectores

void* buscar(const void *vec, size_t ce, size_t tam, void* elem,
             int (*cmp)(const void*, const void*))
{
    while(ce)
    {
        if(cmp(vec, elem)==0)
        {
            return (void*) vec;
        }
        vec+=tam;
        ce--;
    }
    return NULL;
}


void* amap(void *vec, size_t ce, size_t tam, void(*accion)(void*))
{
    void* ini=vec;
    while(ce)
    {
        accion(vec);
        ce--;
        vec+=tam;
    }
    return ini;
}


void* reduce(void*vec, size_t ce, size_t tam, void* valor_retorno,
             void (*freduccion)(void*vr, const void* e))
{
    while(ce)
    {
        freduccion(valor_retorno, vec);
        ce--;
        vec+=tam;
    }
    return valor_retorno;
}


void* filter(void*vec, size_t *ce, size_t tam,
             int (*ffilter)(const void*))
{
    void *pl = vec, *pe = vec;
    int ciclos = *ce;

    while(ciclos--)
    {
        if(ffilter(pl))
        {
            if(pe!=pl)
                memcpy(pe, pl, tam);
            pe+=tam;
        }else{
            (*ce)--;
        }
        pl+=tam;
    }
    return vec;
}


void eliminarTodasAparicionesGenerica(void *vec, int *ce, const void *dato, size_t tam, int cmp(const void *d1, const void *d2))
{
    void *fin = vec + (((*ce)) * tam);
    void *ini = vec;

    while(ini < fin)
    {
        if((cmp(dato, ini) == 0))
        {
            memmove(ini, ini + tam, fin - ini + tam);
            (*ce)--;
        }
        else
            ini += tam;
    }
}


void eliminarGenerica(void *vec, int *ce, const void *dato, size_t tam, int cmp(const void *d1, const void *d2))
{
    void *fin = vec + (((*ce)) * tam);
    void *ini = vec;

    while(ini < fin && cmp(dato, ini) != 0)
        ini += tam;

    if (ini != fin)
    {
        memmove(ini, ini + tam, fin - ini + tam);
        (*ce)--;
    }

}


void insertarOrdenado(void *vec, int ce, const void *dato, size_t tam, int cmp(const void *d1, const void *d2))
{
    void *fin = vec + ((ce) * tam);  // Calcula un puntero al final del vector
    void *ini = vec;                     // Establece un puntero al inicio del vector

    while (ini < fin && cmp(dato, ini) > 0)
        ini += tam;                       // Avanza al siguiente elemento mientras el dato a insertar sea mayor que el elemento actual

    memmove(ini + tam, ini, fin - ini + tam);  // Desplaza los elementos hacia adelante para hacer espacio para el nuevo elemento
    memcpy(ini, dato, tam);               // Copia el dato a insertar en la posición correcta
}


void *busquedaBinaria(const void *clave, const void *base, size_t ce, size_t tam, int(*cmp)(const void *d1, const void *d2))
{
    int li, ls, pm, comp;
    li = 0;
    ls = ce - 1;

    while(li <= ls)
    {
        pm = (li +ls) / 2;
        comp = cmp(base + (pm * tam), clave);

        if(comp == 0)
            return (void*)(base + (pm * tam));
        if(comp > 0)
            ls = pm -1;
        if(comp < 0)
            li = pm + 1;
    }

    return NULL;
}

void * buscarMenor(const void * vec,
                   const void * fin,
                   size_t tam,
                   int (*cmp)(const void*, const void*));

void * orenarSeleccion(void * vec,
                     size_t ce,
                     size_t tam,
                     int (*cmp)(const void*, const void*))
{
    void * ini = vec,
         * fin = vec + (ce - 1) * tam,
         * men;

    while(vec < fin)
    {
        men = buscarMenor(vec, fin, tam, cmp);
        if (vec!=men)
        {
            intercambiar(vec, men, tam);
        }
        vec+=tam;
    }
    return ini;
}
/// >0 1ero mayor
/// <0 1ero menor
/// =0 iguales

void * buscarMenor(const void * vec,
                   const void * fin,
                   size_t tam,
                   int (*cmp)(const void*, const void*)
                   )
{
    const void * men = vec;
    vec+=tam;

    while(vec <= fin)
    {
        if (cmp(vec, men)<0)
        {
            men = vec;
        }
        vec+=tam;
    }
    return (void *) men;
}



void intercambiar(void * e1, void * e2, size_t tam)
{
    void * aux = malloc(tam);
    if (!aux)
        return;

    memcpy(aux, e1, tam);
    memcpy(e1, e2, tam);
    memcpy(e2, aux, tam);

    free(aux);
}


///Archivos
#include "Funciones.h"


void mostrarEmp(const void *dato)
{
    const Empleado *emp = (const Empleado*)dato;

    printf("Dni:[%d], Nombre: [%s], Apelido: [%s], sueldo: [%.2f]\n",
           emp->dni, emp->nombre, emp->apellido, emp->sueldo);
}

void mostraBin(const char *nombreArch, size_t tam, void mostrar(const void *dato))
{
    void *dato = malloc(tam);
    FILE *arch = fopen(nombreArch, "rb");

    if(!dato || !arch)
    {
        fclose(arch);
        free(dato);
        return;
    }

    fread(dato, tam,1, arch);
    while(!feof(arch))
    {
        mostrar(dato);
        fread(dato, tam,1, arch);
    }

    fclose(arch);
    free(dato);

}

void actualizar(const void* nombreTxt, const void* nombreBin)
{
    FILE *archEst, *archEmp;
    Estudiante est;
    Empleado emp;
    int i, cmp;


    archEst = fopen(nombreTxt, "rt");
    archEmp = fopen(nombreBin, "r+b");

    if(!archEst || !archEmp)
    {
        fclose(archEst);
        fclose(archEmp);
        return;
    }

    fread(&emp, sizeof(Empleado), 1, archEmp);
    i = fscanf(archEst,"%d|%[^|\n]|%[^|\n]|%f\n", &est.dni, est.apellido, est.nombre, &est.promedio);

    while(!feof(archEmp) && i != EOF)
    {
        cmp = emp.dni - est.dni;
        if(cmp < 0)
            fread(&emp, sizeof(Empleado), 1, archEmp);
        else if(cmp > 0)
            i = fscanf(archEst,"%d|%[^|\n]|%[^|\n]|%f\n", &est.dni, est.apellido, est.nombre, &est.promedio);
        else
        {
            if(est.promedio >= 7)
            {
                emp.sueldo *= 1.0728;
                fseek(archEmp, (int)sizeof(Empleado) *-1, SEEK_CUR);
                fwrite(&emp, sizeof(Empleado), 1, archEmp);
                fseek(archEmp, 0L, SEEK_CUR);
            }
            fread(&emp, sizeof(Empleado), 1, archEmp);
            i = fscanf(archEst,"%d|%[^|\n]|%[^|\n]|%f\n", &est.dni, est.apellido, est.nombre, &est.promedio);
        }
    }


    fclose(archEst);
    fclose(archEmp);
}


int crearLoteEst(const void* nombreTxt)
{
    FILE *archEst;
    int i;
    Estudiante vEst[]=
    {
        {123, "Lopez", "Juan", 7},
        {234, "Rodriguez", "Ana", 5},
        {345, "Sanchez", "Carlos", 2},
        {432, "Ramirez", "Mariana", 10},
        {567, "Gonzalez", "Pedro", 8},
        {789, "Perez", "Luis", 6},
        {890, "Martinez", "Laura", 9},
        {901, "Torres", "Diego", 8},
    };

    archEst = fopen(nombreTxt, "wt");
    if(!archEst)
        return -10;

    for(i = 0; i < 8; i++)
        fprintf(archEst, "%d|%s|%s|%f\n", vEst[i].dni, vEst[i].apellido, vEst[i].nombre, vEst[i].promedio);

    fclose(archEst);

    return 1;
}


int crearLoteEmp(const void* nombreBin)
{
    FILE *archEmp;
    Empleado vEmp[] =
    {
        {123, "Lopez", "Juan", 2500.0},
        {234, "Rodriguez", "Ana", 4000.0},
        {345, "Sanchez", "Carlos", 2200.0},
        {456, "Gomez", "Maria", 3200.0},
        {567, "Gonzalez", "Pedro", 3100.0},
        {678, "Fernandez", "Sofia", 2700.0},
        {789, "Perez", "Luis", 1800.0},
        {901, "Torres", "Diego", 3500.0},
    };



    archEmp = fopen(nombreBin, "wb");

    if(!archEmp)
        return -10;

    fwrite(vEmp, sizeof(Empleado), sizeof(vEmp) / sizeof(*vEmp), archEmp);

    fclose(archEmp);

    return 1;
}


void trozarArchFijo(void *dato, char *cad)
{
    Alumno *alu = (Alumno*)dato;
    char *aux = cad;

    while(*aux)
        aux++;

    *aux = '\0';

    aux -= 6;
    sscanf(aux, "%f", &(alu->nota));
    *aux = '\0';

    aux -= 29;
    strcpy(alu->nombre, aux);
    *aux = '\0';

    sscanf(cad, "%d", &(alu->dni));

}

void trozarEmpleado(char *cad, Empleado *emp)
{
    char *aux = strchr(cad, '\n');
    *aux = '\0';

    aux = strrchr(cad, '|');
    sscanf(aux + 1, "%f", &emp->sueldo);
    *aux = '\0';

    aux = strrchr(cad, '|');
    sscanf(aux + 1, "%c", &emp->sexo);
    *aux = '\0';

    aux = strrchr(cad, '|');
    strcpy(emp->apellido, aux + 1);
    *aux = '\0';

    aux = strrchr(cad, '|');
    strcpy(emp->nombre, aux + 1);
    *aux = '\0';

    sscanf(cad, "%d", &emp->dni);

}


///Recursivas
char *rStrchr(const char *cad, int c)
{
    if(!*cad)
        return NULL;

    if(*cad == c)
            return (char*)cad;

    return rStrchr(cad + 1, c);
}

char *rStrrchr(const char *cad, int c)
{
    if (*cad == '\0')
        return NULL;

    char *result = rStrrchr(cad + 1, c);

    if (result != NULL)
        return result;

    if (*cad == c)
        return (char*)cad;

    return NULL;
}


int rPalindromo(const char *ini, const char *fin)
{
    if (ini >= fin)
        return 1;

    if (!isalpha(*ini))
        return rPalindromo(ini + 1, fin);

    if (!isalpha(*fin))
        return rPalindromo(ini, fin - 1);

    if (toupper(*ini) != toupper(*fin))
        return 0;

    return rPalindromo(ini + 1, fin - 1);
}


int esPalindromo(const char *cad)
{
    const char *fin = cad;

    while(*fin)
        fin++;
    fin--;

    return rPalindromo(cad, fin);
}


void mostrarInt(void* d)
{
    int *n = (int*)d;
    printf("%d\n", *n);
}


void aMap(void *vec, unsigned ce, unsigned tam, void (*accion)(void* d))
{
    if(ce == 0)
        return;

    accion(vec);

    aMap((char*)vec + tam, ce - 1, tam, accion);
}


size_t rStrlen(const char *cad)
{
    if(*cad == '\0')
        return 0;

    return 1 + rStrlen(++cad);
}


int factorial(int n)
{
    if(n == 0)
        return 1;

    return n * factorial(n - 1);
}

void *rBinaria(int li, int ls, size_t tam, const void *clave, const void *base, int(*cmp)(const void *d1, const void *d2))
{
    int pm, comp;

    pm = (li + ls) / 2;
    comp = cmp(base + (pm * tam), clave);

    if(li > ls)
        return NULL;


    if(comp == 0)
        return (void*)(base + (pm * tam));
    if(comp > 0)
        return rBinaria(li, pm - 1, tam, clave, base, cmp);
    if(comp < 0)
        return rBinaria(pm + 1, ls, tam, clave, base, cmp);

    return NULL;
}



void *busquedaBinaria(const void *clave, const void *base, size_t ce, size_t tam, int(*cmp)(const void *d1, const void *d2))
{
    int li, ls;
    li = 0;
    ls = ce - 1;

    return rBinaria(li, ls, tam, clave, base, cmp);
}


///Matrices

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


void recorrerMatrizEspiral(void *mat, int filas, int columnas, size_t tam, void accion(void *d))
{
    int iniFila, iniColumna, finFila, finColumna, f, c;

    iniFila = 0;
    finFila = filas - 1;
    iniColumna = 0;
    finColumna = columnas - 1;

    while (iniFila <= finFila && iniColumna <= finColumna)
    {
        // Derecha a Izquierda
        for (c = iniColumna; c <= finColumna; c++)
            accion(mat + (iniFila * columnas + c) * tam);

        // Arriba a Abajo
        for (f = iniFila + 1; f <= finFila; f++)
            accion(mat + (f * columnas + finColumna) * tam);

        // Derecha a Izquierda
        if (iniFila < finFila)
        {
            for(c = finColumna - 1; c >= iniColumna; c--)
                accion(mat + (finFila * columnas + c) * tam);
        }

        // Abajo hacia Arriba
        if (iniColumna < finColumna)
        {
            for (f = finFila - 1; f > iniFila; f--)
                accion(mat + (f * columnas + iniColumna) * tam);
        }

        iniFila++;
        finFila--;
        iniColumna++;
        finColumna--;
    }
}


int _contarCelulasVivasEnVecindario(int mat[][MAX_COL], int filas, int columnas, int fila, int columna)
{
    int contador = 0;

    // Verificar las celdas en el vecindario de la posición dada
    for (int i = fila - 1; i <= fila + 1; i++)
    {
        for (int j = columna - 1; j <= columna + 1; j++)
        {
            // Verificar si la posición está dentro de los límites de la matriz
            if (i >= 0 && i < filas && j >= 0 && j < columnas)
            {
                // Verificar si la celda está viva (valor 1)
                if (mat[i][j] == 1)
                    contador++;
            }
        }
    }

    // Restar 1 al contador si la posición dada también está viva
    if (mat[fila][columna] == 1)
        contador--;

    return contador;
}

void mostrar(int mat[][7])
{
    int i,j;
    for(i=0;i<TAM;i++)
    {
        for(j=0;j<TAM;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void primer_cuadrante(int mat[][7])
{
    int i,j;
    for(i=0;i<=TAM/2;i++)
    {
        for(int k=0;k<i;k++) printf("   ");

        for(j=i;j<TAM-i;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void segundo_cuadrante(int mat[][7])
{
    int i,j;
    for(i=0;i<TAM;i++)
    {
        for(j=0;(i<=TAM/2)?(j<=i):(j<TAM-i);j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void tercer_cuadrante(int mat[][7])
{
    int i,j;
    for(i=TAM/2-1;i<TAM;i++)
    {
        for(int k=0;k<TAM-i-1;k++) printf("   ");

        for(j=TAM-i-1;j<=i;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void cuarto_cuadrante(int mat[][7])
{
    int i,j;
    for(i=0;i<TAM;i++)
    {
        for(int k=0;k<((i<TAM/2)?(TAM-i-1):(i));k++) printf("   ");

        for(j=(i<TAM/2)?(TAM-i-1):(i);j<TAM;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

///Cadenas
int _cmp_str(const void* a, const void* b)
{
    const char *c1 = (const char *)a;
    const char *c2 = (const char *)b;

    while(*c1 && *c2)
    {
        if(*c1 > *c2)
            return 1;

        if(*c1 < *c2)
            return -1;

        c1++;
        c2++;
    }
    if(*c1)
        return 1;
    if(*c2)
        return -1;

    return 0;
}


char* _mstrstr(const char *s1, const char *s2)
{
    if (*s2 == '\0')
        return (char*)s1; // Si s2 está vacía, devuelve s1

    while (*s1 != '\0')
    {
        const char *p1 = s1;
        const char *p2 = s2;

        while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2)
        {
            p1++;
            p2++;
        }

        if (*p2 == '\0')
            return (char*)s1; // Se encontró la subcadena, devuelve la ubicación en s1

        s1++; // Avanza al siguiente carácter en s1
    }

    return NULL; // No se encontró la subcadena
}


int contar_palabra(char *palabra, char *texto)
{
    int contador = 0;
    int longitud_texto = strlen(texto);
    int longitud_palabra = strlen(palabra);

    if (longitud_palabra > longitud_texto)
        return 0;

    for (int i = 0; i <= longitud_texto - longitud_palabra; i++)
    {
        if (strncmp(texto + i, palabra, longitud_palabra) == 0)
            contador++;
    }

    return contador;
}
