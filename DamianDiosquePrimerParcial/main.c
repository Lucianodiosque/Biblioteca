#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "actores.h"
#include "peliculas.h"
#define PELIS 30
#define ACTORES 20
#define GENEROS 5
int main()
{
    int opcion,opcion2;
    char opcion3;
    ePelicula  peliculas[PELIS];
    eActores actores[ACTORES];
    ePeli_init_Peliculas(peliculas,PELIS);
    eGenero generos[GENEROS];
    ePeli_Harcodear_Peliculas(peliculas,21,generos,5);
    eActo_Harcodear_Actores(actores,10);
    harcodearGenero(generos,5);
    int idOpcion;
        do
        {
            printf("BIENVENIDO A \n\n");
            printf("INGRESE UNA OPCION: \n");
            printf("1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-Mostrar Actores\n6-Mostrar Peliculas\n7-Informes\n10-Salir\n");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    getch();
                    system("cls");
                    ePeli_add_Peliculas(peliculas,PELIS,generos,GENEROS);
                    eActo_Add_ActoresEnPeliculas(actores,ACTORES,peliculas,PELIS);
                    break;
                case 2:
                    getch();
                    system("cls");
                    ePeli_modify_Peliculas_act(peliculas,PELIS,generos,GENEROS,actores,ACTORES);
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    getch();
                    ePeli_Mostrar_Peliculas(peliculas,PELIS,generos,GENEROS);
                    printf("Ingrese id de pelicula a eliminar\n");
                    scanf("%d",&idOpcion);
                    ePeli_remove_Peliculas(peliculas,PELIS,idOpcion);
                    system("cls");
                    break;
                case 4:
                    printf("Ingrese opcion: \n");
                    printf("1-Ordenar peliculas por anio\n2-Ordenar actores por origen\n");
                    scanf("%d",&opcion2);
                    switch(opcion2)
                    {
                        case 1:
                            ePeli_Ordenar_Peliculas_Por_Anio(peliculas,PELIS);
                            break;
                        case 2:
                            eActo_Ordenar_Pais_Origen(actores,ACTORES);
                            break;
                        default:
                            printf("ingrese opcion correcta!");
                            break;
                    }
                    system("cls");
                    break;
                case 5:
                     system("cls");
                    eActo_Mostrar_Actores(actores,ACTORES);
                    break;
                case 6:
                     system("cls");
                     ePeli_Mostrar_Peliculas(peliculas,PELIS,generos,GENEROS);
                     break;
                case 7:
                    printf("A-Mostrar Peliculas con genero y actor\nB-Peliculas cuya nacionalidad del actor sea EEUU\nC-Por genero titulo de las peliculas\nD-Por genero cantidad de peliculas\nE-Genero/s con menos peliculas\n");
                    fflush(stdin);
                    scanf("%c",&opcion3);
                    opcion3=toupper(opcion3);
                    switch(opcion3)
                    {
                        case 'A':
                            system("cls");
                            eMostrar(peliculas,PELIS,actores,ACTORES,generos,GENEROS);
                            getch();
                            break;
                        case 'B':
                            system("cls");
                            peliculas_De_Eeuu(peliculas,PELIS,actores,ACTORES,generos,GENEROS);
                            getch();
                            break;
                        case 'C':
                            system("cls");
                            Peliculas_De_Genero(peliculas,PELIS,generos,GENEROS);
                            getch();
                            break;
                        case 'D':
                            system("cls");
                            contarPeliculas(peliculas,PELIS,generos,GENEROS);
                            getch();
                            break;
                        default:
                            system("cls");
                            printf("INGRESO UNA OPCION INVALIDA, REINGRESE!!\n");
                            break;
                    }

                    break;
                case 10:
                    break;
                default:
                    printf("Ingreso una opcion no valida, reingrese\n");
                    getch();
                    system("cls");
                    break;
            }
        }while(opcion!=10);
  return 0;
}


