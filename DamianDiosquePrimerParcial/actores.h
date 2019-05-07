#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int idActor;
    char nombre[50];
    char paisOrigen[20];
    int estado;

}eActores;

void eActo_Harcodear_Actores(eActores[],int);
void eActo_Ordenar_Pais_Origen(eActores[],int);
void eActo_Mostrar_Actores(eActores actores[], int tam);
