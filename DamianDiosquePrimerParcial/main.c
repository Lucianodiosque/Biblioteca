#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "actores.h"
#include "peliculas.h"
#define PELIS 10
#define ACTORES 10
int main()
{
    int opcion,opcion2;
    ePelicula  peliculas[PELIS];
    eActores actores[ACTORES];
    ePeli_init_Peliculas(peliculas,PELIS);
    ePeli_Harcodear_Peliculas(peliculas,4);
    eActo_Harcodear_Actores(actores,5);
    int idOpcion;
        do
        {
            printf("BIENVENIDO A \n\n");
            printf("INGRESE UNA OPCION: \n");
            printf("1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-Mostrar Actores\n6-Mostrar Peliculas\n10-Salir\n");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    getch();
                    system("cls");
                    ePeli_add_Peliculas(peliculas,PELIS);
                    break;
                case 2:
                    getch();
                    system("cls");
                    ePeli_modify_Peliculas(peliculas,PELIS);
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    getch();
                    ePeli_Mostrar_Peliculas(peliculas,PELIS);
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
                     ePeli_Mostrar_Peliculas(peliculas,PELIS);
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


