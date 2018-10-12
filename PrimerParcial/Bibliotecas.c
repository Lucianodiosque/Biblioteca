#include "Bibliotecas.h"


int buscarLibre(char array[],int tam)
{
    int i,funcRetorno=-1;
    if(tam>0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].estado==VACIO)
            {
               funcRetorno=i;
                break;
            }
        }
    }
    return funcRetorno;
}
int burbujeoMejoradoEPersonaXNombres(ePropietario* array,int tamArrayNums,int ascend)
{
    int fError=-1,flagSwap,i,conAltas=0;
    ePropietario auxEPropietario;

    if(tamArrayNums<1 || (ascend<0 || ascend>1))
    {
        return fError;
    }
    do
    {
        flagSwap=0;
        for(i=0;i<tamArrayNums-1;i++)//ver por que menos uno
        {
            if(array[i].estado==OCUPADO || array[i+1].estado==OCUPADO)
            {
                conAltas=1;
            }
            if((ascend==1 && strcmp(array[i].nombre,array[i+1].nombre)>0 && array[i].estado==OCUPADO) || (ascend==0 && strcmp(array[i].nombre,array[i+1].nombre)<0 && array[i].estado==OCUPADO))
            {
                auxEPropietario=array[i];
                array[i]=array[i+1];
                array[i+1]=auxEPropietario;

                flagSwap=1;
            }
          /*  if((acend==1 && strcmp(array[i].nombre,array[i+1].nombre)=0)&& array[i].estado==OCUPADO)
            {
                auxIguales=array[i];

            }*/
        }
        if(conAltas=1)
        {
            fError=0;
        }
        else
        {
           fError=-1;
        }
    }while(flagSwap==1);
    return fError;
}

int validar_Num(char numero[])
{
  int i;
  int error=1;
  for(i=0;i<strlen(numero);i++)
  {
      if(!(isdigit(numero[i])))
      {
          printf("INCORRECTO:INGRESE SOLO NUMEROS!\n");
          getch();
          error=0;
          break;
      }
  }
  return error;
}
int validar_cadena(char palabra[]) // LO MISMO QUE VALIDAR NUM
{
    int i;
    int error=1;
    for(i=0;i<strlen(palabra);i++)
    {
        if(!(isalpha(palabra[i])))
        {
            printf("INCORRECTO: INGRESE SOLO LETRAS!\n");
            getch();
            error=0;
            break;
        }
    }
    return error;
}
