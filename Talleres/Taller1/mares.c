/*
	Taller #1	
	Mares en c 
	Calcula el promedio de n materias 
	por: Jaiber Yepes 
*/
#include <stdio.h>
#include <stdlib.h>

//Macros
#define MAXSUBJ 20
#define NUMCHARNAME 20
typedef unsigned int uint;

//Functions Declaration
int numberSubjets();
void getData(unsigned int *, char _name[][NUMCHARNAME], float *);
float calculateAverage(uint _numSubjets, char _name[][NUMCHARNAME], float *pGrade);
void printResult(uint _numSubjets, char _name[][NUMCHARNAME], float *pGrade, float _average);

int main(int argc, char *argv[]){
	
	uint numSubjets = 0;
	char name [MAXSUBJ][NUMCHARNAME];
	//float grade[MAXSUBJ];	
	float *pGrades;
	float average;
	
	numSubjets = numberSubjets();
	pGrades = (float *)malloc(sizeof(float)*numSubjets);

	getData(&numSubjets, name, pGrades);
	
	average = calculateAverage(numSubjets, name, pGrades);
	
	printResult(numSubjets, name, pGrades, average);
	
	free(pGrades);
	return 0;
}

//Functions implementation
int numberSubjets(){
	uint num;
	printf("Ingrese el numero de materias  \n");
	scanf("%d", &num);
	return num;
}

void getData(uint *pNumSubjets, char _name[][NUMCHARNAME], float *_pGrades){

	int i = 0;
	for(i=0; i< *pNumSubjets; i++){
		printf("Ingrese el nombre de la materia  \n");
		scanf("%s", (char*)&_name[i]);

		printf("Ingrese la nota de la materia  \n");
		scanf("%f", _pGrades+i);
	}
}

float calculateAverage(uint _numSubjets, char _name[][NUMCHARNAME], float *pGrade){
	
	int i = 0;
	float avg = 0;
	for(i=0; i<_numSubjets; i++){		
		avg += *(pGrade+i);
	}
	avg /= _numSubjets;
	return avg;
}

void printResult(uint _numSubjets, char _name[][NUMCHARNAME], float *_pGrade, float _average){
	
	int i = 0;
	printf("\n%-10s %-5s\n", "Nombre", "Nota" );
	for(i=0; i<_numSubjets; i++){		
		printf("%-10.10s %-5.1f\n", _name[i], *(_pGrade+i) );
	}
	printf("El promedio es: %.1f \n", _average);
	
}
