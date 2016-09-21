/*
	Ejemplo de estructura punto

	Ejercicio:

	-Agregue un item a la estructura que permita almacenar un nombre al punto 
	-Crear un función que calcule la distancia entre 2 puntos 
	-Modifique este código con el fin que los números se lean desde un fichero y al final de este se debe escribir la distancia que hay entre los dos puntos, 
	Nota:el nombre del fichero debe pasarse como parámetro al ejecutarse, así: ./<nombre ejecutable> points.csv    


*/
#include <stdio.h>
#include <stdlib.h> 

//definicion de la estructura
//Forma 1
struct point {
	int x;
	int y;
	//char name[20];
};

//Forma 2
typedef struct {
	int x;
	int y;
} point_str;

//Declaracion de funciones
void getPoint(point_str *ptr);
void printPoint(point_str *ptr);

int main(){

	//point_str points[2];
	int i;
	point_str *points;
	
	points = malloc(sizeof(point_str)*2);

	for(i=0; i<2; i++){
		//llamado funcion getPoint		
		getPoint(&points[i]);
	}

	for(i=0; i<2; i++){
		printPoint(&points[i]);
	}

	free(points);
	return 0;
}

//Implementacion de funciones 
void getPoint(point_str *ptr){
	//int x;
	printf("Ingrese x y y del punto\n");
	scanf("%d %d", &ptr->x, &ptr->y);
}

void printPoint(point_str *ptr){

	printf("el punto es x = %d, y = %d \n", ptr->x, ptr->y);

}
