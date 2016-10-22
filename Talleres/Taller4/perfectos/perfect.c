#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_CHARS_LINE 200

FILE *openFile(char *filename, char *mode); // Abre un archivo para escritura o lectura
int *readFile(FILE *file); // Lee y procesa un archivo
int *increaseNumbers(int *numbers); // Aumenta la memoria dinámica
int *lineProcess(char *line, int *numbers); // Procesa una línea del archivo

void *isPerfect(void *param); // Verifica si un número es perfecto

int count = 0;

int main(int argc, char *argv[]) {
  int i;
  int *result;
  int *numbers;
  FILE *file;
  pthread_t *tids;

  if (argc != 2) {
    puts("Error al ejecutar, debes hacerlo de la siguiente forma");
    printf("%s <archivo_entrada>\n", argv[0]);
    return 1;
  }

  file = openFile(argv[1], "r");

  // Leer los números del archivo
  numbers = readFile(file);

  // Reservar memoria para guardar el id de los hilos
  tids = malloc(sizeof(pthread_t) * count);

  // Crear todos los hilos
  for (i = 0; i < count; i++) {
    pthread_create((tids + i), NULL, isPerfect, (void *)(numbers + i));
  }

  // Esperar que todos los hilos terminen
  for (i = 0; i < count; i++) {
    pthread_join(*(tids + i), (void **)&result);

    // Verificar el resultado del hilo
    if (*result != 0) {
      printf("%d es un número perfecto\n", *(numbers + i));
    }

    // Liberar memoria del dato retornado por el hilo
    free(result);
  }

  // Liberar memoria de los números e hilos
  free(tids);
  free(numbers);

  // Cerrar archivos
  fclose(file);

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

int *readFile(FILE *file) {
  int *numbers = NULL;
  char line[MAX_CHARS_LINE];

  // Mientras se leen las lineas, se incrementa la memoria dinamica y se guardan los datos
  while (fgets(line, MAX_CHARS_LINE, file)) {
    numbers = lineProcess(line, numbers);
  }

  return numbers;
}

int *increaseNumbers(int *numbers) {
  count++;

  numbers = (int *)realloc(numbers, sizeof(int) * count);

  if (numbers == NULL) {
    puts("Error al incrementar la memoria.");
    exit(1);
  }

  return numbers;
}

int *lineProcess(char *line, int *numbers) {
  char *num;
  char sep[] = ";";

  num = strtok(line, sep);

  while(num != NULL) {
    numbers = increaseNumbers(numbers);

    *(numbers + count - 1) = atoi(num);

    num = strtok(NULL, ";");
  }

  return numbers;
}

void *isPerfect(void *param) {
  int i;
  int num = *((int *)param);
  int max = num / 2 + 1;
  int sum = 0;

  // Reservar memoria para retornar al programa principal
  int *ptr = (void *)malloc(sizeof(int));

  // Realizar la sumatoria desde 1 hasta n/2
  for (i = 1; i < max; i++) {
    if (num % i == 0) {
      sum += i;
    }
  }

  // Verificar si la sumatoria es igual al número inicial
  if (sum == num) {
    *ptr = sum;
  } else {
    *ptr = 0;
  }

  // Retornar dirección de memoria al programa principal
  pthread_exit(ptr);
}