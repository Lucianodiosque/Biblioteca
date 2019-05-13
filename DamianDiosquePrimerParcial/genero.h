#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int idPelicula;
    char descripcion[20];
}eGenero;

void harcodearGenero(eGenero genero[],int tam);
void mostrarGeneros(eGenero[],int);
