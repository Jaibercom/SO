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

typedef struct{
	char name[20];
	float grade;
	int credits;
}strSubjet;

typedef unsigned int uint;

//Declaracion de funciones 
int numberSubjets(FILE *file);
void getData(strSubjet *pSubjets, uint numSubjets, FILE *file);


int main(int argc, char *argv[]){
		
	FILE *inFile;
	char *fileName;
	//char buffer[100];
	//int cred;
	//float grade;
	int i;	
	uint numSubjets;

	//strSubjet subjets[20];
	strSubjet *subjets;
	
	
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
	//printf("La cantida de materias es: %d\n", numSubjets);	

	
	subjets = (strSubjet *) malloc(sizeof(strSubjet)*numSubjets);

	getData(subjets, numSubjets, inFile);
	

	return 0;
}


//Functions implementation
int numberSubjets(FILE *file){
	int num = 0;
	char buffer[NUMCHARNAME];
	while(!feof(file)){
		fgets(buffer, NUMCHARNAME, file);
		//	puts(buffer);
		num++;
	}	
	rewind(file);
	return num/3;
}

void getData(strSubjet *pSubjets, uint numSubjets, FILE *file){
	int i = 0;
	for(i=0; i<numSubjets; i++){
		
		fscanf(file, "%s", &pSubjets->name[0]);
		printf("%s\n", pSubjets->name);
	
		fscanf(file, "%f", &pSubjets->grade);
		printf("%f\n", pSubjets->grade);

		fscanf(file, "%d", &pSubjets->credits);
		printf("%d\n", pSubjets->credits);
		
		pSubjets++;
	}




}

