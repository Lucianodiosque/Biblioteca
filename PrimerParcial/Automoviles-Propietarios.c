#include "Automoviles-Propietarios.h"

void mostrarPropietarioYSusAutos(eAutomovil arrayAuto[],int tamAuto,ePropietario arrayPropie[],int tamPropie)
{
    int i,j;
    char opcion[50];
    mostrar_propietarios(arrayPropie,tamPropie);
    printf("De que propietario quiere ver los datos(ingrese id)?: \n");
    scanf("%s",&opcion);
    if(strcmp(opcion,arrayPropie[i].idPropietario)==0)
    {
        for(i=0;i<tamPropie;i++)
        {
            printf("%s",arrayPropie[i].nombre);
            for(j=0;j<tamAuto;j++)
            {
                if(strcmp(arrayPropie[i].idPropietario,arrayAuto[i].idPropietario)==0)
                {
                    printf("%s %s\n",arrayAuto[i].patente,arrayAuto[i].marca);
                }
            }
        }
    }


}

