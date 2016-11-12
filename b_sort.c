#include <stdio.h>
#include <stdlib.h>

/*  bsort: ordena un arreglo usando el algoritmo bubble sort
    base: es un apuntador a un arreglo a ordenar
    num: es el número de elementos en el arreglo
    size: es el tamaño en bytes de cada elemento en el arreglo
    compar: es el apuntador a una función comparadora, que regresa:
           número negativo si el primer elemento es menor
           0 si ambos elementos son iguales
           número positivo si el primer elemento es mayor
*/
void bsort(void* base, size_t num, size_t size,
            int (*compar)(const void*, const void*)){

	//variable de control para saber cuando el valor este ordenado
	int ordenado = 1;
	//contadores
	int i;
	int j=0;

	//si es te tipo entero
	if( size == sizeof( int ) ){
		int *arr = (int*)base;
		//Mueve el valor mientras no este ordenado
		while( ordenado == 1 ){

			//lo declaramos falso para saber cuando este ordenado
			ordenado = 0;
			//vamos decreciendo hasta que posición se debe comparar
			j ++;

			//así recorremos los valores del arreglo
			for( i = 0; i < (num-j) ; i++ )
				//en caso de que el primer valor sea mayor al segundo se intercambian
				if( (*compar)( (arr+i), (arr+i+1) ) > 0 ){

					//asignamos el valor de*(( int)arr+i) a la variable v
					int v = *(arr+i);
					//asignamos el valor de*(( int)arr+i+1) al apuntador*(( int)arr+i)
					*(arr+i) = *(arr+i+1);
					//asignamos el valor de la variable v al apuntador*(( int)arr+i+1)
					*(arr+i+1) = v;

					//el valor ya esta ordenado
					ordenado = 1;


				}

		}
	}

	//si es de tipo double
	if( size == sizeof( double ) )
		//Mueve el valor mientras no este ordenado
		while( ordenado == 1 ){

			//lo declaramos falso para saber cuando este ordenado
			ordenado = 0;
			//vamos decreciendo hasta que posición se debe comparar
			j ++;

			//así recorremos los valores del arreglo
			for( i = 0; i < (num-j) ; i++ )
				//en caso de que el primer valor sea mayor al segundo se intercambian
				if( (*compar)( ((double*)base+i), ((double*)base+i+1) ) > 0 ){

					//asignamos el valor de*(( double*)base+i) a la variable v
					double v = *((double*)base+i);
					//asignamos el valor de*(( double*)base+i+1) al apuntador*(( double*)base+i)
					*((double*)base+i) = *((double*)base+i+1);
					//asignamos el valor de la variable v al apuntador*(( double*)base+i+1)
					*((double*)base+i+1) = v;

					//el valor ya esta ordenado
					ordenado = 1;


				}

		}

	

}