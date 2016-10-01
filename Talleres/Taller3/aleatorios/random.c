#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define PROCESSES 10

unsigned int randomNumber();

int main(int argc, char *argv[]) {
  int i;
  int result;
  int results[PROCESSES];
  pid_t pids[PROCESSES];

  // Crear todos los procesos
  for (i = 0; i < PROCESSES; i++) {
    // Se crean n hijos
    pids[i] = fork();

    if (pids[i] == -1) {
      printf("Error creando un proceso hijo.\n");
      exit(1);
    // Los hijos generan el número aleatorio y lo retornan en el estado de salida
    } else if (pids[i] == 0) {
      exit(randomNumber());
    }
  }

  // Esperar que todos los procesos terminen
  for (i = 0; i < PROCESSES; i++) {
    // Se espera que termine un proceso determinado
    waitpid(pids[i], &result, 0);

    results[i] = WEXITSTATUS(result);
  }

  puts("");
  // Imprimir los números organizados de acuerdo a la ejecución
  for (i = 0; i < PROCESSES; i++) {
    printf("Proceso %d -> %d\n", pids[i], results[i]);
  }

  return 0;
}

unsigned int randomNumber() {
  unsigned int number;
  FILE *f;

  f = fopen("/dev/random", "r");

  fread(&number, sizeof(number), 1, f);

  fclose(f);

  number = number % 255;

  printf("Proceso hijo %d -> %d\n", (int) getpid(), number);

  return number;
}
