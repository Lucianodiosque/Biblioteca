#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
   int idPropietario;
   char nombre[50];
   char apellido[50];
   char direccion[50];
   int numeroDeTarjeta;
   int estado;

}ePropietario;
int initPropietarios(ePropietario[],int);
int addPropietarios(ePropietario[],int);
int buscarLibre(ePropietario[],int);
void mostrar(ePropietario[],int);
void inicializarPropietariosConHardcode(ePropietario[]);
int remove_Propietario(ePropietario*, int,int);
int modify_propietarios(ePropietario*,int );
int burbujeoMejoradoEPersonaXNombres(ePropietario*,int,int);
