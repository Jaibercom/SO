/*
	Example: Threads, passing arguments to a thread
	compile: gcc -Wall -o threads 2_pthreads.c -lpthread
	To execute: ./threads 5 
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; /* this data is shared by the thread(s) */
void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
	pthread_t tid; /* the thread identifier */
	int value = 0;
	
	if (argc != 2){
		fprintf(stderr,"usage: a.out <integer value>\n");
		return -1;
	}
	
	if (atoi(argv[1]) < 0) {
		fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
		return -1;
	}
	
	value = atoi(argv[1]);
	
	/* create the thread */
	pthread_create(&tid, NULL, runner, (void *)&value);
	/* wait for the thread to exit */
	pthread_join(tid, NULL);
	
	printf("sum = %d\n",sum);
	
	return EXIT_SUCCESS;
	
}

/* The thread will begin control in this function */
void *runner(void *param)
{
	int i, upper = *((int *)param);
	sum = 0;
	for (i = 1; i <= upper; i++)
		sum += i;
		
	pthread_exit(0);
}
