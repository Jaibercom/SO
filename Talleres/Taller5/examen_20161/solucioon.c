#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <stdlib.h>

#define PROCESS 3

sem_t *sem;
int *results;

int main(int argc, char *argv[]) {
  int i;
  int num1;
  int num2;
  pid_t pids[PROCESS];

  if (argc != 3) {
    printf("La ejecución debe ser: %s <numero_1> <numero_2>\n", argv[0]);
    exit(1);
  }

  num1 = atoi(argv[1]);
  num2 = atoi(argv[2]);

  sem = mmap(0, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  sem_init(sem, 1, 0);

  results = mmap(0, sizeof(int) * 2, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  for (i = 0; i < PROCESS; i++) {
    pids[i] = fork();

    if (pids[i] == -1) {
      puts("Error al crear el proceso.");
      exit(1);
    }

    if (pids[i] == 0) {
      switch(i) {
        case 0:
          printf("Proceso %d iniciado\n", i + 1);

          *(results + i) = sumDivisores(num1);
          sem_post(sem);

          printf("Proceso %d terminado\n", i + 1);

          break;
        case 1:
          printf("Proceso %d iniciado\n", i + 1);

          *(results + i) = sumDivisores(num2);
          sem_post(sem);

          printf("Proceso %d terminado\n", i + 1);

          break;
        case 2:
          printf("Proceso %d iniciado\n", i + 1);

          sem_wait(sem);
          sem_wait(sem);

          if (*(results + 0) == num2) {
            printf("El número %d es perfecto\n", num1);
          } else {
            printf("El número %d no es perfecto\n", num1);
          }

          if (*(results + 1) == num1) {
            printf("El número %d es perfecto\n", num2);
          } else {
            printf("El número %d no es perfecto\n", num2);
          }

          printf("Proceso %d terminado\n", i + 1);

          break;
      }

      exit(0);
    }
  }

  for (i = 0; i < PROCESS; i++) {
    wait(NULL);
  }

  return 0;
}

int sumDivisores(int num) {
  int i;
  int sum = 0;

  for (i = 1; i <= num / 2; i++) {
    if (num % i == 0) {
      sum += i;
    }
  }

  return sum;
}