#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 10

void *aumentar(void *param);
void *esperar(void *param);

sem_t sem;

int main() {
  int i;
  pthread_t pids[2];

  sem_init(&sem, 0, 0);

  pthread_create(&pids[0], 0, esperar, (void *) NULL);
  pthread_create(&pids[1], 0, aumentar, (void *) NULL);

  for (i = 0; i < 2; i++) {
    pthread_join(pids[i], NULL);
  }

  sem_destroy(&sem);

  return 0;
}

void *aumentar(void *param) {
  int i;

  for (i = 0; i < MAX; i++) {
    puts("Incrementando el semáforo.");
    sem_post(&sem);
    sleep(1);
  }

  pthread_exit(0);
}

void *esperar(void *param) {
  int cnt = 0;

  while(cnt < MAX) {
    sem_wait(&sem);

    cnt++;

    printf("El semáforo aumentó %d\n", cnt);
  }

  pthread_exit(0);
}