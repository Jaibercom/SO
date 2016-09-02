/*
	Programa que calcula el promedio de los valores de un arreglo de n posiciones 
	-Crea el arreglo dinamicamente 
	-El numero de posiciones del arreglo se ingresa como argumento: así: ./program 50 (para 50 posiciones)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//#define MAXNUM 100
#define true 1
#define false 0

//Functions Declarations 
void generate_numbers(int _array[], int quantity);
float average(int _array[], int quantity);
int check_parameters(int argc, char*argv[]);


//Main function
int main(int argc, char*argv[]){

   float avg = 0;
	//int array[MAXNUM];
	int *numbers;
	int size;
	
	if( !check_parameters(argc, argv) ){
		fprintf(stderr, "usage: %s <array size>\n", argv[0] );
		exit(EXIT_FAILURE);
	}

	//Convert string to int
	size = atoi(argv[1]);
	printf ("El número de posiciones es: %d.\n",size);
	
	//Dynamically allocating memory  
	numbers = malloc(sizeof(int)*size);

	generate_numbers(numbers, size);

   avg = average(numbers, size);

   printf("El promedio es = %.2f\n", avg);

	free(numbers);

   return 0;
}

//checking parameters
int check_parameters(int argc, char*argv[]){
	
	//Checking the number of parameters
	if(argc != 2){
		return false;
	}
	
	//Checking second parameter is a number  
	if (!isdigit(*argv[1]))
	{
		return false;
	}
	return true;
}

//Generate numbers between 0 and 10
void generate_numbers(int _array[], int quantity){

	//int number;
	int i;

	//Seed
	srand (time(NULL));

	for(i= 0; i<quantity; i++){
      _array[i] = rand() % 11;
		printf("array[%d]: %d \n",i, _array[i]);	
   }	
}

//Calculate average
float average(int _array[], int quantity){
	
	float avg = 0;
	int sum =0;
	int i;
	
	for(i=0; i < quantity; i++){
      sum += _array[i];
   }
	avg = (float)sum/quantity;
	return avg;
	
}
