#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
   char nombre[50];
   char idPropietario[50];
   char apellido[50];
   char direccion[50];
   char numeroDeTarjeta[50];
   int estado;

}ePropietario;
int init_Propietarios(ePropietario[],int);
int add_Propietarios(ePropietario[],int);
int buscar_propietarioLibre(ePropietario[],int);
void mostrar_propietarios(ePropietario[],int);
void inicializar_PropietariosConHardcode(ePropietario[]);
int remove_Propietario(ePropietario*, int,char[]);
int modify_propietarios(ePropietario*,int );
int burbujeoMejoradoEPersonaXNombres(ePropietario*,int,int);
int validar_Num(char[]);
int validar_cadena(char[]);
