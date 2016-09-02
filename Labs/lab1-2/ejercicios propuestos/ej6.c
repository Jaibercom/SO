/*
 * Name         : ejercicio6.c
 * Author       : Santiago Osorio
 * Description  : Ejercicio propuesto 6. Calculadora de 2 variables.
 * Compilation  : gcc -Wall ejercicio6.c -o ejercicio6
 * Execution    : ./ejercicio6
*/

#include <stdio.h>

/* Declaration of functions (prototypes). */
char menu();
void result(float result);
void values(float *val1, float *val2);

/* Main function. */
int main(int argc, char *argv[]) {

  /* Local variables. */
  char option;
  float val1 = 0;
  float val2 = 0;

  do {
    option = menu();

    switch (option) {
      case '1':
        values(&val1, &val2);
        result(val1 + val2);
        break;
      case '2':
        values(&val1, &val2);
        result(val1 - val2);
        break;
      case '3':
        values(&val1, &val2);
        result(val1 * val2);
        break;
      case '4':
        values(&val1, &val2);
        if (val2 == 0) {
          printf("No es posible realizar una división por 0.\n");
        } else {
          result(val1 / val2);
        }

        break;
      case 'q':
        printf("Saliendo del programa...\n");
        break;
      default:
        printf("La opcion '%c' no es valida. Volviendo al menu.\n", option);
        break;
    }
  } while(option != 'q');

  return 0;
}

/* Implementation of functions. */

char menu() {
  char action = 'x';

  printf("MENU DE OPCIONES\n");
  printf("1) Suma\n");
  printf("2) Resta\n");
  printf("3) Multiplicación\n");
  printf("4) División\n");
  printf("q) Salir del programa\n");
  printf("Seleccione una opcion: \n");

  setbuf(stdin, NULL);
  scanf("\n%c", &action);
  setbuf(stdin, NULL);

  return action;
}


void result(float result) {
  printf("El resultado de la operación es %0.4f\n", result);
}

void values(float *val1, float *val2) {
  printf("Ingrese el numero 1: \n");
  setbuf(stdin, NULL);
  scanf("%f", val1);

  printf("Ingrese el numero 2: \n");
  setbuf(stdin, NULL);
  scanf("%f", val2);
}
