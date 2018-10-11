#include "Propietarios.h"
#define VACIO 0
#define OCUPADO 1
#define ELIMINADO -1
int initPropietarios(ePropietario array[],int tam)
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

int addPropietarios(ePropietario array[],int tam)
{
    int i,funcRetorno=-1;
    char opcion;

    if(tam>0)
    {

        for(i=0;i<tam;i++)
        {
            printf("Desea ingresar un usuario? (s/n)");
            scanf("%s",&opcion);
            if(opcion=='s')
            {
                printf("Ingrese id del propietario: \n");
                scanf("%d",&array[i].idPropietario);
                printf("Ingrese Nombre del propietario: \n");
                scanf("%s",&array[i].nombre);
                printf("Ingrese Apellido del propietario: \n");
                scanf("%s",&array[i].apellido);
                printf("Ingrese Direccion del propietario: \n");
                scanf("%s",&array[i].direccion);
                printf("Ingrese numero de tarjeta del propietario: \n");
                scanf("%d",&array[i].numeroDeTarjeta);
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
int modify_propietarios(ePropietario * list,int len)
{
    int i;
    int opcion;
    char opcion2;
    int error =-1;
    if(len>0||list!=NULL||buscarLibre(list,len)!=-1)
    {
        mostrar(list,len);
        printf("Ingrese el id del propietario a modificar:\n");
        scanf("%d",&opcion);
        for(i=0;i<len;i++)
        {
            if(opcion==list[i].idPropietario)
            {
                printf("Esta seguro que desea modificar ese id?(s/n)\n");
                scanf("%s",&opcion2);
                if(opcion2=='s')
                {
                    printf("Ingrese Nuevo numero de tarjeta:\n");
                    scanf("%d",&list[i].numeroDeTarjeta);
                }
            }
        }

    error=0;
    }
    return error;
}


int buscarLibre(ePropietario array[],int tam)
{
    int i,funcRetorno=-1;
    if(tam>0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].estado==VACIO)
            {
                return i;
                break;
            }
        }
    }
    return funcRetorno;
}
void mostrar(ePropietario list[] , int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].estado==OCUPADO)
        {
            printf("%d %s %s %s %d\n",list[i].idPropietario,list[i].nombre,list[i].apellido,list[i].direccion,list[i].numeroDeTarjeta);
        }

    }

}
int remove_Propietario(ePropietario* list, int len, int id)
{
    int i;
    int encontro=-1;
    char opcion;
    for(i=0;i<len;i++)
    {
        if(list[i].idPropietario== id && list[i].estado==OCUPADO)
        {
            printf("Esta seguro que desea eliminar el propietario?(s/n)");
            scanf("%s",&opcion);
            if(opcion=='s')
            {
                list[i].estado=ELIMINADO;
                encontro=1;
            }

            break;
        }
    }
    return encontro;
}
void inicializarPropietariosConHardcode(ePropietario array[])
{
    int id[4]={1000,1001,1002,1003};
    char nombre[][50]={"Juan","Maria","Pedro","Vanesa"};
    char apellido[][50]={"Burgos","Lopez","Ricci","Nievas"};
    char direccion[][50]={"Calle falsa 123","roca 192","`Peru 854","Lima 33"};
    int numeroDeTarjeta[4]={9102,8264,7821,6134};

    int i;
    for(i=0;i<4;i++)
    {
        array[i].idPropietario=id[i];
        array[i].numeroDeTarjeta=numeroDeTarjeta[i];
        strcpy(array[i].nombre, nombre[i]);
        strcpy(array[i].apellido, apellido[i]);
        strcpy(array[i].direccion, direccion[i]);
        array[i].estado=OCUPADO;
    }

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
