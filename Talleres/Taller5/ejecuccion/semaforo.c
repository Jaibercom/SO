#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/mman.h>

void *hilo1(void *param);
void *hilo2(void *param);
void *hilo3(void *param);

sem_t sem1;
sem_t sem2;

int main() {
  int i;
  pthread_t pids[3];

  sem_init(&sem1, 0, 0);
  sem_init(&sem2, 0, 0);

  pthread_create(&pids[2], 0, hilo3, (void *) NULL);
  pthread_create(&pids[1], 0, hilo2, (void *) NULL);
  pthread_create(&pids[0], 0, hilo1, (void *) NULL);

  for (i = 0; i < 3; i++) {
    pthread_join(pids[i], NULL);
  }

  sem_destroy(&sem1);
  sem_destroy(&sem2);

  return 0;
}

void *hilo1(void *param) {
  sleep(1);

  puts("Hilo 1 termino.");

  sem_post(&sem1);

  pthread_exit(0);
}

void *hilo2(void *param) {
  sem_wait(&sem1);

  sleep(1);

  puts("hilo 2 termino.");

  sem_post(&sem2);

  pthread_exit(0);
}

void *hilo3(void *param) {
  sem_wait(&sem2);

  sleep(1);

  puts("hilo 3 termino.");

  pthread_exit(0);
}
