#include "actores.h"
#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1

void eActo_Harcodear_Actores(eActores actor[],int tam)
{
    int i;

    int idActor[]={1,2,3,4,5,6,7,8,9,10};
    char nombre[][40]={"Scarlett Johansson","Robert  Downey Jr","Mark Ruffalo","Chris Evans","Chris Hemsworth","Samuel Jackson","Gwyneth Paltrow","Paul Rudd","Bradley Cooper","Josh Brolin"};
    char paisOrigen[][20]={"Argentina","EEUU","Canada","EEUU","Argentina","EEUU","Canada","Argentina","EEUU","Canada"};

    for(i=0;i<tam;i++)
    {
        actor[i].idActor=idActor[i];
        strcpy(actor[i].nombre,nombre[i]);
        strcpy(actor[i].paisOrigen,paisOrigen[i]);
        actor[i].estado=OCUPADO;
    }

}

void eActo_Ordenar_Pais_Origen(eActores actores[],int tam)
{
    int i,j;
    eActores aux;
    for(i=0;i<tam;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(actores[i].paisOrigen,actores[j].paisOrigen)>0)
            {
                aux=actores[i];
                actores[i]=actores[j];
                actores[j]=aux;
            }
        }
    }
}

void eActo_Mostrar_Actores(eActores actores[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(actores[i].estado==OCUPADO)
        {
            printf("%d --- %s --- %s\n",actores[i].idActor,actores[i].nombre,actores[i].paisOrigen);
        }
    }

}
