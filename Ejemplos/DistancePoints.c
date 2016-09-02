/*
	Programa que calcula la distancia entre dos puntos


	Modificar:
	los puntos estan en un fichero asi:
	x1
	y1
	x2
	y2
	ejemplo:
	1
	1
	2
	2
	
	O pueden estar en un fichero separado por comas CSV asi; 
	x;y
	1;1
	2;2

	En este caso les sera util usar la funcion strtok
	

*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//Definicion de la estructura
//Forma 1 
struct point{
	char name[10];	
	int x;
	int y;
};
//Forma 2
typedef struct{
	char name[10];	
	int x;
	int y;
}strPoint;

//Declaracion 
float calculateDistance(struct point *ptr1, strPoint *ptr2);

int main(){
	
	float distance;
	struct point p1 = {"Punto1",1,1};
	strPoint p2;
	FILE *fp = NULL;
	char *fileName = "output.txt";
	fp = fopen(fileName, "w");

	if(fp == NULL){
		printf("no se pudo abrir el archivo %s\n", fileName);
		exit(0);
	}

	//struct point pts[2]; 
	//p2.name = "Punto2";
	/*p2.name[0] = 'P';
	p2.name[1] = 'u';
	p2.name[2] = 'n';
	p2.name[3] = 't';
	p2.name[4] = 'o';
	p2.name[5] = '\0';	*/
	strcpy(&p2.name[0], "Punto2");	
	p2.x = 2;
	p2.y = 2;
	
	//distance  = sqrt( pow((p2.y-p1.y),2) + pow((p2.x-p1.x),2));
	distance = calculateDistance( &p1, &p2);
	
	printf("La distancia entre el %s y el %s es: %.3f\n", p1.name, p2.name, distance);
	fprintf(fp, "La distancia entre el %s y el %s es: %.3f\n", p1.name, p2.name, distance );
	fclose(fp);
	return 0;
}

//Implementacion 
float calculateDistance(struct point *ptr1, strPoint *ptr2){
	float dist;
	float aux1=0, aux2=0;

	aux1 = pow( ptr2->y - ptr1->y ,2);
	aux2 = pow( ptr2->x - ptr1->x ,2);
	dist = sqrt(aux1 + aux2);

	return dist;
}

