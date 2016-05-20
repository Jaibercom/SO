/*
	Example: Creating several threads
	compile: gcc -o threads 5_threads.c -lpthread
	To execute: ./threads
*/

#include <pthread.h>
#include <stdio.h>

int sum; /* this data is shared by the thread(s) */
void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
	pthread_t tid[10]; /* the thread identifier */
	int value[10];
	int numThreads;
	int i;
	int answer;

	printf("Cuantos hilos desea crear:  (Max 10)");
	scanf("%d", &numThreads);
	
	for(i=0; i<numThreads; i++){
		printf("Ingrese el valor upper del hilo %d: ", i+1);
		scanf("%d", &value[i]);
	}

	for(i=0; i<numThreads; i++){
		/* create the thread */
		pthread_create(&tid[i], NULL, runner, (void *)&value[i]);

	}	

	for(i=0; i<numThreads; i++){
		/* wait for the thread to exit */
		pthread_join(tid[i], (void **)&answer);
		printf("sum = %d\n",answer);
	}	
	
	//printf("sum = %d\n",sum);
	return 0;
	
}

/* The thread will begin control in this function */
void *runner(void *param)
{
	int i;
	//int *upper = (int *)param;
	int up = *((int *)param);
	int sum = 0;

	for (i = 1; i <= up; i++)
		sum += i;
		
	//printf("sum = %d\n",sum);

	pthread_exit((void *)sum);
}
