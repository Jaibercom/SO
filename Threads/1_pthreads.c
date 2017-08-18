/*
	Example: Creating threads
	compile: gcc -o threads 1_pthreads.c -lpthread
	To execute: ./threads
*/

#include <pthread.h>
#include <stdio.h>

int sum; /* this data is shared by the thread(s) */
void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
	pthread_t tid[2]; /* the thread identifier */
	
/*
int pthread_create(	pthread_t *thread, 
					const pthread_attr_t *attr,
                    void *(*start_routine) (void *), 
					void *arg);

int pthread_join(pthread_t thread, void **retval);

*/
	/* create the thread */
	pthread_create(&tid[0], NULL, runner, NULL);

	/* wait for the thread to exit */
	pthread_join(tid[0], NULL);

	printf("sum = %d\n",sum);
	return 0;
	
}

/* The thread will begin control in this function */
void *runner(void *unused)
{
	int i, upper = 4;
	sum = 0;
	for (i = 1; i <= upper; i++)
		sum += i;
		
	pthread_exit(0);
}
