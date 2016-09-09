#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS_NAME 20

void menu(char *action);
//void addEmployees(char (*names)[MAX_CHARS_NAME], float *salaries, int *emp_count, int emp_max);
//void showEmployees();
float calculateAux(float salary, int percentage);

int main(int argc, char *argv[]) {
	int emp_max;
	int emp_count = 0;
	char action = 'x';
	int i;

	char (*names)[MAX_CHARS_NAME];
	float *salaries;

	/*if (argc != 2) {
		printf("Error, la ejecución del programa debe ser: %s <num_max_trabajadores>", argv[0]);
		return 1;
	}

	emp_max = atoi(argv[1]);
*/
	for(i=0; i<argc; i++){
		printf("%s\n", argv[i]);
	}


/*
  do {
    menu(&action);

    switch(action) {
      case 'a':
        
        break;
      case 'b':
        
        break;
      case 'c':
        
        break;
      case 'q':
        puts("Saliendo del programa...");
        break;
      default:
        puts("Opción no valida, intenta de nuevo.");
        break;
    }
  } while(action != 'q');
*/
  return 0;
}

void menu(char *action) {
  puts("MENÚ DE OPCIONES");
  printf("a) Registrar trabajadores\n");
  printf("b) Ver lista de trabajadores\n");
  printf("c) Ver nómina\nq) Salir del programa\nSeleccione una opción:");

  setbuf(stdin, NULL);
  scanf("\n%c", action);
}
/*
void addEmployees(char (*names)[MAX_CHARS_NAME], float *salaries, int *emp_count, int emp_max) {
  int n = 0;
  int i = 0;

  printf("Ingrese el número de empleados a registrar: ");

  setbuf(stdin, NULL);
  scanf("%d", &n);

  if (*emp_count + n > emp_max) {
    printf("El número de empreados a registrar sobrepasa la memoria.");
    return;
  }

  for (i = *emp_count; i < *emp_count + n; i++) {
   
  }

  *emp_count = *emp_count + n;
}
/*
void showEmployees(char (*names)[MAX_CHARS_NAME], float *salaries, int emp_count) {
  int i;

  printf("%-50s|%12s\n", "Nombre del trabajador", "Salario");

  for (i = 0; i < emp_count; i++) {
   
  }
}

void showPayroll(char (*names)[MAX_CHARS_NAME], float *salaries, int emp_count) {
  int i;
  float aux;
  float salary;
  float total = 0;
  float subtotal = 0;
  float percentage = 10;

  printf("%-50s|%10s|%12s|%12s\n", "Nombre del trabajador", "Salario", "Aux. Trans.", "Total");

  for (i = 0; i < emp_count; i++) {
    
  }

  printf("%75s%12.2f\n", "total", total);
}

float calculateAux(float salary, int percentage) {
  return (salary * percentage / 100);
}*/
