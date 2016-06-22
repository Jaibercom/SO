/*
	Example: Threads, returning arguments to a thread
	
	Some utils functions:
	void pthread_exit(void *retval);
	int pthread_join(pthread_t thread, void **retval);
	
	compile: gcc -Wall -o threads 3a_pthreads.c -lpthread
	To execute: ./threads 5 
	
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; 	/* this data is shared by the thread(s) */
void *runner(void *param); 	/* threads call this function */

int main(int argc, char *argv[])
{
	pthread_t tid; /* the thread identifier */
	int *response[1];
	int val = 0;
	//int answer=0;
	
	if (argc != 2){
		fprintf(stderr,"usage: a.out <integer value>\n");
		return -1;
	}

	val = atoi(argv[1]);	

	if (val < 5 ) {
		fprintf(stderr,"%d must be >= 5\n",val);
		return -1;
	}
	
	/* create the thread */
	pthread_create(&tid, NULL, runner, (void*)&val);
	/* wait for the thread to exit */
	pthread_join(tid, (void**)response);
	//pthread_join(tid, (void**)&answer);

	printf("result = %d\n", *response[0]);	
	//printf("result = %d\n", answer);
	printf("sum = %d\n", sum);
	free(response[0]);
	return EXIT_SUCCESS; 
}

/* The thread will begin control in this function */
void *runner(void *param)
{
	int i;
	int upper = *((int *)param);
	int sum = 0;
	int *ptr = malloc(sizeof(int));
	
	for (i = 1; i <= upper; i++)
		sum += i;
		
	*ptr = sum;	
		
	pthread_exit(ptr);
	//pthread_exit((void*)sum);
	//return (void*)sum;
}
