#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <semaphore.h>

#define MAX 10

sem_t *sem;

int main() {
  pid_t pids[2];

  sem = mmap(0, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  sem_init(sem, 1, 0);

  pids[0] = fork();

  if (pids[0] == 0) {
    int i;

    for (i = 0; i < MAX; i++) {
      puts("Incrementando el semáforo.");
      sem_post(sem);
      sleep(1);
    }

    exit(0);
  }

  pids[1] = fork();

  if (pids[1] == 0) {
    int cnt = 0;

    while(cnt < MAX) {
      sem_wait(sem);

      cnt++;

      printf("El semáforo aumentó %d\n", cnt);
    }

    exit(0);
  }

  wait(NULL);
  wait(NULL);

  sem_destroy(sem);
  munmap(0, sizeof(sem_t));

  return 0;
}
