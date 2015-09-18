/*
	Taller #1	
	Mares en c 
	por: Jaiber Yepes 
	
	Programa que permite calcular el promedio ponderado 
	obtenido por un estudiante en el semestre, considerando: 

	1. El programa recibe el archivo de entrada como el siguiente:
	
		Materia: SO
		Nota: 3.0
		Créditos: 4
		Materia: LAB
		Nota: 4.5
		Créditos: 1
		. 
		. 
		. 

	2. El programa debe generar el archivo de salida como el siguiente:
	
		Materia Nota Créditos 
		SO 		3.0		4
		LAB		4.5 		1
		. 
		.
		.
		Total de materias: 2
		Materias ganadas: 2
		Materias perdidas: 0
		Promedio ponderado: 3.3
*/

#include <stdio.h>
#include <stdlib.h>

//Macros
#define MAXSUBJ 20
#define NUMCHARNAME 20
typedef unsigned int uint;

typedef struct {
	char name[NUMCHARNAME];
	float grade;
	uint credits; 
}strSubjet;

//Functions Declaration
int numberSubjets();
void getData(uint *pNumSubjets, strSubjet *pSubjets, FILE *file);
void printData(uint *pNumSubjets, strSubjet *pSubjets);
float calculateAverage(uint *pNumSubjets, strSubjet *pSubjets);
void printResult(/* implementar*/);

int main(int argc, char *argv[]){
	
	uint value;	
	uint numSubjets = 0;
	strSubjet *pSubjets;
	FILE *inFile;
	
	char *fileName = "materias.txt";
	
	inFile = fopen(fileName, "r");
	if(inFile == NULL){
		printf("No se puede abrir el fichero: %s\n", fileName);
		exit(EXIT_FAILURE);
	}
	
	numSubjets = numberSubjets(inFile);
	printf("El numero de materias es:  %d \n", numSubjets);
	pSubjets = (strSubjet *)malloc(sizeof(strSubjet)*numSubjets);
	
	getData(&numSubjets, pSubjets, inFile); 
	printData(&numSubjets, pSubjets); 
	
	/*
	average = calculateAverage(numSubjets, name, pGrades);
	
	printResult(numSubjets, name, pGrades, average);
	*/
	free(pSubjets);
	value =	fclose(inFile);
	if (value == 0)
		printf("Se cerro el fichero\n");
	
	return 0;
}

//Functions implementation
int numberSubjets(FILE *file){
	int num = 0;
	char buffer[NUMCHARNAME];
	while(!feof(file)){
		fgets(buffer, NUMCHARNAME, file);
		//puts(buffer);
		num++;
	}	
	rewind(file);
	return num/3;
}

void getData(uint *pNumSubjets, strSubjet *pSubjets, FILE *file){

	int i = 0;
	for(i=0; i< *pNumSubjets; i++){
		fscanf(file, "%s", pSubjets->name);
		//printf("materia: %s\n", pSubjets->name);
		
		fscanf(file, "%f", &pSubjets->grade);
		//printf("nota: %.1f\n", pSubjets->grade);
		
		fscanf(file, "%d", &pSubjets->credits);
		//printf("creditos: %d\n", pSubjets->credits);
		
		pSubjets++;					
	}
}

void printData(uint *pNumSubjets, strSubjet *pSubjets){

	int i = 0;
	for(i=0; i< *pNumSubjets; i++){
		printf("\nmateria: %s\n", pSubjets->name);	
		printf("nota: %.1f\n", pSubjets->grade);
		printf("creditos: %d\n", pSubjets->credits);
		
		pSubjets++;						
	}
}

float calculateAverage(uint *pNumSubjets, strSubjet *pSubjets){
	
	int i = 0;
	float avg = 0;
	for(i=0; i<*pNumSubjets; i++){		
		//implementar
	}
	avg /= *pNumSubjets;
	return avg;
}

void printResult(){
	//Implementar, escribir en fichero de salida 
	/*
	int i = 0;
	printf("\n%-10s %-5s %-8s\n", "Nombre", "Nota", "Creditos" );

	for(i=0; i<_numSubjets; i++){		
		//printf("%-10.10s %-5.1f\n", _name[i], *(_pGrade+i) );
	}
	//printf("El promedio ponderado es: %.1f \n", _average);
	*/
}
