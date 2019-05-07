#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}


void eGen_IdGenerador(eGenerica lista[],int tam,int posicion)
{
    int maximo;
    maximo=eGen_BuscarIdMaximo(lista,tam);
    maximo=maximo+100;
    lista[posicion].id=maximo;

}
int eGen_BuscarUltimaPosicionArray(eGenerica lista[],int tam)
{
    int i;
    int index=-1;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            index=i;
        }
    }
    return index;
}

int eGen_BuscarLibre(eGenerica lista[],int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
int eGen_BuscarIdMaximo(eGenerica lista[],int tam)
{
    int i;
    int index=-1;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            index=lista[i].id;
        }
    }
    return index;

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

int remove_Propietario(ePropietario* list, int len, char id[])
{
    int i;
    int encontro=-1;
    char opcion;
    for(i=0;i<len;i++)
    {
        if(strcmp(list[i].idPropietario,id)==0 && list[i].estado==OCUPADO)
        {
            printf("Esta seguro que desea eliminar el propietario?(s/n)\n");
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


int modify_propietarios(ePropietario * list,int len)
{
    int i;
    char opcion[50];
    char opcion2;
    int error =-1;
    if(len>0||list!=NULL||buscar_propietarioLibre(list,len)==-1) // fijarse si anda ese buscar libre
    {
        mostrar_propietarios(list,len);
        printf("Ingrese el id del propietario a modificar:\n");
        scanf("%s",&opcion);
        for(i=0;i<len;i++)
        {
          if(strcmp(opcion,list[i].idPropietario)==0)
            {
                printf("Esta seguro que desea modificar ese id?(s/n)\n");
                scanf("%s",&opcion2);
                if(opcion2=='s')
                {
                    printf("Ingrese Nuevo numero de tarjeta:\n");
                    scanf("%s",&list[i].numeroDeTarjeta);
                    error=0;
                }
            }
        }
    }
    return error;
}


int add_Propietarios(eGenerica array[],int tam)
{
    int i,funcRetorno=-1;
    char opcion='s';
    char valida[295];
    int validacion;
    if(tam>0)
    {
      while(opcion=='s')
      {
        for(i=0;i<tam;i++)
        {
          if(array[i].estado==VACIO)
          {
            do
            {
                system("cls");
                printf("Ingrese id del propietario: \n");
                scanf("%s",valida);
                validacion=validar_Num(valida);
                if(validacion==1)
                {
                    generica[i].id=atoi(valida);
                    break;
                }
            }while(validacion==0);

             /*
             printf("Ingrese Nombre del propietario: \n");
             scanf("%s",&array[i].nombre);
             validacion=validar_cadena(array[i].nombre);
             while(validacion==0)
             {
                system("cls");
                printf("Ingrese nombre del propietario: \n");
                scanf("%s",&array[i].nombre);
                validacion=validar_cadena(array[i].nombre);
             }
             printf("Ingrese Apellido del propietario: \n");
             scanf("%s",&array[i].apellido);
             validacion=validar_cadena(array[i].apellido);
             while(validacion==0)
             {
                system("cls");
                printf("Ingrese apellido del propietario: \n");
                scanf("%s",&array[i].apellido);
                validacion=validar_cadena(array[i].apellido);
             }
             printf("Ingrese Direccion del propietario: \n");
             scanf("%s",&array[i].direccion);
             printf("Ingrese numero de tarjeta del propietario: \n");
             scanf("%s",&array[i].numeroDeTarjeta);
             validacion=validar_Num(array[i].numeroDeTarjeta);
             while(validacion==0)int validar_Num(char numero[])
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

int remove_Propietario(ePropietario* list, int len, char id[])
{
    int i;
    int encontro=-1;
    char opcion;
    for(i=0;i<len;i++)
    {
        if(strcmp(list[i].idPropietario,id)==0 && list[i].estado==OCUPADO)
        {
            printf("Esta seguro que desea eliminar el propietario?(s/n)\n");
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


int modify_propietarios(ePropietario * list,int len)
{
    int i;
    char opcion[50];
    char opcion2;
    int error =-1;
    if(len>0||list!=NULL||buscar_propietarioLibre(list,len)==-1)
    {
        mostrar_propietarios(list,len);
        printf("Ingrese el id del propietario a modificar:\n");
        scanf("%s",&opcion);
        for(i=0;i<len;i++)
        {
          if(strcmp(opcion,list[i].idPropietario)==0)
            {
                printf("Esta seguro que desea modificar ese id?(s/n)\n");
                scanf("%s",&opcion2);
                if(opcion2=='s')
                {
                    printf("Ingrese Nuevo numero de tarjeta:\n");
                    scanf("%s",&list[i].numeroDeTarjeta);
                    error=0;
                }
            }
        }
    }
    return error;
}


int add_Propietarios(eGenerica array[],int tam)
{
    int i,funcRetorno=-1;
    char opcion='s';
    char valida[295];
    int validacion;
    if(tam>0)
    {
      while(opcion=='s')
      {
        for(i=0;i<tam;i++)
        {
          if(array[i].estado==VACIO)
          {
            do
            {
                system("cls");
                printf("Ingrese id del propietario: \n");
                scanf("%s",valida);
                validacion=validar_Num(valida);
                if(validacion==1)
                {
                    generica[i].id=atoi(valida);
                    break;
                }
            }while(validacion==0);

             /*
             printf("Ingrese Nombre del propietario: \n");
             scanf("%s",&array[i].nombre);
             validacion=validar_cadena(array[i].nombre);
             while(validacion==0)
             {
                system("cls");
                printf("Ingrese nombre del propietario: \n");
                scanf("%s",&array[i].nombre);
                validacion=validar_cadena(array[i].nombre);
             }
             printf("Ingrese Apellido del propietario: \n");
             scanf("%s",&array[i].apellido);
             validacion=validar_cadena(array[i].apellido);
             while(validacion==0)
             {
                system("cls");
                printf("Ingrese apellido del propietario: \n");
                scanf("%s",&array[i].apellido);
                validacion=validar_cadena(array[i].apellido);
             }
             printf("Ingrese Direccion del propietario: \n");
             scanf("%s",&array[i].direccion);
             printf("Ingrese numero de tarjeta del propietario: \n");
             scanf("%s",&array[i].numeroDeTarjeta);
             validacion=validar_Num(array[i].numeroDeTarjeta);
             while(validacion==0)
             {
                system("cls");
                printf("Ingrese numero de tarjeta del propietario: \n");
                scanf("%s",&array[i].numeroDeTarjeta);
                validacion=validar_Num(array[i].numeroDeTarjeta);
             }
             array[i].estado=OCUPADO;
             fflush(stdin);
             printf("Desea ingresar un usuario? (s/n)");
             scanf("%s",&opcion);*/
             if(opcion=='n')
             {
                break;
             }
          }
        }
    funcRetorno=0;
    }
    return funcRetorno;
  }
}



int init_Propietarios(ePropietario array[],int tam)
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
             {
                system("cls");
                printf("Ingrese numero de tarjeta del propietario: \n");
                scanf("%s",&array[i].numeroDeTarjeta);
                validacion=validar_Num(array[i].numeroDeTarjeta);
             }
             array[i].estado=OCUPADO;
             fflush(stdin);
             printf("Desea ingresar un usuario? (s/n)");
             scanf("%s",&opcion);*/
             if(opcion=='n')
             {
                break;
             }
          }
        }
    funcRetorno=0;
    }
    return funcRetorno;
  }
}



int init_Propietarios(ePropietario array[],int tam)
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

void mostrar_propietarios(ePropietario list[] , int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].estado==OCUPADO)
        {
            printf("%s --- %s --- %s --- %s --- %s\n",list[i].idPropietario,list[i].nombre,list[i].apellido,list[i].direccion,list[i].numeroDeTarjeta);
        }

    }

}
/*
int burbujeoMejoradoEPersonaXNombres(ePropietario* array,int tamArrayNums,int ascend)
{
    int fError=-1,flagSwap,i,conAltas=0;
    ePropietario auxEPropietario;

    if(tamArrayNums<1 || (ascend<0 || ascend>1))
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
}*///POR LAS DUDAS
