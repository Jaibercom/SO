#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/mman.h>

void *hilo1(void *param);
void *hilo2(void *param);
void *hilo3(void *param);

// Variable en memoria compartida que guarda el último hilo ejecutado
int *hilo;

int main() {
  int i;
  pthread_t pids[3];

  // Mapear memoria compartida
  hilo = mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  pthread_create(&pids[2], 0, hilo3, NULL);
  pthread_create(&pids[1], 0, hilo2, NULL);
  pthread_create(&pids[0], 0, hilo1, NULL);

  for (i = 0; i < 3; i++) {
    pthread_join(pids[i], NULL);
  }

  // Liberar memoria compartida
  munmap(0, sizeof(int));

  return 0;
}

void *hilo1(void *param) {
  sleep(1);

  puts("Hilo 1 termino.");

  *hilo = 1;

  pthread_exit(0);
}

void *hilo2(void *param) {
  while(*hilo != 1) {}

  sleep(1);

  puts("hilo 2 termino.");

  *hilo = 2;

  pthread_exit(0);
}

void *hilo3(void *param) {
  while(*hilo != 2) {}

  sleep(1);

  puts("hilo 3 termino.");

  pthread_exit(0);
}
