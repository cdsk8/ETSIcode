/* 
 *Definiciones de las Constantes para la práctica 2 
 */
#ifndef _CONSTANTES
#define _CONSTANTES

/* Constantes simbólicas para indicar el metodo de ordenacion*/
enum algoritmos {BURBUJA, INSERCION, SELECCION};
/* Constantes para indicar el Orden del metodo de ordenacion*/
enum ordenes {CUADRADO, NlogN};
/* Constantes para indicar el Numero de repeticiones para el caso medio de cada método de búsqueda */
static const int REPETICIONES = 100;
/* Constantes para indicar la variacion de las tallas del vector */
enum valoresTallas { TALLA_INI = 100, TALLA_FIN = 1000, TALLA_DELTA = 100}; 

#endif