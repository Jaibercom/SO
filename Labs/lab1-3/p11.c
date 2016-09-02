/*
	Programa que calcula el promedio de los valores de un arreglo de 100 posiciones 
	-Crea el arreglo estáticamente

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100

void generate_numbers(int _array[], int quantity);
float average(int _array[], int quantity);

int main(void) {

   float avg = 0;
	int numbers[MAXSIZE];

	generate_numbers(numbers, MAXSIZE);

   avg = average(numbers, MAXSIZE);
   printf("El promedio es = %.2f\n", avg);

   return 0;
}


//Generate numbers between 0 and 10
void generate_numbers(int _array[], int size){

	//int number;
	int i;

	//Seed
	srand (time(NULL));

	for(i= 0; i<size; i++){
      _array[i] = rand() % 11;
		printf("array[%d]: %d \n",i, _array[i]);	
   }
	
}

//Calculate average
float average(int _array[], int size){
	
	float avg = 0;
	int sum =0;
	int i;
	
	for(i=0; i < size; i++){
      sum += _array[i];
   }
	avg = (float)sum/size;
	return avg;
	
}




