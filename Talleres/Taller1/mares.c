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

typedef struct{
	char name[NUMCHARNAME];
	float grade;
	uint credits; 
}strSubjet;

//Functions Declaration
int numberSubjets(FILE *file);
void getData(uint *, strSubjet *, FILE *);
void printData(uint *pNumSubjets, strSubjet *pSubjets);

float calculateAverage(uint _numSubjets, char _name[][NUMCHARNAME], float *pGrade);
void printResult(uint _numSubjets, char _name[][NUMCHARNAME], float *pGrade, float _average);

int main(int argc, char *argv[]){
	
	uint numSubjets = 0;
/*	char name [MAXSUBJ][NUMCHARNAME];
	//float grade[MAXSUBJ];	
	float *pGrades;
	float average;
*/
	char *fileName = NULL;//"materias.txt";
	FILE *inFile;
	//strSubjet subjets[100];
	strSubjet *subjets = NULL;
	
	if(argc != 2){
		printf("Numero de parametros no valido, debe ingresar asi: 	./a.out <nombrefichero>\n");
		exit(EXIT_FAILURE);
	}

	fileName = argv[1];
	
	inFile = fopen(fileName, "r");
	if(inFile == NULL){
		printf("No se puede abrir el fichero: %s\n", fileName);
		exit(EXIT_FAILURE);
	}
	
	numSubjets = numberSubjets(inFile);
	printf("No. de materias es : %d\n", numSubjets);

	subjets = malloc(sizeof(strSubjet)*numSubjets);	

	getData(&numSubjets, subjets, inFile);
	printData(&numSubjets, subjets);
	/*
	numSubjets = numberSubjets();
	pGrades = (float *)malloc(sizeof(float)*numSubjets);

	getData(&numSubjets, name, pGrades);
	
	average = calculateAverage(numSubjets, name, pGrades);
	
	printResult(numSubjets, name, pGrades, average);
		
*/	fclose(inFile);
	free(subjets);
	return EXIT_SUCCESS;
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

void getData(uint *pNumSubjets, strSubjet *pSubjets, FILE *file)	{
	int i = 0;
	for(i=0; i< *pNumSubjets; i++){
		fscanf(file, "%s", &(pSubjets+i)->name[0]);
		fscanf(file, "%f", &(pSubjets+i)->grade);
		fscanf(file, "%d", &(pSubjets+i)->credits);
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
