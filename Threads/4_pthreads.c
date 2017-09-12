/*
	Example: Creating several threads, each thread is able to sum a independient value
	compile: gcc -o threads 4_pthreads.c -lpthread
	To execute: ./threads
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> 

#define MAX 100

int sum; /* this data is shared by the thread(s) */
void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
	int i;
	int numThreads;
	int value[MAX];
	pthread_t tid[MAX]; /* the thread identifier */
	int *answer[MAX];

	printf("Cuantos hilos desea crear:  (Max %d) ", MAX);
	scanf("%d", &numThreads);

	if (numThreads > MAX ) {
		fprintf(stderr,"Numero de hilos debe ser <= %d\n", MAX);
		return -1;
	}
	
	for(i=0; i<numThreads; i++){
		printf("Ingrese el valor para el hilo %d: ", i+1);
		scanf("%d", &value[i]);
	}

	//Creating threads
	for(i=0; i<numThreads; i++)
	{
		pthread_create(&tid[i], NULL, runner, (void *)&value[i]);
	}
	
	//Waiting for the threads
	for(i=0; i<numThreads; i++)
	{
		pthread_join(tid[i], (void **)&answer[i]);
		printf("sum[%d] = %d\n", i+1, *answer[i]);
	
		//Memory free 
		free(answer[i]);
	}	

	return 0;
}

/* The thread will begin control in this function */
void *runner(void *param)
{
	int i;
	int up = *((int *)param);

	int *ptr_sum = (void *) malloc(sizeof(int));	

	for (i = 1; i <= up; i++)
		*ptr_sum += i;
		
	pthread_exit(ptr_sum);
}
