/*Incluye las funciones de b_sort.c y arreglos_random.c*/
#include "b_sort.h"
#include "arreglos_random.h"

/*Declara las funciones que vamos a ocupar*/
// función que compara dos enteros
int cmp_int(const void *a, const void *b);
// función que compara dos doubles
int cmp_double(const void *a, const void *b);
// función que imprime una lista de enteros de tamaño num
void imprime_int(int *arreglo, size_t num);
// función que imprime una lista de doubles de tamaño num
void imprime_double(double *arreglo, size_t num);


int main()
{
    // Se inicializan 2 arreglos, uno de ints y otro de doubles
    int *arr1 = arreglo_int(20, 0, 10);
    double *arr2 = arreglo_double(20, 0, 10);

    // Se imprime ordena e imprime el primer arreglo
    imprime_int(arr1, 20);
  	bsort(arr1, 20, sizeof(int), &cmp_int);
    imprime_int(arr1, 20);

    // Se imprime ordena e imprime el segundo arreglo
    imprime_double(arr2, 20);
    bsort(arr2, 20, sizeof(double), &cmp_double);
    imprime_double(arr2, 20);

    // Se libera la memoria que ocupan los arreglos ordenados
    free(arr1);
    free(arr2);

    return 0;
}

int cmp_int( const void *a, const void *b ){
	//hacemos el cast
	const int *x = (const int *)a;
	const int *y = (const int *)b;
	//si es mas pequeño el primero que el segundo regresa -1
	if( *x < *y )
		return -1;
	//si es mas grande el primero que el segundo regresa 1
	if( *x > *y )
		return 1;
	//si son iguales regresa 0
	return 0;

}

int cmp_double( const void *a, const void *b ){
	//hacemos el cast
	const double *x = (const double *)a;
	const double *y = (const double *)b;

	//si es mas pequeño el primero que el segundo regresa -1
	if( *x < *y )
		return -1;
	//si es mas grande el primero que el segundo regresa 1
	if( *x > *y )
		return 1;
	//si son iguales regresa 0
	return 0;


}

void imprime_int( int *arreglo, size_t num ){
	//contador
	int i;
	//por cada elemento en el arreglo lo imprimimos
	for( i = 0; i < num ; i++ )
		printf( "%d ", arreglo[i] );
	//doble salto de linea para que sea mas visible el resultado
	printf("\n\n");

}

void imprime_double(double *arreglo, size_t num){
//contador
	int i;
	//por cada elemento en el arreglo lo imprimimos
	for( i = 0; i < num ; i++ )
		printf( "%f ", arreglo[i] );
	//doble salto de linea para que sea mas visible el resultado
	printf("\n\n");

}