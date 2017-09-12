/*
 * Name         : mares.c
 * Author       : Jaiber Yepes
 * Description  : Taller 1. Programa que permita calcular el promedio ponderado 
 *							obtenido por un estudiante en el semestre
 * Importance   : Poner en practica los temas vistos: Funciones, punteros, memoria dinamica, 
 *				  estructuras y ficheros
 * Compilation  : gcc -Wall mares.c -o mares
 * Execution    : ./mares materias.csv
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Macros
#define NUMCHARNAME 20

typedef struct {
	char name[NUMCHARNAME];
	float grade;
	int credits; 
}strSubjet;

//Functions Declaration
int getNumberSubjets(FILE *file);
void readData(FILE *file, int numSubjets, strSubjet *prtStrSubjet);
void printData(FILE *file, int numSubjets, strSubjet *prtStrSubjet);
float calculateAverage(int numSubjets, strSubjet *prtStrSubjet);

int main(int argc, char *argv[]){
	
	int value;	
	int numSubjets = 0;
	FILE *inFile;
	char *fileName = NULL;
	float average;

	//strSubjet subjets[4];
	strSubjet *subjets;
	
	//Validar Argumentos
	if(argc != 2 ){
		printf("Se debe ejecutar asi: %s materias.csv\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fileName = argv[1];
	
	//Abrir fichero
	inFile = fopen(fileName, "a+");
	if(inFile == NULL){
		printf("No se puede abrir el fichero: %s\n", fileName);
		exit(EXIT_FAILURE);
	}
	
	//Obtener el numero de materias 
	numSubjets = getNumberSubjets(inFile);
	printf("El numero de materias es:  %d \n", numSubjets);
	
	//reservar memoria 
	subjets =  (strSubjet *) malloc(sizeof(strSubjet)*numSubjets);
	
	//Leer información del fichero
	readData(inFile, numSubjets, subjets); 
	printData(inFile, numSubjets, subjets); 
	
	//Realizar calculos
	average = calculateAverage(numSubjets, subjets);
	printf("\nEl promedio ponderado es : %0.1f\n", average);

	//Liberar memoria
	fclose(inFile);
	free(subjets);
	
	return 0;
}

//Functions implementation
int getNumberSubjets(FILE *file){
	int num = -2;
	char buffer[100];

	while( !feof(file) ){		//es lo mismo que:   feof(file) == 0
		fgets(buffer, 100, file);
		//puts(buffer);
		num++;
	}	
	
	rewind(file);
	return num-1;
}

void readData(FILE *file, int numSubjets, strSubjet *prtStrSubjet){

	int i = 0;
	char *pch;
	char buffer[100];

	float var;
	int varInt;

	rewind(file);
	fgets(buffer, 100, file);	//Leo linea 1
	fgets(buffer, 100, file);	//Leo linea 2

	for(i=0; i<numSubjets; i++){

		fgets(buffer, 100, file);
		//puts(buffer);
		
		//"Laboratorio;4.5;1"     "4.5"
		pch = (char *)strtok(buffer, ";");
		strcpy(prtStrSubjet->name, pch);
		//printf("*Materia: %s\n", prtStrSubjet->name);

		pch = (char *)strtok(NULL, ";");
		prtStrSubjet->grade = atof(pch);
		//printf("*Nota: %.1f\n", prtStrSubjet->grade);

		pch = (char *)strtok(NULL, ";");
		prtStrSubjet->credits = atoi(pch);
		//printf("*Creditos %d\n", prtStrSubjet->credits);

		prtStrSubjet++;
		
	}
}

void printData(FILE *file, int numSubjets, strSubjet *prtStrSubjet){

	int i = 0;
	char *pch;
	char buffer[100];

	printf("%-20.20s -- %-6.6s -- %-8.8s\n", "Materia", "Nota", "Creditos");
	for(i=0; i<numSubjets; i++){

		printf("%-20.18s -- %-6.1f --    %-8d\n", prtStrSubjet->name, prtStrSubjet->grade, prtStrSubjet->credits);
		prtStrSubjet++;
		
	}
}

float calculateAverage(int numSubjets, strSubjet *prtStrSubjet){
	
	int i = 0;
	float avg = 0;
	int numCred = 0;
	float numGrades = 0;

	for(i=0; i<numSubjets; i++){
		numCred += prtStrSubjet->credits;
		numGrades += prtStrSubjet->grade * prtStrSubjet->credits;

		prtStrSubjet++;
	}
	//printf("numGrades: %.1f\n", numGrades);	
	//printf("numCred: %d\n", numCred);

	avg = numGrades/numCred;
	return avg;
}

