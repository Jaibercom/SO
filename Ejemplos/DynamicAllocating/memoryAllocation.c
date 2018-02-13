/*
	P11 del lab1_3
*/
#include <stdio.h>
#include <stdlib.h>

#define NUMCHAR 4

//Variables globales


//Declaracion de funciones 
void getData(float * , int );
float *reserveDynamicMemory(int n);
void printData(float * , int );
float average(float * , int );


int main(){
	//variables locales
	//float numbers[NUMCHAR];
	float *numbers;
	float avg;
	int size; 

	printf("Ingrese el numero de datos \n");
	scanf("%d", &size);
	numbers = reserveDynamicMemory(size);

	getData(numbers, size);
	printData(numbers, size);
	avg = average(numbers, size);

	printf("El promedio es: %.1f\n", avg );

	free(numbers);
	
	return 0;
}

//Implementacion de funciones 
float *reserveDynamicMemory(int n){

	float *ptr = NULL;
	//printf("n = %d\n", *n);
	ptr = (float *) malloc(n*sizeof(float));
	
	return ptr;
}


void getData(float *ptrNumbers, int size){

	int i;

	printf("Ingrese %d datos: \n", size);
	for(i=0; i<size; i++){
		scanf("%f", ptrNumbers++);		
		//scanf("%f", numbers);
		//scanf("%f", &ptrNumbers[i]);
		//ptrNumbers++;	
	}
}


void printData(float *ptrNumbers , int size){

	int i;
	printf("Los datos son: ");

	for(i=0; i<size-1; i++){
		//printf("Los datos son: %.1f\n", numbers[i]);
		printf("%.1f, ", *ptrNumbers);
		ptrNumbers++;
	}

	printf("%.1f \n", *ptrNumbers);
}

float average(float *ptrNumbers , int size){

	float avg = 0;
	float sum = 0;
	int i;
	for(i=0; i<size; i++){
		sum += *ptrNumbers;
		ptrNumbers++;
	}
	avg = sum/size;	

	return avg;
}

