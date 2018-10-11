#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Propietarios.h"
#include "Automoviles.h"

#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1
#define AUTOS 20
int main()
{
    int opcion;
    ePropietario propietarios[AUTOS];
    eAutomovil automoviles[AUTOS];
    int error;
    int error1;
    int error2;
    int error3;
    int error4;
    int error5;
    int optionId;
    error =initPropietarios(propietarios,AUTOS);
    inicializarPropietariosConHardcode(propietarios);
    if(error==0)
    {
        do
        {
            printf("BIENVENIDO A ESTACIONAMIENTO DE VEHICULOS\n\n");
            printf("INGRESE UNA OPCION: \n");
            printf("1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-INGRESO AUTOS\n6-EGRESO AUTOS\n");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    error1= addPropietarios(propietarios,4);
                    getch();
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    error2= modify_propietarios(propietarios,4);
                    if(error2==-1)
                    {
                        printf("Ocurrio un error, no se puede modificar");
                    }
                    getch();
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    mostrar(propietarios,4);
                    printf("Que id desea eliminar?");
                    scanf("%d",&optionId);
                    error3=remove_Propietario(propietarios,4,optionId);
                    if(error3==-1)
                    {
                        printf("Usuario no encontrado o ya se encuentra eliminado");
                    }
                    getch();
                    system("cls");
                    break;
                case 4:
                    error4 =burbujeoMejoradoEPersonaXNombres(propietarios,4,1);
                    mostrar(propietarios,4);
                    getch();
                    system("cls");
                    break;
                case 5:
                   error5=addAutomoviles(automoviles,4);
                default:
                    printf("Ingreso un *************** no valido, reingrese\n");
                    getch();
                    system("cls");
                    break;
            }
        }while(opcion!=5);
    }
    return 0;
}
