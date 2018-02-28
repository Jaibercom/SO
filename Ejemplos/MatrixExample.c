#include <stdio.h>
#include <stdlib.h>
 
void getData(int **p);

int main(void) 
{ 
 
	int rows = 2;
	int columns = 3;	
	int **matrix;	
 
	int i;	 // Recorre rows 
	int j;	 // Recorre columns 
 
	// Reserva de Memoria 
	matrix = (int **)malloc(rows*sizeof(int*)); 
	
	for (i=0;i<rows;i++) 
		matrix[i] = (int*)malloc(columns*sizeof(int)); 
 
	getData(matrix);
 
	// Dibujamos la Matriz en pantalla 
	for (i=0; i<rows; i++) 
	{ 
		printf("\n"); 
		for (j=0; j<columns; j++) 
			printf("\t%d", matrix[i][j] ); 
	} 
	printf("\n");
	
	return 0; 
} 

void getData(int **p){
	
// Damos Valores a la Matriz 
	p[0][0] = 1; 
	p[0][1] = 2; 
	p[0][2] = 3; 
 
	p[1][0] = 4; 
	p[1][1] = 5; 
	p[1][2] = 6; 


}



