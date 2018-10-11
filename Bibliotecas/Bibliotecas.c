#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Bibliotecas.h"

#define F_ESTADO_LIBRE 0
#define F_ESTADO_OCUPADO 1

int arrayEPersonaConAltas(EPersona* lista,int cantLista,int valorAlta)
{
    int conAltas=0,i;

    for(i=0;i<cantLista;i++)
        if(lista[i].estado==valorAlta)
        {
            conAltas=1;
            break;
        }

    return conAltas;
}
int burbujeoMejoradoInt(int* nums,int tamArrayNums,int ascend)
{
    int fError=-1,flagSwap,i,auxSwap;

    if(tamArrayNums<1 || (ascend<0 || ascend>1))
        return fError;

    do
    {
        flagSwap=0;

        for(i=0;i<tamArrayNums-1;i++)
        {
            if((ascend==1 && nums[i]>nums[i+1]) || (ascend==0 && nums[i]<nums[i+1]))
            {
                auxSwap=nums[i];
                nums[i]=nums[i+1];
                nums[i+1]=auxSwap;

                flagSwap=1;
            }
        }
        fError=0;
    }while(flagSwap==1);
    return fError;
}
int burbujeoMejoradoEPersonaXNombres(EPersona* array,int tamArrayNums,int ascend)
{
    int fError=-1,flagSwap,i,conAltas=0;//auxIntSwap
    //char auxCharSwap[256];
    EPersona auxEPersona;

    if(tamArrayNums<1 || (ascend<0 || ascend>1))
        return fError;

    do
    {
        flagSwap=0;

        for(i=0;i<tamArrayNums-1;i++)//ver por que menos uno
        {
            if(array[i].estado || array[i+1].estado)
                conAltas=1;

            if((ascend==1 && strcmp(array[i].nombre,array[i+1].nombre)>0 && array[i].estado) || (ascend==0 && strcmp(array[i].nombre,array[i+1].nombre)<0 && array[i].estado))
            {
                auxEPersona=array[i];
                array[i]=array[i+1];
                array[i+1]=auxEPersona;

                flagSwap=1;
            }
        }
        if(conAltas)
            fError=0;
        else
            fError=-2;
    }while(flagSwap==1);
    return fError;
}
int buscarPrimeraOcurrencia(EPersona array[],int cantElementos,int dni)
{
    int i,funcRetorno=-1;
    if(cantElementos>0 && dni>=0)
        {
            for(i=0;i<cantElementos;i++)
            {
                if(array[i].dni==dni)
                {
                      return i;
                }

            }
        }
    return funcRetorno;
}
int buscarLibre(EPersona array[],int cantElementos)
{
    int i,funcRetorno=-1;
    if(cantElementos>0)
    {
        for(i=0;i<cantElementos;i++)
        {
            if(array[i].estado==F_ESTADO_LIBRE)
            {
                return i;
                break;
            }
        }
    }
    return funcRetorno;
}

int matSuma(float op1,float op2,float* resultado)
{
    int flagError=0;

    op1+=op2;
    *resultado=op1;

    return flagError;
}

int matResta(float op1,float op2,float* resultado)
{
    int flagError=0;

    op1-=op2;
    *resultado=op1;

    return flagError;
}

int matMultipl(float op1,float op2,float* resultado)
{
    int flagError=0;

    op1*=op2;
    *resultado=op1;

    return flagError;
}

int matDivision(float op1,float op2,float* resultado)
{
    int flagError=-1;

    if(op2!=0)
    {
        op1/=op2;
        *resultado=op1;
        flagError=0;
    }

    return flagError;
}

int matFactorial(int N,int* resultado)
{
    int i,r=1,flagError=-1;

    if(N>=0)
    {
        for(i=N;i>=1;i--)
            r=r*i;

        *resultado=r;
        flagError=0;
    }

    return flagError;
}
int ordenarArrayIntInsertion(int* array,int cantidad,int ordenAscendente)
{
	int auxiliar,funcRetorno=-1;
    int j, i;

    if(cantidad>0 && (!ordenAscendente || ordenAscendente))
    {
        for(i = 1; i < cantidad; i++)
        {
            auxiliar = array[i];
            j = i;
            while(j > 0 && ((auxiliar < array[j - 1] && ordenAscendente==1) || (auxiliar > array[j - 1] && ordenAscendente==0)))
            {
                array[j] = array[j - 1];
                j--;
            }
            array[j] = auxiliar;
        }
        funcRetorno=0;
    }

    return funcRetorno;
}
int init*****(****** array[],int tam)
{
    int i;
    int error=-1;
    if(array!= NULL || tam<0)
    {
        for(i=0;i<tam;i++)
        {
            array[i].ESTADO=VACIO;
            error=0;
        }
    }
    return error;
}
int idGenerator(***** array[],int len)
{
    int id=1000;//(elegir el numero a generar);
    int i;
    int error=-1;
    for(i=0;i<len;i++)
    {
      if(array[i].ESTADO==OCUPADO)
      {
           array[i].ID=id;
           id=id+1;
           error=0;
      }

    }
    return error;
}
int find********ById(******* * list, int len,int id)
{
    int error=-1;
    int i;
    if(len>0&&list!=NULL&&buscarEspacio(list,len)!=-1)//llama a una funcion que busque espacio(buscar libre)
    {
        for(i=0;i<len;i++)
        {
            if(id==list[i].ID)
            {
                error=list[i].ID;// fijarme si de ultima es al revez
                break;
            }
        }
    }
    return error;
}
int modify*******(******* * list,int len)
{
    int i;
    int opcion;
    int opcion2;
    int error =-1;
    if(len>0||list!=NULL||buscarEspacio(list,len)!=-1)//llama a una funcion que busque espacio libre(buscar libre)
    {
        printf("Ingrese el id del ******* a modificar");
        scanf("%d",&opcion2);
        mostrar(list,len);
        for(i=0;i<len;i++)
        {
            if(opcion2==list[i].id)
            {
                printf("Elija que modificar: \n\n");
                printf("1-******* \n2-*******\n3-******* \n4-*******");
                scanf("%d",&opcion);
                switch(opcion)
                {
                    case 1:
                    printf("ingrese *******\n");
                    scanf("%s",&list[i].name);
                    break;
                case 2:
                    printf("Ingrese *******\n");
                    scanf("%s",&list[i].lastName);
                    break;
                case 3:
                    printf("ingrese *******\n");
                    scanf("%f",&list[i].salary);
                    break;
                case 4:
                    printf("ingrese *******\n");
                    scanf("%d",&list[i].sector);
                    break;
                default:
                    printf("Opcion incorrecta,reingrese");
                    break;
            }
            }
        }


        }
        error=0;
  return error;
}
int remove*******(******* * list, int len, int id)
{
    int i;
    int optionId;
    int encontro=-1;
    mostrar(list,len);//llama a una funcion que muestre el array
    printf("Que id desea eliminar?");
    scanf("%d",&optionId);
    for(i=0;i<len;i++)
    {
        if(list[i].ID == optionId && list[i].ESTADO==OCUPADO)
        {
            list[i].ESTADO=ELIMINADO;
            encontro=1;
            break;
        }
    }
    return encontro;
}

void mostrar(******* list[] , int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].ESTADO==OCUPADO)
        {
            printf("%s %s %d %f %d\n",list[i].name,list[i].lastName,list[i].id,list[i].salary,list[i].sector);//SE MODIFICA
        }

    }

}

******* cargar*******()//ES DEL TIPO ESTRUCTURA *******
{
    ******* *******;
    printf("ingrese *******: ");
    scanf("%d", &*******);
    printf("Ingrese *******: ");
    fflush(stdin);
    gets(*******);
    printf("ingrese*******: ");
    scanf("%f", &*******);
    return *******;
}

int validar_Num(char numero[])
{
    int i=0,sw=0,j;// i variable de control sw error j guarda la cantidad de caracteres
    j=strlen(numero); //j es la cantidad de caracteres
    while(i<j && sw==0)
    {
        if(isdigit(numero[i])!=0)
        {
            i++;
        }
        else
        {
            sw=1;
        }

    }
    return sw;
}

int validar_cadena(char cadena[]) // LO MISMO QUE VALIDAR NUM
{
    int i=0,sw=0,j;
    j=strlen(cadena);
    while(i<j && sw==0)
    {
        if(isalpha(cadena[i])!=0)
        {
            i++;
        }
        else
        {
            sw=1;
        }
    }
    return sw;
}
