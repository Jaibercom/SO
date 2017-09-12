/*
	Ejemplo de como reservar memoria dinamica, uso de argumentos, uso de punteros, funciones.
	compilar: gcc ejemplo1.c -o ejemplo 	
	ejecutar: ./ejemplo 10

*/

#include <stdio.h>
#include <stdlib.h>
//Prototipo
float *reservar_memoria(int *n);

int main(int argc, char *argv[]){
	
	int cant=0;
	int i=0;
	int *p_cant = malloc(sizeof(int));
	float arr[20];
	float *ptr_arr;

	if (argc != 2){
		printf("error: debe ingesar asi: ./a.out <numero posiciones>\n");
		exit(0)	;
	}	
	//Verificar
	printf("arc= %d\n", argc);
	printf("argv[0] = %s\n", argv[0]);
	printf("argv[1] = %s\n", argv[1]);

	*p_cant = atoi(argv[1]);

	printf("cant = %d\n", *p_cant);
	
	//solicitar memoria
	ptr_arr = reservar_memoria(p_cant);
	
	//Escribir en la memoria
	for(i=0; i< *p_cant; i++){
		*(ptr_arr+i) = i*i;
	}
	//Leer en la memoria
	for(i=0; i< *p_cant; i++){
		//printf("arreglo[%d] = %.2f\n", i, *(ptr_arr+i));
		printf("arreglo[%d] = %.2f\n", i,  ptr_arr[i]);
	}
	//liberar memoria
	free(ptr_arr);	
	return 0;
} 

//Impementación
float *reservar_memoria(int *n){
	float *ptr = NULL;
	printf("n = %d\n", *n);
	ptr = malloc((*n)*sizeof(float));
	return ptr;
}


