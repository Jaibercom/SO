/*
	Example: synchronizing exercise using semaphores.
	s1 run before than s2.
	Modify the program in order to S3 run before S1
	compile: gcc 5_sync.c -o sync -lpthread
	To execute: ./sync
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define NUMTHREADS 3

sem_t synch;

void *s1(void *arg);
void *s2(void *arg);
void *s3(void *arg);

int main(){
	int i;
	pthread_t tid[NUMTHREADS];
	
	sem_init(&synch,0,0);
	
	pthread_create(&tid[0],NULL,&s1,NULL);
	pthread_create(&tid[1],NULL,&s2,NULL);
	pthread_create(&tid[2],NULL,&s3,NULL);
	
	for( i=0; i< NUMTHREADS; i++){
		pthread_join(tid[i], NULL);
	}
	
	
	sem_destroy(&synch);

	printf("\nDone !!\n");
	return 0;
}

void *s1(void *arg){
	
	printf("\nExecuting S1..\n");
	sem_post(&synch);
	return 0;
}

void *s2(void *arg){
	
	sem_wait(&synch);
	printf("\nExecuting S2..\n");

	return 0;
}

void *s3(void *arg){
	
	printf("\nExecuting S3..\n");
	return 0;
}

