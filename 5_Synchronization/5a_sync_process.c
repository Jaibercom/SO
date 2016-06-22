/*
	Example: synchronizing PROCESS exercise using semaphores.
	In this exercise the process s1 run before than s2,
	modify the program in order to S3 run after S2
	
	compile: gcc 5a_sync_process.c -o sync -lpthread 
	To execute: ./sync

*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define NUMHIJOS 3

sem_t *sem1;

void s1();
void s2();
void s3();

int main(){
	int i;
	pid_t pid[NUMHIJOS];
	int val= 0;
	int	pid_hijo =0;

	sem1 = mmap(0, sizeof(sem_t), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);

	sem_init(sem1,1,0); //direccion de la variable, 0->hilos y diferente de 0->procesos, valor de inicializacion del semaforo.

	for (i = 0; i < NUMHIJOS; i++) {
		pid[i] = fork();//Crea los procesos y los guarda en un arreglo

		if (pid[i] == -1) {
			/* Verificacion de Error */
			printf("No fue posible crear un hijo\n");
			return -1;
		}

		if (pid[i] == 0) {
			//printf("\nSoy un proceso hijo con PID: %d!\n", getpid());
			  switch (i){
				case 0:
					s3();
				break;

				case 1:
					s2();
				break;

				case 2: 
					s1();
				break;  	 
			  }
			printf("El proceso hijo con PID %d ha terminado!\n", getpid()); 
			exit(0);
		}
	}

	for (i = 0; i < NUMHIJOS; i++) {	
		wait(&val);
	}

	sem_destroy(sem1);

	printf("\nEl padre termino !!\n"); //mensaje al final
	return 0;
}

void s1(){
	printf("\nS1 Executing...\n");
	sem_post(sem1);
}

void s2(){
	sem_wait(sem1);//ejecuta primero el S1
	printf("\nS2 Executing...\n");
}

void s3(){
	printf("\nS3 Executing...\n");
}
