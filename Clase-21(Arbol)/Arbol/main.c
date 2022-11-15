#include "Arbol.h"


#define ARCH_BIN_IDX "EmpleadosIdx.dat"

/**
    Arbol avl: la diferencia entre cualquier subarbol izq y der es a lo sumo de 1
        si en alguno de sus subarbeles hay alguna diferencia
    eliminarNodoRaiz
**/

typedef struct
{
    int dni; ///campo clave
    int pos; //pos del archivo, usar fseek
}Idx;

typedef struct
{
    int dni; ///campo clave
    char nombre[20];
}Empleado;



int compararInt(const void *d1, const void *d2);
void mostrarInt(const void *d1);


int compararIdx(const void *d1, const void *d2);
void mostrarIdx(const void *d1);
void mostrarArchivoBin(const char *nombre, void *dato, unsigned tamBytes, void mostrar(const void * d1));


void crearLote();
void grabar(void *d1);
void cargarArbol(Arbol *pa);
int buscarEmpleadoPorDni(Arbol *pArb, const void *dato, unsigned tamBytes, void *dato2, int cmp(const void *d1, const void *d2));


int main()
{
    Arbol arbol;
    Empleado emp;
    Idx empIdx;

    crearLote();

    crearArbol(&arbol);
    cargarArbol(&arbol);

    mostrarArbolInOrden(&arbol, 0, mostrarIdx);

    mostrarArbolPreOrden(&arbol, grabar);

    int dniABuscar = 16;

    if(buscarEmpleadoPorDni(&arbol, &dniABuscar, sizeof(dniABuscar), &emp, compararIdx))
    {
        printf("\n\nDni[%d], Nombre[%s]\n", emp.dni, emp.nombre);
    }
    else
    {
        printf("No se encontro\n");
    }

    printf("\nArchivo del Arbol\n\n");

    mostrarArchivoBin(ARCH_BIN_IDX, &empIdx, sizeof(empIdx), mostrarIdx);

    return 0;
}


void mostrarArchivoBin(const char *nombre,  void *dato, unsigned tamBytes, void mostrar(const void * d1))
{
    FILE *p = fopen(nombre, "rb");

    if(!p)
        return;

    fread(dato, tamBytes, 1, p);

    while(!feof(p))
    {
        mostrar(dato);
        fread(dato, tamBytes, 1, p);
    }

    fclose(p);
}


int buscarEmpleadoPorDni(Arbol *pArb, const void *dato, unsigned tamBytes, void *dato2, int cmp(const void *d1, const void *d2))
{
    FILE *pArch = fopen("Empleados.dat", "rb");
    Arbol *pa;
    Idx empIdx;
    void *d1 = malloc(tamBytes);

    if(!d1)
        return 0;

    memcpy(d1, dato, tamBytes);

    if((pa = buscarNodoAElim(pArb, d1, cmp)) != NULL)
    {
        memcpy(&empIdx, (*pa)->info, minimo(sizeof(Idx), (*pa)->tamBytes));
        fseek(pArch, empIdx.pos * sizeof(Empleado) , SEEK_SET);
        fread(dato2, sizeof(Empleado), 1, pArch);

        fclose(pArch);
        free(d1);
        return 1;
    }
    else
    {
        fclose(pArch);
        free(d1);
        return 0;
    }

}


void cargarArbol(Arbol *pa)
{
    FILE *pArch = fopen("Empleados.dat", "rb");
    Empleado emp;
    Idx empIdx;
    int pos = 0;

    if(!pArch)
        return;

    fread(&emp, sizeof(Empleado), 1, pArch);

    empIdx.dni = emp.dni;
    empIdx.pos = pos;

    while (!feof(pArch))
    {
        insertarEnArbol(pa, &empIdx, sizeof(empIdx), compararIdx);
        fread(&emp, sizeof(Empleado), 1, pArch);

        pos++;
        empIdx.dni = emp.dni;
        empIdx.pos = pos;

    }

    fclose(pArch);
}


void grabar(void *d1)
{
    Idx indice = *(Idx*)d1;
    FILE *pArch = fopen("EmpleadosIdx.dat", "wb");

    if(!pArch)
        return;

    fwrite(&indice, sizeof(Idx), 1, pArch);

    fclose(pArch);
}

void crearLote()
{
    Empleado vEmp[] =
    {
        {16, "Nombre1"},
        {25, "Nombre2"},
        {15, "Nombre3"},
        {65, "Nombre4"},
        {11, "Nombre5"},
    };

    FILE *pa = fopen("Empleados.dat", "wb");

    if(!pa)
        return;

    fwrite(vEmp, sizeof(Empleado), 5, pa);

    fclose(pa);
}


void mostrarIdx(const void *d1)
{
    Idx dato = *(Idx*)d1;

    printf("Dni[%d], Pos[%d]\n", dato.dni, dato.pos);
}


int compararIdx(const void *d1, const void *d2)
{
    Idx dato1 = *(Idx*)d1;
    Idx dato2 = *(Idx*)d2;

    return dato1.dni - dato2.dni;
}


void mostrarInt(const void *d1)
{
    int dato1 = *(int*)d1;

    printf("%d\n", dato1);
}


int compararInt(const void *d1, const void *d2)
{
    int dato1 = *(int*)d1;
    int dato2 = *(int*)d2;

    return dato1 - dato2;
}
