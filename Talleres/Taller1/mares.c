/*
	Taller #1	
	Mares en c 
	por: Jaiber Yepes 
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIGN 20
#define NUMCHARNAME 20

void getData(unsigned int *, char _name[][NUMCHARNAME], float *);
float average();
void printResult();


int main(){
	
	int i = 0;
	unsigned int numSign = 0;
	char name [MAXSIGN][NUMCHARNAME];
	//float grade[MAXSIGN];	
	float *grade;
	
	printf("Ingrese el numero de materias  \n");
	scanf("%d", &numSign);

	grade = (float *)malloc(sizeof(float)*numSign);
	grade++;

	getData(&numSign, name, grade);
	
	printf("%-10s %-5s\n", "nombre", "nota" );
	for(i=0; i<numSign; i++){		
		printf("%-10s %5.2f\n", name[i], grade[i] );
		//printf("%-10s\n", name[i]);
	}

	free(grade);
	return 0;
}


void getData(unsigned int *pNumMat, char _name[][NUMCHARNAME], float *pGrade){
	
	int i = 0;
	
	//printf("%d\n", *pNumMat);
	
	for(i=0; i< *pNumMat; i++){
		printf("Ingrese el nombre de la materia  \n");
		scanf("%s", (char*)&_name[i]);

		printf("Ingrese la nota de la materia  \n");
		scanf("%f", pGrade+i);
	
	}


}


