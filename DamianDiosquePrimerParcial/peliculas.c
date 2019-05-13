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

    char titulo[][20]= {"Masacre","La Tierra","Muerte","GOT","Masacre Dos","Muerte en la playa"};
    int dia[]= {20,10,06,05,07,27};
    int mes[]={06,10,12,03,01,07};
    int anio[]={1991,2008,2001,1947,2030,2015};
    int generos[]={1,2,3,1,3,2};
    int idActor[]= {1,2,3,4,5,6};
    int idPelicula[]= {100,101,102,103,104,105,106};

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
                if(array[i].idPelicula<1000)
                {
                    do
                    {
                    system("cls");
                    printf("Ingrese id de la pelicula: \n");
                    scanf("%s",valida);
                    validacion=validar_Num(valida);
                    if(validacion==1)
                    {
                        array[i].idPelicula=atoi(valida);
                        break;
                    }
                    }while(validacion==0);
                }
                else
                {
                    ePeli_IdGenerador(array,tam,i);
                }
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
    maximo=maximo+100;
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

