/*
	Descripcion: taller1 realizado ude@ 
	autor: Jaiber Yepes 
	fecha: 09 Sept 2016

	Pendiente: -modificar la función "showEmployees" para hacer una salida formateada acorde a la descripción del taller 
			   -Crear una función que calcule el salario total de todos los trabajadores

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS_NAME 50
#define EMP_MAX 10

//Declaracion de funciones
void menu(char *action);
void addEmployees(char (*ptr_names)[MAX_CHARS_NAME], float *ptr_salaries, int *count);
void showEmployees(char (*ptr_names)[MAX_CHARS_NAME], float *salaries, int *count);

//int emp_max =10;


int main(int argc, char *argv[]) {
	
	int emp_count = 0;		//numero de empleados 
	char action = 'x';
	int i;
	float salaries[EMP_MAX];
	char names[EMP_MAX][MAX_CHARS_NAME];

	printf("numero max de empleados es : %d\n", EMP_MAX);
	
	do {
		menu(&action);

		switch(action) {
		  case 'a':
				printf("\n**Registrar trabajadores**\n"); 
				addEmployees( names, salaries, &emp_count);
			break;
		  case 'b':
				printf("**Ver trabajadores**\n"); 
				showEmployees( names, salaries, &emp_count);
			break;
		  case 'q':
				puts("Saliendo del programa...");
			break;
		  default:
				puts("Opción no valida, intenta de nuevo.");
			break;
		}
	} while(action != 'q');

	return 0;
}

//Implementacion de funciones
void menu(char *ptr_action) {
	
	puts("MENÚ DE OPCIONES");
	printf("a) Registrar trabajadores\n");
	printf("b) Ver lista de trabajadores\n");
	printf("q) Salir del programa\nSeleccione una opción:");

	setbuf(stdin, NULL);
	scanf("\n%c", ptr_action);

}

void addEmployees(char (*ptr_names)[MAX_CHARS_NAME],float *ptr_salaries, int *count){
	int num = 0;
	int i = 0;
	float aux;
	//float *ptr = &sal;
	//*ptr = 45.4;

	printf("Ingrese el número de empleados a registrar: ");
	setbuf(stdin, NULL);
	scanf("%d", &num);

	if ((*count + num) > EMP_MAX) {
		printf("El número de empreados a registrar sobrepasa la memoria.\n");
		return;
	}
	
	for(i=*count; i< (*count + num) ; i++){
		
		printf("ingrese el nombre %d  \n", i+1);
		scanf("%s", (char *)(ptr_names+i));

		printf("ingrese el salario %d  \n", i+1);
		//scanf("%f", &aux);
		//*(ptr_salaries+i) = aux;	
		scanf("%f", ptr_salaries+i);
	}
	//count = *count + num; 
	*count += num;
}

void showEmployees(char (*ptr_names)[MAX_CHARS_NAME], float *ptr_salaries, int *count){
	int i = 0;
	for(i=0; i<(*count); i++){
		printf("Nombre %d = %s\n", i+1, (char *)(ptr_names+i));
		printf("salario %d = %.1f\n", i+1, *(ptr_salaries+i));		
	}
}

