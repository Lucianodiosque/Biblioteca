#include "peliculas.h"
#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1

int ePeli_init_Peliculas(ePelicula array[],int tam)
{
    int i;
    int error=-1;
    if(array!= NULL || tam<0)
    {
        for(i=0; i<tam; i++)
        {
            array[i].estado=LIBRE;
            error=0;
        }
    }
    return error;
}

void ePeli_Harcodear_Peliculas(ePelicula peliculas[],int tam,eGenero genero[],int tamGene)
{
    int i,j;

    char titulo[][30]= {"Avengers EndGame","Thor","Cellular","Men in Black 4","IronMan","13 Going on 30","Lucy","Nace una estrella","¿Dime con cuantos?","Guardianes de la Galaxia","A perfect murder","La isla","Que paso ayer","Home Alone 3","DeadPool","Sherlock Holmes","Men in Black 3","Avengers Infinity War","Grandes esperanzas","SWAT","XxX"};
    int dia[]= {20,10,2,10,5,7,9,8,4,20,6,3,5,6,7,5,2,6,8,20,11};
    int mes[]={4,6,5,7,9,5,2,3,4,5,8,10,2,10,12,6,5,4,12,2,5};
    int anio[]={2019,2013,2004,2019,2012,2004,2014,2018,2010,2014,1995,2005,2013,1997,2015,2011,2010,2017,1995,1998,1992};
    int generos[]={1,1,1,1,1,4,1,4,4,1,3,3,2,2,1,1,1,1,4,1,1};
    int idActor[]= {2,5,4,5,2,3,1,9,4,9,7,1,9,1,10,2,10,10,7,6,6};
    int idPelicula[]= {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,1019,1020};

    for(i=0; i<tam; i++)
    {
       for(j=0;j<tamGene;j++)
       {
           strcpy(peliculas[i].titulo,titulo[i]);
            peliculas[i].fechaDeEstreno.dia=dia[i];
            peliculas[i].fechaDeEstreno.mes= mes[i];
            peliculas[i].fechaDeEstreno.anio=anio[i];
            if(genero[j].idPelicula=generos[i])
            {
                peliculas[i].genero=generos[i];
            }
            peliculas[i].idActor=idActor[i];
            peliculas[i].idPelicula=idPelicula[i];
            peliculas[i].estado=OCUPADO;
            break;
       }

    }

}

int ePeli_add_Peliculas(ePelicula array[],int tam,eGenero genero[],int tamgene)
{
    int i,j,funcRetorno=-1,validarr;
    char opcion;
    char valida[400];
    int validacion;
    if(tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if(array[i].estado==LIBRE)
            {
                ePeli_IdGenerador(array,tam,i);
                system("cls");
                printf("Ingrese nombre de la pelicula: \n");
                fflush(stdin);
                gets(array[i].titulo);
                do
                {
                    system("cls");
                    printf("Ingrese dia de la pelicula: \n");
                    scanf("%s",valida);
                    validacion=validar_Num(valida);
                    if(validacion==1)
                    {
                        array[i].fechaDeEstreno.dia=atoi(valida);
                        break;
                    }
                }while(validacion==0);
                do
                {
                    system("cls");
                    printf("Ingrese mes de la pelicula: \n");
                    scanf("%s",valida);
                    validacion=validar_Num(valida);
                    if(validacion==1)
                    {
                        array[i].fechaDeEstreno.mes=atoi(valida);
                        break;
                    }
                }while(validacion==0);
                do
                {
                    system("cls");
                    printf("Ingrese año de la pelicula: \n");
                    scanf("%s",valida);
                    validacion=validar_Num(valida);
                    if(validacion==1)
                    {
                        array[i].fechaDeEstreno.anio=atoi(valida);
                        break;
                    }
                }while(validacion==0);
                mostrarGeneros(genero,tamgene);
                do
                {
                    printf("Ingrese genero de la pelicula: \n");
                    scanf("%s",valida);
                    validacion=validar_Num(valida);
                    if(validacion==1)
                    {
                        for(j=0;j<tamgene;j++)
                        {
                            validarr=atoi(valida);
                           if(validarr==genero[j].idPelicula)
                            {
                                array[i].genero=validarr;
                                validacion=1;
                                break;

                            }
                            else
                            {

                                validacion=0;
                            }
                        }
                    }
                }while(validacion==0);
                    break;
                }

          }

    funcRetorno=0;
    }
    return funcRetorno;
}

int validar_Num(char numero[])
{
    int i;
    int error=1;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            printf("INCORRECTO:INGRESE SOLO NUMEROS!\n");
            getch();
            error=0;
            break;
        }
    }
    return error;
}

int validar_cadena(char palabra[]) // LO MISMO QUE VALIDAR NUM
{
    int i;
    int error=1;
    for(i=0; i<strlen(palabra); i++)
    {
        if(!(isalpha(palabra[i])))
        {
            printf("INCORRECTO: INGRESE SOLO LETRAS!\n");
            getch();
            error=0;
            break;
        }
    }
    return error;
}

void ePeli_IdGenerador(ePelicula lista[],int tam,int posicion)
{
    int maximo;
    maximo=ePeli_BuscarIdMaximo(lista,tam);
    maximo=maximo+1;
    lista[posicion].idPelicula=maximo;

}

int ePeli_BuscarIdMaximo(ePelicula lista[],int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            index=lista[i].idPelicula;
        }
    }
    return index;
}

void ePeli_Mostrar_Peliculas(ePelicula lista[],int tam,eGenero genero[],int tamGene)
{
    int i,j;
    for(i=0;i<tam;i++)
    {
        for(j=0;j<tamGene;j++)
        {
           if(lista[i].estado==OCUPADO)
            {
                if(lista[i].genero==genero[j].idPelicula)
                {

                    printf("%d --- %s --- %d/%d/%d --- %s ---%d \n",lista[i].idPelicula,lista[i].titulo,lista[i].fechaDeEstreno.dia,lista[i].fechaDeEstreno.mes,lista[i].fechaDeEstreno.anio,genero[j].descripcion,lista[i].idActor);
                    break;
                }


            }
        }

    }
}

int ePeli_BuscarLibre(ePelicula lista[],int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
int ePeli_remove_Peliculas(ePelicula list[],int len, char id[])
{
    int i;
    int encontro=-1;
    char opcion;
    for(i=0;i<len;i++)
    {
        if(list[i].idPelicula==id && list[i].estado==OCUPADO)
        {
            printf("Esta seguro que desea eliminar esta pelicula?(s/n)\n");
            scanf("%s",&opcion);
            if(opcion=='s')
            {
                list[i].estado=ELIMINADO;
                encontro=1;
            }

            break;
        }
    }
    return encontro;
}

void ePeli_Ordenar_Peliculas_Por_Anio(ePelicula pelicula[],int tam)
{
    int i,j;
    ePelicula aux;
    for(i=0;i<tam;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(pelicula[i].fechaDeEstreno.anio>pelicula[j].fechaDeEstreno.anio)
            {
                aux=pelicula[i];
                pelicula[i]=pelicula[j];
                pelicula[j]=aux;
            }
        }
    }
}

