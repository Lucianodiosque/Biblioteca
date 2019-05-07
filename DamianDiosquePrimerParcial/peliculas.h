#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    char generos[20];

}eGenero;

typedef struct
{
    char titulo[30];
    eFecha fechaDeEstreno;
    eGenero genero;
    int idActor;
    int idPelicula;
    int estado;

}ePelicula;

int ePeli_init_Peliculas(ePelicula[],int);
void ePeli_Harcodear_Peliculas(ePelicula[],int);
int validar_cadena(char palabra[]);
int validar_Num(char numero[]);
int ePeli_BuscarIdMaximo(ePelicula lista[],int tam);
void ePeli_IdGenerador(ePelicula lista[],int tam,int posicion);
int ePeli_add_Peliculas(ePelicula array[],int tam);
void ePeli_Mostrar_Peliculas(ePelicula lista[],int tam);
int ePeli_BuscarLibre(ePelicula lista[],int tam);
int ePeli_modify_Peliculas(ePelicula list[],int len);
//void mostrarPelisyActores(ePelicula[],int,e)
void ePeli_Ordenar_Peliculas_Por_Anio(ePelicula pelicula[],int tam);
int ePeli_remove_Peliculas(ePelicula list[],int len, char id[]);
