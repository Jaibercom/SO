/*
 * Name         : taller2.c
 * Author       : Juangui Restrepo y Jaiber Yepes
 * Description  : Taller 2. Lista de trabajadores de EMPRENDOR.
 * Inportance   : Poner en practica los temas vistos para el
 *                segundo laboratorio (Archivos y Estructuras).
 * Compilation  : gcc -Wall taller2.c -o taller2
 * Execution    : ./taller2 trabajadores2.csv salida.txt
*/

/* Including headers or libraries. */
#include <stdio.h>      // printf, scanf, setbuf, fflush
#include <stdlib.h>     // malloc
#include <string.h>

/* Definition of macros and constants. */
#define MAX_CHARS_NAME 50
#define MAX_CHARS_LINE 20
#define EXTRA 20000

/* Definition of structures. */
typedef struct {
    char name[MAX_CHARS_NAME];
    float salary;
    int extras;
} employee;

/* Declaration of functions (prototypes). */
void getOption(char *_option);
int getNumEmployees(FILE *f);
void registerEmployees(employee *emp, FILE *f);
void showEmployees(employee *emp, FILE *f);
float getTotal(employee *emp);
int existEmployees();

/* Global variables. */
int numEmployees = 0;

/* Main function. */
int main(int argc, char *argv[]) {

    /* Local variables. */
    char option = 'x';
    int exitValue;
    char *fileName;
    FILE *employeeFile;
    char *fileName2;
    FILE *salida;
    employee *employees;
    float total = 0;

    // Validation: Number of arguments from console.
    if (argc != 3) {
        printf("Error: Numero de parametros invalido.\nDebe iniciar asi: ./taller.out <archivoEntrado.csv> <archivoSalida.csv>\n");
		exit(0);
    }
    
    fileName = argv[1];
    fileName2 = argv[2];
    
    employeeFile = fopen(fileName, "r");
    if(employeeFile == NULL) {
        printf("No se pudo abrir el archivo\n");
        exit(0);
    }
    
    salida = fopen(fileName2, "w+");
    if(employeeFile == NULL) {
        printf("No se pudo abrir el archivo\n");
        exit(0);
    }
    
    numEmployees = getNumEmployees(employeeFile);
    
    if (numEmployees <= 0) {
        printf("Error: No hay trabajadores en el archivo\n");
		exit(0);
    }
    
    printf("Hay %d trabajadores en el archivo\n", numEmployees);
    
    employees = (employee *)malloc(sizeof(employee) * numEmployees);

    do {
        getOption(&option);
        switch (option) {
            case 'a':
                registerEmployees(employees, employeeFile);
                break;
            case 'b':
					 showEmployees(employees, salida);
                break;
            case 'c':
					 total = getTotal(employees);
                     printf("TOTAL: %.2f", total);
                break;
            case 'q':
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("La opcion '%c' no es valida. Volviendo al menu.\n", option);
                break;
        }
    } while(option != 'q');
    
    exitValue = fclose(employeeFile);
    if(exitValue == 0) {
        printf("se cerro el archivo\n");
    }
    
    exitValue = fclose(salida);
    if(exitValue == 0) {
        printf("se cerro el archivo\n");
    }
    
    /* Free memory. */
    free(employees);


    return 0;
}

/* Implementation of functions. */

int getNumEmployees(FILE *f) {
    int num = 0;
    char buffer[MAX_CHARS_LINE];
    while(!feof(f)) {
        fgets(buffer, MAX_CHARS_LINE, f);
        num++;
    }
    rewind(f);
    return num - 1;
}

/* Punto 1 (20%): Mostrar un menu con las opciones disponibles. */
void getOption(char *_option) {
  printf("\nMENU DE OPCIONES\n");
  printf("\ta) Registrar trabajadores\n");
  printf("\tb) Ver lista de trabajadores\n");
  printf("\tc) Calcular nomina\n");
  printf("\tq) Salir del programa\n");
  printf("Seleccione una opcion: ");
  setbuf(stdin, NULL);
  scanf("\n%c", _option);
}

void registerEmployees(employee *emp, FILE *f) {
    /* Local variables. */
    int i = 0;
    char *token;
    char lines[MAX_CHARS_LINE];
    
    for (i = 0; i < numEmployees; i++) {
        fgets(lines, MAX_CHARS_LINE, f);
        token = strtok(lines, ";");
        while(token!=NULL) {
            strcpy((char *)emp->name,token);
            token = strtok(NULL, ";");
            emp->salary = atof(token);
            token = strtok(NULL, ";");
            emp->extras = atoi(token);
            token = strtok(NULL, ";");
        }
        emp++;
    }
}

/* Punto 3 (20%): Obtener el pago total. */
float getTotal(employee *emp) {

    /* Local variables. */
    int i = 0;
    float total = 0;

    for (i = 0; i < numEmployees; i++) {
        total += emp->salary + (EXTRA * emp->extras);
        emp++;
    }
    //printf("\nEl pago total es de: %.2f$\n", total);
	 return total;
}

/* Punto 4 (20%): Mostrar la lista. */
void showEmployees(employee *emp, FILE *f) {

    int i = 0;
    
	 printf("\nLa lista de trabajadores es:\n");	

    fprintf(f, "|%-12s|%-12s|%-12s|\n", "Nombre", "Salario", "Extras");
    for (i = 0; i < numEmployees; i++) {
        fprintf(f, "|%-12s|%-12.2f|%-12d|\n", emp->name, emp->salary, emp->extras);
        emp++;
    }

}
