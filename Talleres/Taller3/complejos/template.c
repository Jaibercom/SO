#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX 50

typedef struct {
  signed int real;
  signed int imaginary;
} ComplexNumber;

FILE *openFile(char *filename, char *mode);
ComplexNumber *readFile(FILE *file);
ComplexNumber *increaseNumbers(ComplexNumber *numbers);
void lineProcess(char *line, ComplexNumber *complex);
void printNumbers(ComplexNumber *num1, ComplexNumber *num2);

ComplexNumber add(ComplexNumber num1, ComplexNumber num2);
ComplexNumber subtract(ComplexNumber num1, ComplexNumber num2);
ComplexNumber multiply(ComplexNumber num1, ComplexNumber num2);

int count = 0;

int main(int argc, char *argv[]) {
  int i;
  FILE *input;
  ComplexNumber *numbers;

  if (argc != 2) {
    printf("Error: Número de parametros invalidos.\n");
    printf("Debe iniciar así: %s <archivo_entrada.csv>\n", argv[0]);
    exit(1);
  }

  input = openFile(argv[1], "r");

  numbers = readFile(input);

  for (i = 0; i < count; i = i + 2) {
    printNumbers(numbers + i, numbers + i + 1);
  }

  fclose(input);
  free(numbers);

  return 0;
}

FILE *openFile(char *filename, char *mode) {
  FILE *file;

  file = fopen(filename, mode);

  // Validar si el archivo fue abierto
  if (!file) {
    printf("Error al abrir el archivo: %s\n", filename);
    exit(1);
  }

  return file;
}

ComplexNumber *readFile(FILE *file) {
  ComplexNumber *numbers = NULL;
  char line[MAX];

  // Mientras se leen las lineas, se incrementa la memoria dinamica y se guardan los datos
  while (fgets(line, MAX, file)) {
    numbers = increaseNumbers(numbers);

    lineProcess(line, (numbers + count - 1));
  }

  return numbers;
}

ComplexNumber *increaseNumbers(ComplexNumber *numbers) {
  count++;

  numbers = (ComplexNumber *)realloc(numbers, sizeof(ComplexNumber) * count);

  if (numbers == NULL) {
    puts("Error al incrementar la memoria.");
    exit(1);
  }

  return numbers;
}

void lineProcess(char *line, ComplexNumber *number) {
  char *pch;
  char sep[] = ";";

  pch = strtok(line, sep);
  number->real = *pch;

  pch = strtok(NULL, sep);
  number->imaginary = *pch;
}

void printNumbers(ComplexNumber *num1, ComplexNumber *num2) {
  ComplexNumber res;

  res = add(*num1, *num2);
  printf("PID %d -> Suma: %d, %di\n", (int)getpid(), res.real, res.imaginary);

  // Realizar una pausa para observar el paralelismo
  sleep(1);

  res = subtract(*num1, *num2);
  printf("PID %d -> Resta: %d, %di\n", (int)getpid(), res.real, res.imaginary);

  res = multiply(*num1, *num2);
  printf("PID %d -> Multiplicación: %d, %di\n", (int)getpid(), res.real, res.imaginary);
}

ComplexNumber add(ComplexNumber num1, ComplexNumber num2) {
  ComplexNumber number;

  number.real = num1.real + num2.real;
  number.imaginary = num1.imaginary + num2.imaginary;

  return number;
}

ComplexNumber subtract(ComplexNumber num1, ComplexNumber num2) {
  ComplexNumber number;

  number.real = num1.real - num2.real;
  number.imaginary = num1.imaginary - num2.imaginary;

  return number;
}

ComplexNumber multiply(ComplexNumber num1, ComplexNumber num2) {
  ComplexNumber number;

  number.real = (num1.real * num2.real) - (num1.imaginary * num2.imaginary);
  number.imaginary = (num1.real * num2.imaginary) + (num1.imaginary * num2.real);

  return number;
}
