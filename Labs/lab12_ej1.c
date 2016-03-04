/*
	Este programa solicita la nota y el nombre de un estudiante 
	Usamos salida formateada 
*/
#include <stdio.h>


int main(){
	char subjet[30];
	float grade;

	printf("Ingrese el nombre de la materia \n");
	//scanf("%s", &subjet[0]);
	scanf("%s", subjet);

	printf("Ingrese la nota de la materia \n");
	scanf("%f", &grade);
	
	printf("La materia es: %s y su nota es: %.1f\n", subjet, grade);

	return 0;
}
