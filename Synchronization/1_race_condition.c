/*
	Example: race condition
	compile: gcc 1_race_condition.c -o race_condition -lpthread
	To execute: ./raceCondition
*/

#include <stdio.h>
#include <pthread.h>
#define NUMTHREADS 200
#define MAXCNT 1000

/* Global variables - shared between threads */
double counter = 0;
/* Declaring functions*/
void* counting(void *);
 
int main(void) {
	pthread_t tid[NUMTHREADS];
	int i=0;
	
	for( i=0; i<NUMTHREADS; i++){
 		pthread_create (&tid[i], NULL, &counting, NULL);
 	}
 	
	for( i=0; i< NUMTHREADS; i++){
		pthread_join(tid[i], NULL);
	}
	
	printf("\nCounter must be in: %d\n", MAXCNT*NUMTHREADS);
	printf("\nCounter value is: %.0f\n\n", counter);

	return 0;
}

/* Function Thread*/
void* counting(void * unused) {
	int i=0;
	for(i=0; i<MAXCNT; i++)
 		counter++;

	return NULL;
}
