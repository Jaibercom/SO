/*
 * Name         : factory.c
 * Author       : Juangui Restrepo y Jaiber Yepes
 * Description  : Taller 2. Lista de trabajadores de EMPRENDOR.
 * Inportance   : Poner en practica los temas: estructuras y ficheros
 * Compilation  : gcc -Wall factory.c -o factory
 * Execution    : ./factory <file>

 Example file:
	Jose
	1000
	2
	Pedro
	2000
	5
	Pepito
	2500
	3
*/

/* Including headers or libraries. */
#include <stdio.h>      // printf, scanf, setbuf, fflush
#include <stdlib.h>     // malloc

/* Definition of macros and constants. */
#define MAX_CHARS_NAME 20
#define MAX_CHARS_LINE 100

struct employe{
	char name[MAX_CHARS_NAME];
    float salary;
	int h_extras;
};

typedef struct{
	char name[MAX_CHARS_NAME];
    float salary;
}str_employe;

/* Declaration of functions (prototypes). */
void getOption(char *_option);
void registerEmployees(struct employe *_employes);
void registerEmployeesFile(struct employe *_employes, FILE *file);
void showEmployees(struct employe *_employes);
//float getTotal(float *_salaries)
int existEmployees();
int getNumEmployees(FILE *f) ;

/* Global variables. */
int max_employees = 20;
int num_employees = 0;

//struct employe employe1;
//str_employe empl2;
 
/* Main function. */
int main(int argc, char *argv[]) {

    /* Local variables. */
    char option = 'x';
    //char (*names)[MAX_CHARS_NAME];
    //float *salaries;
    //float total = 0;
	//struct employe employes[max_employees];
	struct employe *employes;
	char *fileName;
	FILE *file;

    // Validation: Number of arguments from console.
    if (argc != 2) {
        printf("Error: Numero de parametros invalido.\nDebe iniciar asi: %s <archivo con trabajadores>\n", argv[0]);
		exit(0);
    }
	
	fileName = argv[1];
	file = fopen(fileName, "r");
	if(file == NULL) {
        printf("No se pudo abrir el archivo\n");
        exit(0);
    }

    // Validation: Argument is a positive integer.
    if(max_employees <= 0){
        printf("Error: Parametro invalido.\nDebe iniciar asi: ./taller.out <numero maximo de trabajadores>\n");
        exit(0);
    }

	max_employees = getNumEmployees(file);

    printf("La lista tendra una capacidad maxima de %d trabajadores.\n", max_employees);

    /* Get free space in memory. */
    //names = (char (*)[MAX_CHARS_NAME]) malloc(sizeof(char[MAX_CHARS_NAME]) * max_employees);
    //salaries = (float *) malloc(sizeof(float) * max_employees);
	employes = (struct employe *) malloc(sizeof(struct employe)*max_employees);
		
    do {
        getOption(&option);
        switch (option) {
            case 'a':
                //registerEmployees(employes);
				registerEmployeesFile(employes, file);
                break;
            case 'b':
				showEmployees(employes);
                break;
            case 'q':
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("La opcion '%c' no es valida. Volviendo al menu.\n", option);
                break;
        }
    } while(option != 'q');

    /* Free resources */
    free(employes);
	fclose(file);

    return 0;
}

/*  Functions implementation. */

/* Punto 1 (20%): Mostrar un menu con las opciones disponibles. */
void getOption(char *_option) {
  printf("\nMENU DE OPCIONES\n");
  printf("\ta) Registrar trabajadores\n");
  printf("\tb) Ver lista de trabajadores\n");
  printf("\tq) Salir del programa\n");
  printf("Seleccione una opcion: ");
  setbuf(stdin, NULL);
  scanf("\n%c", _option);
}

/* Punto 2 (40%): Registrar a los trabajadores. */
//void registerEmployees(char (*_names)[MAX_CHARS_NAME], float *_salaries) {
void registerEmployees(struct employe *_employes) {

    // Local variables. 
    int i = 0;
    int num_new_employees = 0;

    printf("Ingrese el numero de trabajadores a registrar: ");
    setbuf(stdin, NULL);
    scanf("%d", &num_new_employees);

    if (num_employees + num_new_employees > max_employees) {
        printf("No es posible registrar %d trabajadores.\n", num_new_employees);
        printf("La capacidad maxima es %d y actualmente estan registrados %d.\n", max_employees, num_employees);
        return;
    }

    for (i = num_employees; i < num_employees + num_new_employees; i++) {

		/* Get information of new employee. */
        printf("\nNombre del empleado #%d: ", i + 1);
        setbuf(stdin, NULL);
		//scanf("%s", _employes[i].name );
		scanf("%s", &(_employes+i)->name[0] );
        //scanf("%s", (char *)(_names+i));
        printf("Salario: ");
        setbuf(stdin, NULL);
		scanf("%f", &(_employes+i)->salary);
        //scanf("%f", _salaries+i);

		printf("Horas extras: ");
        setbuf(stdin, NULL);
		scanf("%d", &(_employes+i)->h_extras);

    }
    num_employees += num_new_employees;
    printf("\nSe han registrado %d trabajadores en la lista.\n", num_new_employees);

}

void registerEmployeesFile(struct employe *_employes, FILE *file) {

    // Local variables. 
    int i = 0;
    int num_new_employees = 0;

    for (i = 0; i < 3; i++) {

		/* Get information of new employee. */

		fscanf(file, "%s", (_employes+i)->name );

		fscanf(file, "%f", &(_employes+i)->salary);
  
		fscanf(file, "%d", &(_employes+i)->h_extras);

		num_employees++;

    }
    //num_employees += num_new_employees;
    printf("\nSe han registrado %d trabajadores en la lista.\n", num_employees);
}

/* Punto 3 (20%): Obtener el pago total. */
/*float getTotal(float *_salaries) {

    // Local variables. 
    int i = 0;
	 float total = 0;

    if (!existEmployees()) {
        printf("No se puede calcular el total porque no se han registrado trabajadores.\n");
        return 0;
    }

    for (i = 0; i < num_employees; i++) {
        total += *(_salaries+i);
    }
    //printf("\nEl pago total es de: %.2f$\n", total);
	 return total;
}*/

/* Punto 4 (20%): Mostrar la lista. */
void showEmployees(struct employe *_employes) {

    // Local variables. 
    int i = 0;

    if (!existEmployees()) {
        printf("No hay trabajadores para mostrar.\n");
        return;
    }
	printf("\nLa lista de trabajadores es:\n");	

    printf("|%-12s|%-12s|%-12s|\n", "Nombre", "Salario", "Extras");
    for (i = 0; i < num_employees; i++) {
        //printf("|%-12s|%-12.2f|\n", *(_names+i), *(_salaries+i));
		printf("|%-12s|%-12.2f|%-12d|\n", _employes->name, _employes->salary, _employes->h_extras);
		_employes++;
    }

	 //printf("|%12s|%-12.2f|\n", "Total ", getTotal(_salaries));

}

int existEmployees() {
    if (num_employees) {
        return 1;
    }
    return 0;
}


int getNumEmployees(FILE *f) {
    int num = 0;
    char buffer[MAX_CHARS_LINE];
    while(!feof(f)) {
        fgets(buffer, MAX_CHARS_LINE, f);
        num++;
    }
    rewind(f);
    return num/3;
}
