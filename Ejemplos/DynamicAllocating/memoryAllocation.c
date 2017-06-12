/*
	P11 del lab1_3
*/
#include <stdio.h>
#include <stdlib.h>

#define NUMCHAR 4

//Variables globales


//Declaracion de funciones 
void getData(float * , int );
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
	numbers = (float *) malloc(sizeof(float)*size);
	
	getData(numbers, size);
	printData(numbers, size);
	avg = average(numbers, size);

	printf("El promedio es: %.1f\n", avg );
	
	return 0;
}

//Implementacion de funciones 
void getData(float *ptrNumbers, int size){
	int i;
	printf("Ingrese %d datos: \n", size);
	for(i=0; i<size; i++){
		scanf("%f", ptrNumbers++);		//scanf("%f", numbers);
		//scanf("%f", &ptrNumbers[i]);
		//ptrNumbers++;	
	}
}

void printData(float *ptrNumbers , int size){
	int i;
	for(i=0; i<size; i++){
		//printf("Los datos son: %.1f\n", numbers[i]);
		printf("Los datos son: %.1f\n", *ptrNumbers);
		ptrNumbers++;
	}
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

