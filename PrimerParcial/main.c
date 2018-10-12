#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<conio.h>
#include "Propietarios.h"
#include "Automoviles.h"


#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1
#define AUTOS 20
int main()
{
    ePropietario propietarios[AUTOS];
    eAutomovil automoviles[AUTOS];
    int opcion;
    int error;
    int error1;
    int error2;
    int error3;
    int error4;
    int error5;
    int error6;
    int errorInitAutos;
    char optionId[50];
    error =init_Propietarios(propietarios,AUTOS);
    errorInitAutos=init_automoviles(automoviles,AUTOS);
    inicializar_PropietariosConHardcode(propietarios);
    inicializar_automovilesConHardcode(automoviles);
    if(error==0 || errorInitAutos==0)
    {
        do
        {
            printf("BIENVENIDO A ESTACIONAMIENTO DE VEHICULOS\n\n");
            printf("INGRESE UNA OPCION: \n");
            printf("1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-INGRESO AUTOS\n6-EGRESO AUTOS\n7-SALIR\n");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    error1= add_Propietarios(propietarios,AUTOS);
                    if(error1==-1)
                    {
                        printf("No hay mas espacio!");
                    }
                    getch();
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    error2= modify_propietarios(propietarios,AUTOS);
                    if(error2==-1)
                    {
                        printf("Usuario no encontrado");
                    }
                    getch();
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    mostrar_propietarios(propietarios,AUTOS);
                    printf("Que id desea eliminar?");
                    scanf("%s",&optionId);
                    error3=remove_Propietario(propietarios,AUTOS,optionId);
                    if(error3==-1)
                    {
                        printf("Usuario no encontrado o ya se encuentra eliminado");
                    }
                    getch();
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    error4 =burbujeoMejoradoEPersonaXNombres(propietarios,AUTOS,1);
                    if(error4==-1)
                    {
                        printf("No ingreso ningun propietario");
                    }
                    mostrar_propietarios(propietarios,AUTOS);
                    getch();
                    system("cls");
                    break;
                case 5:
                   system("cls");
                   error5=add_automoviles(automoviles,AUTOS);
                   if(error5==-1)
                   {
                       printf("No hay mas espacio!");
                   }
                   getch();
                   system("cls");
                   break;
                case 6:
                     system("cls");
                     error6=calcularHorasDeEstadia(automoviles,AUTOS);
                     if(error6==-1)
                     {
                        printf("Ingreso una patente incorrecta.");
                     }
                     getch();
                     system("cls");
                     break;
                case 7:
                    break;
                default:
                    printf("Ingreso una opcion no valida, reingrese\n");
                    getch();
                    system("cls");
                    break;
            }
        }while(opcion!=7);
    }
    return 0;
}
