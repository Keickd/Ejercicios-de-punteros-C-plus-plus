/*11. Hacer un programa que multiplique dos arrays bidimensionales de 3 x 3 elementos hacia
un tercer array.*/

#include <stdio.h>
#include <stdlib.h>


void rellenarMatrizSinPunteros(int matriz[3][3]);
int** reservarMemoria(int **, int, int);
void rellenarMatrizConPunteros(int **, int, int);
void multiplicarMatrices(int **, int **, int **, int, int);

void mostrarMatrizSinPunteros(int matriz[3][3]);
void mostrarMatrizConPunteros(int **);
void liberarMemoria(int **, int);

int main(){
	int tabla1[3][3];
	int tabla2[3][3];
	int tabla3[3][3];
	
	//SIN USAR PUNTEROS --> TAMAÑO FIJO
	/*
	rellenarMatrizSinPunteros(tabla1);//Ejemplo
	mostrarMatrizSinPunteros(tabla1);
	*/


	//USANDO PUNTEROS --> TAMAÑO DINAMICO
	int nFilas = 3, nColumnas = 3; //o se le pide al usuario
	int **matriz1, **matriz2, **matriz3;

	matriz1 = reservarMemoria(matriz1, nFilas, nColumnas);
	matriz2 = reservarMemoria(matriz2, nFilas, nColumnas);
	matriz3 = reservarMemoria(matriz3, nFilas, nColumnas);
	//pointer = (type *)malloc(number_of_elements * sizeof(type));

	printf("Matriz 1: \n");
	rellenarMatrizConPunteros(matriz1, nFilas, nColumnas);
	printf("Matriz 2: \n");
	rellenarMatrizConPunteros(matriz2, nFilas, nColumnas);

	multiplicarMatrices(matriz1, matriz2, matriz3, nFilas, nColumnas);

	mostrarMatrizConPunteros(matriz3);

	liberarMemoria(matriz1, nFilas);
	liberarMemoria(matriz2, nFilas);
	liberarMemoria(matriz3, nFilas);
	
	return 0;
}

void rellenarMatrizSinPunteros(int matriz[3][3]){
	for (int i = 0; i < 3; i++) {
	        for (int j = 0; j < 3; j++) {
	            printf("matriz[%d][%d]: ", i, j);
	            fflush(stdout);
	            scanf("%d", &matriz[i][j]);
	        }
	    }
}

int** reservarMemoria(int **matriz, int nFilas, int nColumnas){
	matriz = (int **)malloc(nFilas * sizeof(int *));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matriz[i] = (int *)malloc(nColumnas * sizeof(int));
		}
	}

	return matriz;
}

void rellenarMatrizConPunteros(int **matriz, int nFilas, int nColumnas){
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("matriz[%d][%d]: ", i, j);
			fflush(stdout);
			scanf("%d", *(matriz + i) + j);
		}
	}
}


void mostrarMatrizSinPunteros(int matriz[3][3]){
	for (int i = 0; i < 3; i++) {
		 for (int j = 0; j < 3; j++) {
			 printf(" %d ", matriz[i][j]);
		 }
		 printf("\n");
	 }
}

void mostrarMatrizConPunteros(int **matriz){
	for (int i = 0; i < 3; i++) {
		 for (int j = 0; j < 3; j++) {
			 printf(" %d ", *(*(matriz + i) + j));
		 }
		 printf("\n");
	 }
}

void multiplicarMatrices(int **matriz1, int **matriz2, int **matrizResultado, int nFilas, int nColumnas){
	for (int i = 0; i < 3; i++) {
		 for (int j = 0; j < 3; j++) {
			 matrizResultado[i][j] = matriz1[i][j] * matriz2[i][j];
			 //*(*(matrizResultado + i) + j) = *(*(matriz1 + i) + j) * (*(*(matriz2 + i) + j));
		 }
	 }
}

void liberarMemoria(int **matriz, int nFilas){
	for(int i = 0; i < nFilas; i++){
		free(matriz[i]);
	}
	free(matriz);
}

/*
Ejemplo de 3x4
matriz --> [*puntero] --> [int] [int] [int] [int]
		   [*puntero] --> [int] [int] [int] [int]
		   [*puntero] --> [int] [int] [int] [int]
*/
