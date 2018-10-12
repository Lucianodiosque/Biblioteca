#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHA_ROMEO
#define FERRARI
#define AUDI
#define OTRO
typedef struct
{
   char idPropietario[50];
   char patente[50];
   char marca[50];
   int estado;
}eAutomovil;

int init_automoviles(eAutomovil[],int);
int add_automoviles(eAutomovil[],int);
void inicializar_automovilesConHardcode(eAutomovil[]);
void mostrar_automoviles(eAutomovil[],int);
int validar_NumAutos(char[]);
int validar_cadenaAutos(char[]);
int devolverHorasEstadia();
int buscar_automovilesLibre(eAutomovil[],int);
void stringToUpper(char caracter[]);
