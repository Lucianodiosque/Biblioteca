#include "genero.h"


void harcodearGenero(eGenero genero[],int tam)
{
    int i;

    int idGenero[]={1,2,3,4,5};
    char nombre[][40]={"Accion","Comedia","Drama","Romance","Terror"};

    for(i=0;i<tam;i++)
    {
        genero[i].idPelicula=idGenero[i];
        strcpy(genero[i].descripcion,nombre[i]);
    }
}

void mostrarGeneros(eGenero genero[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
       printf("%d ---%s\n",genero[i].idPelicula,genero[i].descripcion);
    }
}

