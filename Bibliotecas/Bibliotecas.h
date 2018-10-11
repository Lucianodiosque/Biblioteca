#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {

    char nombre[50];
    int edad;
    int estado; //Tomamos flag en 0-Libre,1-Ocupado.
    int dni;

}EPersona;


/** \brief Comprueba si un array tipo EPersona tiene al menos un alta.
 *
 * \param lista EPersona* Array de datos tipo EPersona.
 * \param cantLista int Cantidad de elementos del array.
 * \param valorAlta int Recibe que valor numerico se toma como elemento ocupado(Alta) dentro del array a analizar.
 * \return int 0 Array vacio,1 Array con altas.
 *
 */
int arrayEPersonaConAltas(EPersona* lista,int cantLista,int valorAlta);

/** \brief Ordena un array de numeros enteros, por metodo de burbujeo optimizado.
 *
 * \param nums int* Array de numeros enteros a ordenar.
 * \param tamArrayNums int Cantidad de elementos del array de enteros recibido.
 * \param ascend int 0-Ordenamiento ascendente,1-Ordenamiento descendente.
 * \return int 0-OK,-1-Error.
 *
 */
int burbujeoMejoradoInt(int* nums,int tamArrayNums,int ascend);

/** \brief Ordenamiento por nombre de datos tipo EPersona mediante metodo de la burbuja.
 *
 * \param array EPersona* Array de datos tipo EPersona.
 * \param tamArrayNums int Cantidad de elementos del array.
 * \param ascend int Criterio de ordenamiento: 0 Descendente(cba),1 Ascendente.(abc)
 * \return int -1 Error,0 OK.
 *
 */
int burbujeoMejoradoEPersonaXNombres(EPersona* array,int tamArrayNums,int ascend);

/** \brief Busca un valor dentro de un array, devolviendo en que indice se encuentra.
 *
 * \param array[] int Array de elementos de tipo entero.
 * \param cantElementos int Cantidad de elementos del array.
 * \param valor int Valor a buscar.
 * \return int Retorna el elemento en el que se encuentra el valor buscado. Si retorna -1 no se encontro el valor.
 *
 */
int buscarPrimeraOcurrencia(EPersona array[],int cantElementos,int dni);

/** \brief Busca el primer lugar libre del array tipo EPersona.
 *
 * \param array[] EPersona Array de tipo EPersona.
 * \param cantElementos int Cantidad de elementos del array.
 * \return int -1 Error,<id> del elemento disponible del array.
 *
 */
int buscarLibre(EPersona array[],int cantElementos);

/** \brief Calcula la suma entre dos numeros.
 *
 * \param op1 float Operando 1.
 * \param op2 float Operando 2.
 * \param resultado float* Puntero a flotante en donde se devuelve el resultado de la operacion.
 * \return int Codigo de errores: 0-OK, <distinto cero>-Error.
 *
 */
int matSuma(float op1,float op2,float* resultado);

/** \brief Calcula la resta entre dos numeros.
 *
 * \param op1 float Operando 1.
 * \param op2 float Operando 2.
 * \param resultado float* Puntero a flotante en donde se devuelve el resultado de la operacion.
 * \return int Codigo de errores: 0-OK, <distinto cero>-Error.
 *
 */
int matResta(float op1,float op2,float* resultado);

/** \brief Calcula el producto entre dos numeros.
 *
 * \param op1 float Operando 1.
 * \param op2 float Operando 2.
 * \param resultado float* Puntero a flotante en donde se devuelve el resultado de la operacion.
 * \return int Codigo de errores: 0-OK, <distinto cero>-Error.
 *
 */
int matMultipl(float op1,float op2,float* resultado);

/** \brief Calcula el cociente entre dos numeros.
 *
 * \param op1 float Operando 1.
 * \param op2 float Operando 2.
 * \param resultado float* Puntero a flotante en donde se devuelve el resultado de la operacion.
 * \return int Codigo de errores: 0-OK, -1-Error por divisor igual a cero.
 *
 */
int matDivision(float op1,float op2,float* resultado);

/** \brief Calcula el factorial de un numero.
 *
 * \param N int Numero a calcular.
 * \param resultado int* Puntero a entero en donde devuelve el resultado de la operacion.
 * \return int Codigo de error: 0-OK, -1-Error por numero menor a cero.
 *
 */
int matFactorial(int N,int* resultado);

/** \brief Ordenamiento de array de numeros enteros por metodo de insercion.
 *
 * \param array int* Array de numeros enteros a ser ordenados.
 * \param cantidad int Cantidad de elementos del array.
 * \param orden int 0-Orden descendente,1-Orden ascendente.
 * \return int 0-Predeterminado y unico valor.
 *
 * MODIFICAR: La funcion deberia comprobar errores.
 */
int ordenarArrayIntInsertion(int * array,int cantidad,int ordenAscendente);
/** \brief Inicia un array de tipo **** en el valor que desiemos
 *
 * \param array pasamos el array que queremos iniciar
 * \param tam pasamos el tamaño de el array a iniciar
 * \return retorna -1 si hay un error 0 si esta todo ok
 *
 */
int init*****(***** array[],int tam);

/** \brief Genera un id aleatorio automaticamente y lo asigna al array
 *
 * \param le pasamos el array
 * \param el tamaño del array
 * \return retorna -1 si esta vacio y 0 si esta ok
 *
 */

int idGenerator(***** array[],int len);
/** \brief Busca algo por id
 *
 * \param se le pasa el array
 * \param se le pasa el tamaño y el id a buscar
 * \return retorna -1 si no encontro o el numero de posicion en el array
 *
 */

int find********ById(******* * list, int len,int id);
/** \brief modifica una entidad
 *
 * \param se le pasa el array
 * \param se le pasa el tamaño del array
 * \return retorna -1 si hay error 0 si esta OK
 *
 */

int modify*******(******* * list,int len);

/** \brief BAJA LOGICA
 *
 * \param ARRAY
 * \param TAMAÑO DEL ARRAY Y ID DE USUARIO A BAJAR
 * \return SI ENCONTRO EL USUARIO 0 SI NO ENCONTRO -1
 *
 */

int remove*******(******* * list, int len, int id);

/** \brief MUESTRA UN ARRAY
 *
 * \param ARRAY
 * \param TAMAÑO DEL ARRAY
 * \return VOID
 *
 */

void mostrar(******* list[] , int len);
/** \brief VALIDA NUMEROS
 *
 * \param SE LE PASA UN ARRAY DE NUMEROS A VALIDAR
 * \param
 * \return RESTORNA 0 SI SON TODOS NUMEROS RETORNA 1 SI ENCONTRO LETRAS
 *
 */

int validar_Num(char numero[]);
/** \brief VALIDA LETRAS
 *
 * \param se le pasa la cadena de caracteres
 * \param
 * \return retorna 0 si son  todas letras 1 si encontro numeros
 *
 */

int validar_cadena(char cadena[]);
#endif // FUNCIONES_H_INCLUDED
