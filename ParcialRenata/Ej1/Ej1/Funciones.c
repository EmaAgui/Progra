#include "Prototipos.h"
#include "Lista.h"
int crearLotePrueba()
{
    FILE *pfTrans = fopen("Transferencias.csv","wt");
    FILE *pfCuen = fopen("Cuentas.dat","wb");

    int i,ce;

    Transferencia mov[] = {{1,"Lucas Rullo",4,"Mika Gonzalez",2000},
        {4,"Mika Gonzalez",2,"Tatiana Rullo",1500},
        {2,"Tatiana Rullo",1,"Lucas Rullo",3000},
        {8,"Renzo Hara",7,"Emanuel Villagra",500},
        {8,"Renzo Hara",1,"Lucas Rullo",500},
        {8,"Renzo Hara",1,"Lucas Rullo",500},
        {7,"Emanuel Villagra",8,"Renzo Hara",5800}
    };

    Cuenta cuentas[] = {{1,"BNC12","Lucas Rullo",85000},
        {2,"BNC12","Tatiana Rullo",45671},
        {4,"BNC12","Mika Gonzalez",120000},
        {7,"BNC12","Emanuel Villagra",26000},
        {8,"BNC12","Renzo Hara",60000}
    };

    if(!pfTrans || !pfCuen)
    {
        printf("no se pudo crear archivo");
        return 0;
    }

    ce=sizeof(mov)/sizeof(mov[0]);

    for(i=0; i<ce; i++)
    {
        fprintf(pfTrans,"%d,%s,%d,%s,%lf\n",mov[i].cta_origen,mov[i].titularO,mov[i].cta_destino,mov[i].titutarD,mov[i].cantidad);
    }

    fwrite(cuentas,sizeof(cuentas),1,pfCuen);

    fclose(pfTrans);
    fclose(pfCuen);

    return 1;
}

void trozarArchivoLV(Transferencia* mov,char* cadena)
{
    char* aux;
    aux = strchr(cadena,'\n');
    *aux = '\0';

    aux = strrchr(cadena,',');
    sscanf(aux+1,"%lf",&mov->cantidad);
    *aux = '\0';

    aux = strrchr(cadena,',');
    strcpy(mov->titutarD,aux+1);
    *aux = '\0';

    aux = strrchr(cadena,',');
    sscanf(aux+1,"%d",&mov->cta_destino);

    *aux = '\0';
    aux = strrchr(cadena,',');
    strcpy(mov->titularO,aux+1);

    *aux = '\0';
    sscanf(cadena,"%d",&mov->cta_origen);

}

void cargarLista(t_lista* lista)
{
    crearLista(lista);
    FILE* pf;
    pf = fopen("Transferencias.csv","rt");
    if(pf == NULL)
        puts("no se pudo abrir archivo");

    char cadena[100];
    Transferencia mov;

    while(fgets(cadena,100,pf))
    {
        trozarArchivoLV(&mov,cadena);
        ponerEnOrden(lista,&mov,sizeof(Transferencia),compararTransferencias,actualizarTransferencias);
    }
    fclose(pf);

}

int compararTransferencias(const void* t1, const void* t2)
{
    Transferencia mov1 = *(Transferencia*)t1;
    Transferencia mov2= *(Transferencia*)t2;
    if((mov1.cta_origen - mov2.cta_origen) == 0)
    {
        return (mov1.cta_destino - mov2.cta_destino);
    }
    return (mov1.cta_origen - mov2.cta_origen);
}


void mostrarTransferencias(const void* t1)
{
    Transferencia mov = *(Transferencia*)t1;
    printf("\n%d,%s,%d,%s,%.2lf",mov.cta_origen,mov.titularO,mov.cta_destino,mov.titutarD,mov.cantidad);
}

void actualizarTransferencias(void* t1,const void*t2)
{
    Transferencia *mov1 = (Transferencia*)t1;  //lista
    Transferencia *mov2 = (Transferencia*)t2;  //dato

    mov1->cantidad+=mov2->cantidad;
}

void actualizarArchivoCuentas(FILE *pfBin, t_lista* lista)
{
    Cuenta cuen;
    Transferencia lTrans;
    t_lista *ini = lista;

    rewind(pfBin);
    fread(&cuen,sizeof(Cuenta),1,pfBin);
    while(!feof(pfBin))
    {
        while(!listaVacia(lista))
        {
            verPrimero(lista, &lTrans, sizeof(Transferencia));
            lista=&(*lista)->sig;
            if(lTrans.cta_origen==cuen.nro_cta)
            {
                cuen.saldo-=lTrans.cantidad;
                fseek(pfBin, (long int)-sizeof(Cuenta), SEEK_CUR);
                fwrite(&cuen,sizeof(Cuenta),1,pfBin);
                fseek(pfBin, 0L, SEEK_CUR);
            }

            if(lTrans.cta_destino==cuen.nro_cta)
            {
                cuen.saldo+=lTrans.cantidad;
                fseek(pfBin, (long int)-sizeof(Cuenta), SEEK_CUR);
                fwrite(&cuen,sizeof(Cuenta),1,pfBin);
                fseek(pfBin, 0L, SEEK_CUR);
            }

        }
        lista=ini;
        fseek(pfBin, 0L, SEEK_CUR);
        fread(&cuen,sizeof(Cuenta),1,pfBin);
    }
}


void mostrarArchivoBinario()
{
    FILE* pf;
    pf = fopen("Cuentas.dat","rb");
    rewind(pf);
    if(pf == NULL)
        puts("no se pudo abrir archivo");

    Cuenta cta;
    fread(&cta,sizeof(Cuenta),1,pf);
    while(!feof(pf))
    {
        printf("\n%d,%s,%s,%.2lf\n",cta.nro_cta,cta.cod_suc,cta.titular,cta.saldo);
        fread(&cta,sizeof(Cuenta),1,pf);
    }
    fclose(pf);
}

void incriptarArch()
{
    FILE *pfNue=fopen("TransInscrip.csv","wt");
    FILE *pfTrans = fopen("Transferencias.csv","rt");
    rewind(pfTrans);
    char cad[500];

    if(!pfNue || !pfTrans)
    {
        return ;
    }

    while(fgets(cad,500,pfTrans))
    {
        ofuscarLinea(cad);
        fprintf(pfNue,"%s\n",cad);
    }
    fclose(pfTrans);
    fclose(pfNue);

}


void ofuscarLinea(char *cad)
{
    while(*cad)
    {
        if(ES_NRO(*cad))
        {

            if(PAR(*cad))
            {
                cambiarCaracteresPar(cad);
            }
            if(IMPAR(*cad))
            {
                cambiarCaracteresImpar(cad);
            }
             cad++;

        }
        else
        {
           cad++;
        }
    }
}


void cambiarCaracteresPar(char *cad)
{
    if(*cad=='0')
    {
        *cad='a';
    }
    if(*cad=='2')
    {
        *cad='e';
    }
    if(*cad=='4')
    {
        *cad='i';
    }
    if(*cad=='6')
    {
        *cad='o';
    }
    if(*cad=='8')
    {
        *cad='u';
    }
}

void cambiarCaracteresImpar(char *cad)
{
    if(*cad=='1')
    {
        *cad='b';
    }
    if(*cad=='3')
    {
        *cad='c';
    }
    if(*cad=='5')
    {
        *cad='d';
    }
    if(*cad=='7')
    {
        *cad='f';
    }
    if(*cad=='9')
    {
        *cad='g';
    }
}



