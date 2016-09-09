#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS_NAME 50

void menu(char *action);
void addEmployees(char (*names)[MAX_CHARS_NAME], float *salaries, int *emp_count, int emp_max);
void showEmployees(char (*names)[MAX_CHARS_NAME], float *salaries, int emp_count);
void showPayroll(char (*names)[MAX_CHARS_NAME], float *salaries, int emp_count);
float calculateAux(float salary, int percentage);

int main(int argc, char *argv[]) {
  int emp_max;
  int emp_count = 0;
  char action = 'x';

  char (*names)[MAX_CHARS_NAME];
  float *salaries;

  if (argc != 2) {
    printf("Error, la ejecución del programa debe ser: %s <num_max_trabajadores>", argv[0]);
    return 1;
  }

  emp_max = atoi(argv[1]);

  names = (char (*)[MAX_CHARS_NAME]) malloc(sizeof(char [MAX_CHARS_NAME]) * emp_max);
  salaries = (float *) malloc(sizeof(float) * emp_max);

  do {
    menu(&action);

    switch(action) {
      case 'a':
        addEmployees(names, salaries, &emp_count, emp_max);
        break;
      case 'b':
        showEmployees(names, salaries, emp_count);
        break;
      case 'c':
        showPayroll(names, salaries, emp_count);
        break;
      case 'q':
        puts("Saliendo del programa...");
        break;
      default:
        puts("Opción no valida, intenta de nuevo.");
        break;
    }
  } while(action != 'q');

  free(names);
  free(salaries);

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
    puts("Ingrese el nombre:");
    setbuf(stdin, NULL);
    scanf("%s", (char *)(names + i));

    puts("Ingrese el salario:");
    setbuf(stdin, NULL);
    scanf("%f", (salaries + i));
  }

  *emp_count = *emp_count + n;
}

void showEmployees(char (*names)[MAX_CHARS_NAME], float *salaries, int emp_count) {
  int i;

  printf("%-50s|%12s\n", "Nombre del trabajador", "Salario");

  for (i = 0; i < emp_count; i++) {
    printf("%-50s|%12.2f\n", *(names + i), *(salaries + i));
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
    salary = *(salaries + i);

    aux = calculateAux(salary, percentage);

    subtotal = aux + salary;

    printf("%-50s|%10.2f|%12.2f|%12.2f\n", *(names + i), salary, aux, subtotal);

    total = total + subtotal;
  }

  printf("%75s%12.2f\n", "total", total);
}

float calculateAux(float salary, int percentage) {
  return (salary * percentage / 100);
}
