/*
	Example: Creating threads
	compile: gcc -o threads 1_threads.c -lpthread
	To execute: .
*/

#include <pthread.h>
#include <stdio.h>

int sum; /* this data is shared by the thread(s) */
void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
	pthread_t tid; /* the thread identifier */
	
	/* create the thread */
	pthread_create(&tid, NULL, runner, argv[1]);
	/* wait for the thread to exit */
	pthread_join(tid,NULL);
	
	printf("sum = %d\n",sum);
	
}

/* The thread will begin control in this function */
void *runner(void *unused)
{
	int i, upper = 10;
	sum = 0;
	for (i = 1; i <= upper; i++)
		sum += i;
		
	pthread_exit(0);
}
