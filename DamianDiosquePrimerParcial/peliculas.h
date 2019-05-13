#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "genero.h"

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;


typedef struct
{
    char titulo[30];
    eFecha fechaDeEstreno;
    int genero;
    int idActor;
    int idPelicula;
    int estado;

}ePelicula;

int ePeli_init_Peliculas(ePelicula[],int);
void ePeli_Harcodear_Peliculas(ePelicula[],int,eGenero[],int);
int validar_cadena(char palabra[]);
int validar_Num(char numero[]);
int ePeli_BuscarIdMaximo(ePelicula lista[],int tam);
void ePeli_IdGenerador(ePelicula lista[],int tam,int posicion);
int ePeli_add_Peliculas(ePelicula array[],int tam,eGenero genero[],int tamgene);
void ePeli_Mostrar_Peliculas(ePelicula lista[],int tam,eGenero[],int);
int ePeli_BuscarLibre(ePelicula lista[],int tam);
void ePeli_Ordenar_Peliculas_Por_Anio(ePelicula pelicula[],int tam);
int ePeli_remove_Peliculas(ePelicula list[],int len, char id[]);

