#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define QTY_PERSONAS 10
#define F_ESTADO_LIBRE 0
#define F_ESTADO_OCUPADO 1
//MENU GENERICO :3
int main()
{
    int opcion;
    //iniciar las variables
    //iniciar los arrays
    do
    {
        printf("BIENVENIDO A ***************\n\n");
        printf("INGRESE UNA OPCION: \n");
        printf("1-******\n2-********\n3-******\n4-********\n5-******\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                system("cls");
                system("cls");
                getch();
                break;
            case 2:
                system("cls");
                system("cls");
                getch();
                break;
            case 3:
                system("cls");
                system("cls");
                getch();
                break;
            case 4:
                system("cls");
                system("cls");
                getch();
                break;
            case 5:
                system("cls");
                system("cls");
                getch();
                break;
            default:
                printf("Ingreso un *************** no valido, reingrese");
                break;
        }
    }while(opcion!=****);
}
