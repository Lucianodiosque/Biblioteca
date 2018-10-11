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
   int idPropietario;
   char patente[50];
   char marca[50];
   int estado;
}eAutomovil;

int initAutomoviles(eAutomovil[],int);
int addAutomoviles(eAutomovil[],int);
