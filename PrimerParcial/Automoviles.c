#include "Automoviles.h"

int init_automoviles(eAutomovil array[],int tam)
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
int add_automoviles(eAutomovil array[],int tam)
{
    int i,funcRetorno=-1,opcion2;
    char opcion='s';
    int validacion;
    if(tam>0)
    {
      while(opcion=='s')
      {
        for(i=0;i<tam;i++)
        {
          if(array[i].estado==VACIO)
          {
             system("cls");
             printf("Ingrese id del propietario: \n");
             scanf("%s",&array[i].idPropietario);
             validacion=validar_Num(array[i].idPropietario);
             while(validacion==0)
             {
               system("cls");
               printf("Ingrese Id del propietario: \n");
               scanf("%s",&array[i].idPropietario);
               validacion=validar_Num(array[i].idPropietario);
             }
             printf("Ingrese Patente del propietario: \n");
             scanf("%s",&array[i].patente);
             strupr(array[i].patente);
             printf("Ingrese Marca del propietario: \n");
             printf("1-ALPHA_ROMEO\n2-FERRARI\n3-AUDI\n4-OTROS\n5-SALIR\n");
             scanf("%d",&opcion2);
             do{
             switch(opcion2)
             {
                case 1:
                    strcpy(array[i].marca,"ALPHA_ROMEO");
                    break;
                case 2:
                    strcpy(array[i].marca,"FERRARI");
                    break;
                case 3:
                    strcpy(array[i].marca,"AUDI");
                    validacion=validar_cadena(array[i].marca);
                    break;
                case 4:
                    strcpy(array[i].marca,"OTROS");
                    break;
                case 5:
                    break;
                default:
                    printf("Ingreso una opcion incorrecta reingrese");
                    break;
             }
             }while(opcion=='5');
             array[i].estado=OCUPADO;
             fflush(stdin);
             printf("Desea ingresar un usuario? (s/n)");
             scanf("%s",&opcion);
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
void inicializar_automovilesConHardcode(eAutomovil array[])
{
    char id[][50]={"1000","1001","1002","1003"};
    char marca[][50]={"ALPHA_ROMEO","FERRARI","AUDI","ALPHA_ROMEO"};
    char patente[][50]={"MTA087","BTA236","PPE876","AUD979"};

    int i;
    for(i=0;i<4;i++)
    {
        strcpy(array[i].idPropietario,id[i]);
        strcpy(array[i].patente, patente[i]);
        strcpy(array[i].marca, marca[i]);
        array[i].estado=OCUPADO;
    }
}
void mostrar_automoviles(eAutomovil list[] , int len)
{
    int i;
    printf("ID PROPIETARIO: ---- MARCA: ----- PATENTE:\n");
    for(i=0;i<len;i++)
    {
        if(list[i].estado==OCUPADO)
        {
            printf("%s ---- %s ----- %s\n",list[i].idPropietario,list[i].marca,list[i].patente);
        }

    }

}

int validar_NumAutos(char numero[])
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
int validar_cadenaAutos(char palabra[]) // LO MISMO QUE VALIDAR NUM
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
int buscar_automovilesLibre(eAutomovil array[],int tam)
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

int calcularHorasDeEstadia(eAutomovil array[],int tam,eHistorialAutos list[],int tamHist)
{
    int i;
    int j;
    char opcion2;
    char opcion[50];
    int horas;
    int acumuladorAudi=0;
    int acumuladorAlpha=0;
    int acumuladorFerrari=0;
    int acumuladorOtros=0;
    int dinero=0;
    char aux[4][50];
    int*  flag;
    if(tam>0||array!=NULL||buscar_automovilesLibre(array,tam)==-1)
    {
        mostrar_automoviles(array,tam);
        printf("Ingrese la patente del auto que egresa:\n");
        scanf("%s",&opcion);
        strupr(opcion);
        for(i=0;i<tam;i++)
        {
            if(strcmp(opcion,array[i].patente)==0)
            {
               printf("Esta seguro que el auto egresa?(s/n)\n");
               scanf("%s",&opcion2);
               switch(opcion2)
               {
               case 's':
                    if(strcmp(array[i].marca,"ALPHA_ROMEO")==0)
                    {
                      //  sumarPocicionesArray(list,tamHist);
                        horas=devolverHorasEstadia();
                        dinero=150*horas;
                        acumuladorAlpha=dinero+acumuladorAlpha;
                        list[i].contadorAlpha=acumuladorAlpha;
                        acumuladorAlpha=list[i].contadorAlpha;
                        list[i].estado=OCUPADO;

                        printf("ID PROPIETARIO: ---- PATENTE: ---- MARCA: ---- VALOR DE LA ESTADIA:\n\n");
                        printf("%s ---- %s ---- %s ---- %d\n",array[i].idPropietario,array[i].patente,array[i].marca,dinero);

                    }
                    else if(strcmp(array[i].marca,"FERRARI")==0)
                    {
                        horas=devolverHorasEstadia();
                        dinero=horas*175;
                        acumuladorFerrari=dinero+acumuladorFerrari;
                        list[i].contadorFerrari=acumuladorFerrari;
                           list[i].estado=OCUPADO;
                        printf("ID PROPIETARIO: ---- PATENTE: ---- MARCA: ---- VALOR DE LA ESTADIA:\n\n");
                        printf("%s ---- %s ---- %s ---- %d\n",array[i].idPropietario,array[i].patente,array[i].marca,dinero);
                    }
                    else if(strcmp(array[i].marca,"AUDI")==0)
                    {
                        horas=devolverHorasEstadia();
                        dinero=horas*200;
                        acumuladorAudi=dinero+acumuladorAudi;
                        list[i].contadorAudi=acumuladorAudi;
                        list[i].estado=OCUPADO;
                        printf("ID PROPIETARIO: ---- PATENTE: ---- MARCA: ---- VALOR DE LA ESTADIA:\n\n");
                        printf("%s ---- %s ---- %s ---- %d\n",array[i].idPropietario,array[i].patente,array[i].marca,dinero);
                    }
                    else
                    {
                        horas=devolverHorasEstadia();
                        dinero=horas*250;
                        acumuladorOtros=acumuladorOtros+dinero;
                        list[i].contadorOtros=acumuladorOtros;
                        list[i].estado=OCUPADO;
                        printf("ID PROPIETARIO: ---- PATENTE: ---- MARCA: ---- VALOR DE LA ESTADIA:\n\n");
                        printf("%s ---- %s ---- %s ---- %d\n",array[i].idPropietario,array[i].patente,array[i].marca,dinero);
                    }
                    break;
               case 'n':
                    break;
              default:
                    printf("Ingrese opcion correcta");
                    break;

                    }
                array[i].estado=ELIMINADO;

            }

        }
    }
    return dinero;
}
int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}


