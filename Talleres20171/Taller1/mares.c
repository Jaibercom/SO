/*
 * Name         : mares.c
 * Author       : Jaiber Yepes
 * Description  : Taller 1. Realice un programa que permita calcular el promedio ponderado 
 *							obtenido por un estudiante en el semestre
 * Importance   : Poner en practica los temas vistos: Funciones, punteros, memoria dinamica, estructuras y ficheros
 * Compilation  : gcc -Wall mares.c -o mares
 * Execution    : ./mares
*/


#include <stdio.h>
#include <stdlib.h>

//Macros
#define NUMCHARNAME 20

typedef struct {
	char name[NUMCHARNAME];
	float grade;
	uint credits; 
}strSubjet;

//Functions Declaration
int getNumberSubjets();
void readData(/* implementar*/);
void printData(/* implementar*/);
float calculateAverage(/* implementar*/);
void printResult(/* implementar*/);

int main(int argc, char *argv[]){
	
	int value;	
	int numSubjets = 0;
	FILE *inFile;
	
	char *fileName = argv[1];
	
	inFile = fopen(fileName, "r");
	if(inFile == NULL){
		printf("No se puede abrir el fichero: %s\n", fileName);
		exit(EXIT_FAILURE);
	}
	
	numSubjets = getNumberSubjets(inFile);
	printf("El numero de materias es:  %d \n", numSubjets);
	
	//reservar memoria 


	
	//Leer información del fichero
	//readData( .... ); 
	//printData( .... ); 
	


	//Realizar calculos
	/*
	average = calculateAverage();
	printResult();
	*/

	//Liberar memoria
	fclose(inFile);
	
	return 0;
}

//Functions implementation
int numberSubjets(FILE *file){
	int num = -2;
	char buffer[NUMCHARNAME];
	while(!feof(file)){
		fgets(buffer, NUMCHARNAME, file);
		//puts(buffer);
		num++;
	}	
	rewind(file);
	return num;
}

void getData(int pNumSubjets, strSubjet *pSubjets, FILE *file){

	int i = 0;
	for(i=0; i<pNumSubjets; i++){
			
	}
}

void printData(){


}

float calculateAverage(){
	
	int i = 0;
	float avg = 0;





	return avg;
}

void printResult(){
	//Implementar, escribir en fichero de salida 
	/*
	int i = 0;
	printf("\n%-10s %-5s %-8s\n", "Nombre", "Nota", "Creditos" );


	//printf("El promedio ponderado es: %.1f \n", _average);
	*/
}
