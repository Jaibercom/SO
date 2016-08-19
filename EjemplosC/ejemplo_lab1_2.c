/*
	1. Solicitar el primer nombre del estudiante y almacenarlo como una cadena de caracteres.
	2. Nota obtenida y almacenarla como un flotante.
	3. Imprimir:
	   - Nombre: máx 5 caracteres, alineado a la izquierda.
	   - Nota: ancho del campo 5, máx 2 decimales.
	4. La tecla q para terminar.
*/
#include <stdio.h>

//Variables globales

int main(){
	//variables locales
	char name[20] = "Pepito";  
	//char name[20] = {'p','e','p','i','t','o','\0'};

	//int values[] = {1, 2, 3, 40};

	float grade = 0;
	char key = 'a';
	
	do{
		printf("\nHola compañero !!\n");
		puts("Digite su nombre: ");
		scanf("%s", &name[0]);

		puts("Digite su nota: ");
		scanf("%f", &grade);

		//printf("Su nombre es %s y su nota fue %.1f\n", name, grade);
		printf("%-10s \t %-10s\n", "Nombre", "Nota");
		printf("%10.5s \t %10.2f\n", name, grade);

		setbuf(stdin, NULL);
		printf("para terminar q");
		key = getchar();
	}
	while(key != 'q');		

	return 0;
}
