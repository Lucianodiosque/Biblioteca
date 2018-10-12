#include "Historial-Automoviles.h"

#define VACIO 0
#define OCUPADO 1
#define ELIMINADO -1

void mostrar_historialAutos(eHistorialAutos array[], int tam)
{
    int i;
    printf("ALPHA_ROMEO: ---- FERRARI: ---- AUDI: ---- OTROS:\n");
    for(i=0;i<tam;i++)
    {

        if(array[i].estado==OCUPADO)
        {

            printf("%d ---- %d ---- %d ---- %d\n",array[i].contadorAlpha,array[i].contadorFerrari,array[i].contadorAudi,array[i].contadorOtros);
        }
    }

}
int init_historialAutos(eHistorialAutos array[],int tam)
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
void sumarPocicionesArray(eHistorialAutos array[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        array[i].contadorAlpha=array[i].contadorAlpha+array[i+1].contadorAlpha;
        array[i].contadorFerrari=array[i].contadorFerrari+array[i+1].contadorFerrari;
        array[i].contadorAudi=array[i].contadorAudi+array[i+1].contadorAudi;
        array[i].contadorOtros=array[i].contadorOtros+array[i+1].contadorOtros;
    }
}
