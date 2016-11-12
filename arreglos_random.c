#include <stdlib.h>
#include <time.h>

/*  Crea un arreglo de enteros(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
int* arreglo_int(size_t num, int min, int max){

	//arreglo para los numeros aleatorios con calloc ya que esta inicializa la memoria asignada
	int *num_random = (int *)calloc(num,sizeof(int));
	//creamos la semilla
	srand( time(NULL) ); 
	//llenamos el arreglo
	for( int i = 0; i<num; i++ ){
		/*obtenemos un numero aleatorio le sacamos modulo con min y max para
		tener un numero x, tal que min<x<max*/
		num_random[i] = (rand()%(max+1-min))+min;
	}
	//regresamos un puntero que hace referencia a la primera al arreglo
	return num_random;

}

/*  Crea un arreglo de doubles(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
double* arreglo_double(size_t num, double min, double max){

	//arreglo para los numeros aleatorios  con calloc ya que esta inicializa la memoria asignada
	double *num_random = (double *)calloc(num,sizeof(double));
	//creamos la semilla
	srand48( time(NULL) );
	//llenamos el arreglo
	for( int i = 0; i<num; i++ ){
		/*obtenemos un numero aleatorio le sacamos modulo con min y max para
		tener un numero x, tal que min<x<max*/
		num_random[i] = drand48()*(max-min)+max; 
	}
	//regresamos un puntero que hace referencia a la primera al arreglo
	return num_random;

}