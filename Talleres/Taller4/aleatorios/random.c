#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 10

void *randomNumber(); // Genera un número aleatorio

int main(int argc, char *argv[]) {
  int i;
  int *results[THREADS];
  pthread_t ids[THREADS];

  // Crear todos los hilos
  for (i = 0; i < THREADS; i++) {
    pthread_create(&ids[i], NULL, randomNumber, &i);
  }

  // Esperar que todos los hilos terminen
  for (i = 0; i < THREADS; i++) {
    // Se espera que termine un hilo determinado
    pthread_join(ids[i], (void **)&results[i]);
  }

  puts("");

  // Imprimir los números organizados de acuerdo a la ejecución
  for (i = 0; i < THREADS; i++) {
    printf("Hilo %d -> %d\n", (int)ids[i], *results[i]);

    // Liberar la memoria dínamica reservada en el hilo
    free(results[i]);
  }

  return 0;
}

void *randomNumber() {
  unsigned int num;
  // Reservar memoria dínamica para retornar al programa principal
  int *number = malloc(sizeof(int));

  FILE *f;

  f = fopen("/dev/random", "r");

  fread(&num, sizeof(num), 1, f);

  fclose(f);

  *number = num % 1000;

  printf("Hilo %d -> %d\n", (int)pthread_self(), *number);

  // Retornar dirección de memoria dínamica
  pthread_exit(number);
}
