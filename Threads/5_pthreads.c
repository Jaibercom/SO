/*
	Example: data spliting using Threads
	
	compile: gcc -Wall -o threads 5_pthreads.c -lpthread
	To execute: ./threads 1000 5
	
*/


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define NUMTHREADS 2

struct parameters{
	int down;
	int up;
};

//int sum = 0; /* this data is shared by the thread(s) */
void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
	pthread_t tid[NUMTHREADS]; /* the thread identifier */
	unsigned char cnt =0;
	int sum=0; 	
	
	int *response[NUMTHREADS];
	int value = 0;
	
	struct parameters params[NUMTHREADS];
	
	if (argc != 2){
		fprintf(stderr,"usage: %s <integer value>\n", argv[0]);
		return -1;
	}
	
	value = atoi(argv[1]);

	if ( value < NUMTHREADS ) {
		fprintf(stderr,"%d must be >= 0\n",value);
		return -1;
	}
	
	params[0].down = 1;
	params[0].up = value/2;
	params[1].down = (value/2)+1;
	params[1].up = value;

	/* create the thread */
	for(cnt=0; cnt < NUMTHREADS; cnt++){ 	
		pthread_create(&tid[cnt], NULL, runner, (void*)&params[cnt]);
	}
	/* wait for the thread to exit */
	for(cnt=0; cnt < NUMTHREADS; cnt++){
		pthread_join(tid[cnt], (void**) &response[cnt]);
		sum += *response[cnt];
	}	
	
	for(cnt=0; cnt < NUMTHREADS; cnt++){
		printf("Parcial result %d\n", *response[cnt]);
			
		//Memory free
		free(response[cnt]);
	}	
	
	printf("Total result = %d\n",sum);
	
	return EXIT_SUCCESS;
}

/* The thread will begin control in this function */
void *runner(void *param)
{
	int i =	0;
	struct parameters *ptr_params = (struct parameters *)param;
	int lower = ptr_params->down;
	int upper = ptr_params->up;
	int sum = 0;
	int *ptr = (void *) malloc(sizeof(int));
	
	printf("lower: %d     upper: %d \n",lower,upper);
	for (i = lower; i <= upper; i++)
		sum += i;
	
	*ptr = sum;	
		
	pthread_exit(ptr);
}
