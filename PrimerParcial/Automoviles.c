#include "Automoviles.h"

#define ALPHA_ROMEO
#define FERRARI
#define AUDI
#define OTRO
#define VACIO 0
#define OCUPADO 1
#define ELIMINADO -1
int initAutomoviles(eAutomovil array[],int tam)
{
    int i;
    int error=-1;
    if(array!= NULL || tam<0)
    {
        for(i=0;i<tam;i++)
        {
            array[i].estado=VACIO;
            error=0;
        }
    }
    return error;
}
int addAutomoviles(eAutomovil array[],int tam)
{
    int i,funcRetorno=-1;
    char opcion;

    if(tam>0)
    {
        for(i=0;i<tam;i++)
        {
            printf("Desea ingresar un automovil? (s/n)");
            scanf("%s",&opcion);
            if(opcion=='s')
            {
                printf("Ingrese id del propietario: \n");
                scanf("%d",&array[i].idPropietario);
                printf("Ingrese Patente del automovil: \n");
                scanf("%s",&array[i].patente);
                printf("Ingrese marca del automovil: \n");
                scanf("%d",&array[i].marca);
                array[i].estado=OCUPADO;
            }
            else
            {
                break;
            }

        }
    funcRetorno=0;
    }

    return funcRetorno;
}
