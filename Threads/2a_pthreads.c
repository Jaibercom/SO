/*
	Example: Threads, passing arguments to a thread
	compile: gcc -Wall -o threads 2_pthreads.c -lpthread
	To execute: ./threads 5 
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct str_params{
	int value;
	char msg[20];
};

int sum; /* this data is shared by the thread(s) */
void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
	pthread_t tid; /* the thread identifier */
	struct str_params param;

	printf("Ingrese un valor para el limite de la suma: \n");
	scanf("%d", &param.value);
	
	printf("Ingrese un mensaje: \n");
	scanf("%s", &param.msg[0]);
	
	/* create the thread */
	pthread_create(&tid, NULL, runner, (void *)&param);
	/* wait for the thread to exit */
	pthread_join(tid, NULL);
	
	printf("sum = %d\n",sum);
	
	return EXIT_SUCCESS;
	
}

/* The thread will begin control in this function */
void *runner(void *param)
{
	int i;
	struct str_params *ptr = (struct str_params *)param;
	sum = 0;

	printf("El mensaje es: %s\n", ptr->msg);	

	for (i = 1; i <= ptr->value; i++)
		sum += i;
		
	pthread_exit(0);
}
