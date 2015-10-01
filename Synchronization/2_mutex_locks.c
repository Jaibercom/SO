/*
	Example: implementing mutex locks with acquire() and release() functions
	compile: gcc 2_mutex_locks.c -o mutex_locks -lpthread
	To execute: ./mutex_locks
*/
#include <stdio.h>
#include <pthread.h>
#define NUMTHREADS 200
#define MAXCNT 1000
#define false 0
#define true 1

/* Global variables - shared between threads */
double counter = 0;
unsigned char available = true;

/* Declaring functions*/
void* counting(void *);
void acquire();
void release();
 
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
	
	acquire(); 
	
	for(i=0; i<MAXCNT; i++){
		
		counter++;	
	}
	release();
	
	return NULL;
}

/* Function acquire*/
void acquire() {
	while (!available); // busy wait 
	available = false;
}

/* Function release*/
void release() {
	available = true;
}
