#include "actores-pelis.h"
#define OCUPADO 1
#define LIBRE 0
void eMostrar(ePelicula lista[],int tam,eActores act[],int tamAct,eGenero genero[],int tamgen)
{
    int i,j,k;
    printf("ID\t               TITULO\t      FECHA\t     ACTOR\t  GENERO\n");
    for(i=0;i<tam;i++)
    {
      if(lista[i].estado==OCUPADO)
      {
        for(k=0;k<tamAct;k++)
        {
           if(lista[i].idActor==act[k].idActor)
           {
                for(j=0;j<tamgen;j++)
                {
                    if(lista[i].genero==genero[j].idPelicula)
                    {
                         printf("%2d %25s %5d/%2d/%3d %20s %4s\n",lista[i].idPelicula,lista[i].titulo,lista[i].fechaDeEstreno.dia,lista[i].fechaDeEstreno.mes,lista[i].fechaDeEstreno.anio,act[k].nombre,genero[j].descripcion);

                    }

                }

            }
        }

      }
    }
}

void eActo_Add_ActoresEnPeliculas(eActores actores[],int tam,ePelicula pelicula[],int tamPe)
{
    system("cls");
    eActo_Mostrar_Actores(actores,tam);
    int i,j;
    char valida[400];
    int validacion;
    int validarr;
    if(tam>0)
    {

        for(i=0;i<tamPe;i++)
        {
            if(pelicula[i].estado==LIBRE)
            {
                do
                {
                    printf("Ingrese el id del actor de la pelicula: \n");
                    scanf("%s",valida);
                    validacion=validar_Num(valida);
                    if(validacion==1)
                    {
                        for(j=0;j<tam;j++)
                        {
                           validarr=atoi(valida);
                           if(validarr==actores[j].idActor)
                            {
                                pelicula[i].idActor=validarr;
                                printf("%d",validarr);
                                validacion=1;
                                pelicula[i].estado=OCUPADO;

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
    }

}

int ePeli_modify_Peliculas_act(ePelicula list[],int len,eGenero genero[],int tamGene,eActores actores[],int tamAct)
{
    int i;
    char valida[20];
    int opcion,opcion3,validacion,validarr;
    char opcion2;
    int error =-1;
    if(len>0||list!=NULL||ePeli_BuscarLibre(list,len)==-1)
    {
        ePeli_Mostrar_Peliculas(list,len,genero,tamGene);
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
                            do
                            {
                                system("cls");
                                printf("Ingrese nuevo dia de la pelicula: \n");
                                scanf("%s",valida);
                                validacion=validar_Num(valida);
                                if(validacion==1)
                                {
                                    list[i].fechaDeEstreno.dia=atoi(valida);
                                    break;
                                }
                            }while(validacion==0);
                            do
                            {
                                system("cls");
                                printf("Ingrese nuevo mes de la pelicula: \n");
                                scanf("%s",valida);
                                validacion=validar_Num(valida);
                                if(validacion==1)
                                {
                                    list[i].fechaDeEstreno.mes=atoi(valida);
                                    break;
                                }
                            }while(validacion==0);
                            do
                            {
                                system("cls");
                                printf("Ingrese nuevo año de la pelicula: \n");
                                scanf("%s",valida);
                                validacion=validar_Num(valida);
                                if(validacion==1)
                                {
                                    list[i].fechaDeEstreno.anio=atoi(valida);
                                    break;
                                }
                            }while(validacion==0);
                            break;
                        case 3:
                            do
                            {
                                eActo_Mostrar_Actores(actores,tamAct);
                                printf("Ingrese nuevo actor:\n");
                                scanf("%s",&valida);
                                validacion=validar_Num(valida);
                                validarr=atoi(valida);
                                if(validacion<=5)
                                {
                                    list[i].idActor=validarr;
                                }
                                else
                                {
                                    printf("reingrese correctamente");
                                    validacion=0;
                                }
                            }while(validacion==0);
                    }
                }
            }
        }
    }
    return error;
}
void peliculas_De_Eeuu(ePelicula lista[],int tam,eActores actores[],int tamAct,eGenero genero[],int tamGen)
{
    int i,j,k;
    printf("ID\t               TITULO\t      FECHA\t     ACTOR\t  GENERO\n");
    for(i=0;i<tam;i++)
    {
      if(lista[i].estado==OCUPADO)
      {
        for(k=0;k<tamAct;k++)
        {
           if(lista[i].idActor==actores[k].idActor)
           {
                for(j=0;j<tamGen;j++)
                {
                    if(lista[i].genero==genero[j].idPelicula)
                    {
                        if(strcmp(actores[k].paisOrigen,"EEUU")==0)
                        {
                            printf("%2d %25s %5d/%2d/%3d %20s %4s\n",lista[i].idPelicula,lista[i].titulo,lista[i].fechaDeEstreno.dia,lista[i].fechaDeEstreno.mes,lista[i].fechaDeEstreno.anio,actores[k].nombre,genero[j].descripcion);
                        }

                    }

                }

            }
        }

      }
    }
}

void Peliculas_De_Genero(ePelicula pelicula[],int tamPeli,eGenero genero[],int tamGene)
{
    int i,j;
    for(i=0;i<tamGene;i++)
    {
        printf("%s:\n",genero[i].descripcion);
        for(j=0;j<tamPeli;j++)
        {
            if(pelicula[j].genero==genero[i].idPelicula&&pelicula[j].estado==OCUPADO)
            {
                printf("%20s\n",pelicula[j].titulo);
            }
        }
    }
}
void contarPeliculas(ePelicula peliculas[],int tam,eGenero genero[],int  tamGene)
{
    int i,j;
    int contadorPelis;
    for(i=0;i<tamGene;i++)
    {
        printf("%s\n",genero[i].descripcion);
        contadorPelis=0;
        for(j=0;j<tam;j++)
        {
            if(peliculas[j].genero==genero[i].idPelicula&&peliculas[j].estado==OCUPADO)
            {
                contadorPelis++;
            }
        }
        printf("La cantidad de Peliculas es :%d\n",contadorPelis);
    }
}
/*
int generos_Menor_peliculas(ePelicula peliculas[], int tam,eGenero genero[],int tamGene)
 {
     int i,j;
     int minimo=0;
     int contador;
     int contadores[5];
     for(i=0;i<tamGene;i++)
     {
        contador=0;
        flag=0;
        for(j=0;j<tam;j++)
        {
            if(peliculas[j].estado==OCUPADO)
            {
                if(peliculas[j].genero==genero[i].idPelicula)
                {

                    contador++;
                }
            }
        }
        flag=1;
        if(flag=1)
        {
          contadores[i]=contador;
        }
        if(contadores[i]<minimo)
        {
            minimo=contadores[i];
        }
     }
    return minimo;
}
void imprimirMinimo(ePelicula peliculas[], int tam,eGenero genero[],int tamGene)
{
    int minimo;
    int i;
    for()
}*/
