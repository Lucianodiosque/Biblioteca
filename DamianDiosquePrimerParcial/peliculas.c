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

void ePeli_Harcodear_Peliculas(ePelicula peliculas[],int tam)
{
    int i;

    char titulo[][20]= {"Masacre","La Tierra","Muerte","GOT","Masacre Dos","Muerte en la playa"};
    int dia[]= {20,10,06,05,07,27};
    int mes[]={06,10,12,03,01,07};
    int anio[]={1991,2008,2001,1947,2030,2015};
    eGenero generos[20]= {{"Terror"},{"Documental"},{"Terror"},{"Fantasia"},{"Terror"},{"Terror"}};
    int idActor[]= {1,2,3,4,5,6};
    int idPelicula[]= {100,101,102,103,104,105,106};

    for(i=0; i<tam; i++)
    {
        strcpy(peliculas[i].titulo,titulo[i]);
        peliculas[i].fechaDeEstreno.dia=dia[i];
        peliculas[i].fechaDeEstreno.mes= mes[i];
        peliculas[i].fechaDeEstreno.anio=anio[i];
        strcpy( peliculas[i].genero.generos,generos[i].generos) ;
        peliculas[i].idActor=idActor[i];
        peliculas[i].idPelicula=idPelicula[i];
        peliculas[i].estado=OCUPADO;
    }

}

int ePeli_add_Peliculas(ePelicula array[],int tam)
{
    int i,funcRetorno=-1;
    char opcion;
    char valida[400];
    int validacion;
    if(tam>0)
    {
       printf("Desea ingresar un usuario? (s/n)");
        scanf("%s",&opcion);
        while(opcion=='s')
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
                        }
                        while(validacion==0);
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
                    do
                    {
                        system("cls");
                        printf("Ingrese genero de la pelicula: \n");
                        scanf("%s",valida);
                        validacion=validar_cadena(valida);
                        if(validacion==1)
                        {
                            strcpy(array[i].genero.generos,valida);
                            break;
                        }
                    }while(validacion==0);
                    do
                    {
                        system("cls");
                        printf("Ingrese actor de la pelicula: \n");
                        scanf("%s",valida);
                        validacion=validar_Num(valida);
                        if(validacion==1)
                        {
                            array[i].idActor=atoi(valida);
                        }
                    }
                    while(validacion==0);
                    array[i].estado=OCUPADO;
                    fflush(stdin);
                    printf("Desea ingresar un usuario mas? (s/n)");
                    scanf("%s",&opcion);
                    if(opcion=='n')
                    {
                        break;
                    }
                }
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

void ePeli_Mostrar_Peliculas(ePelicula lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==OCUPADO)
        {

            printf("%d --- %s --- %d/%d/%d --- %s ---%d \n",lista[i].idPelicula,lista[i].titulo,lista[i].fechaDeEstreno.dia,lista[i].fechaDeEstreno.mes,lista[i].fechaDeEstreno.anio,lista[i].genero.generos,lista[i].idActor);


        }
    }
}

int ePeli_modify_Peliculas(ePelicula list[],int len)
{
    int i;
    int opcion,opcion3;
    char opcion2;
    int error =-1;
    if(len>0||list!=NULL||ePeli_BuscarLibre(list,len)==-1)
    {
        ePeli_Mostrar_Peliculas(list,len);
        printf("Ingrese el id de la pelicula a modificar:\n");
        scanf("%d",&opcion);
        for(i=0;i<len;i++)
        {
          if(opcion==list[i].idPelicula)
            {
                printf("Esta seguro que desea modificar ese id?(s/n)\n");
                scanf("%s",&opcion2);
                if(opcion2=='s')
                {
                    printf("Ingrese opcion a modificar\n");
                    printf("1-Titulo\n2-Fecha de Estreno\n3-Actor\n");
                    scanf("%d",&opcion3);
                    switch(opcion3)
                    {
                        case 1:
                            printf("Ingrese Nuevo Titulo:\n");
                            fflush(stdin);
                            gets(list[i].titulo);
                            error=0;
                            break;
                        case 2:
                            printf("Ingrese nueva Fecha de Estreno:\n");
                            printf("Primero ingrese el dia\n");
                            scanf("%d",&list[i].fechaDeEstreno.dia);
                            fflush(stdin);
                            printf("Ahora ingrese el mes:\n");
                            scanf("%d",&list[i].fechaDeEstreno.mes);
                            fflush(stdin);
                            printf("Y por ultimo ingrese el anio:\n");
                            scanf("%d",&list[i].fechaDeEstreno.anio);
                            error=0;
                            break;
                        case 3:
                            printf("Ingrese nuevo actor:\n");
                            scanf("%d",&list[i].idActor);
                    }
                }
            }
        }
    }
    return error;
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
