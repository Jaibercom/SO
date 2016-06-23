// gcc taller4.c -o exe -lpthread
// ./exe 3 5 10

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct{
	int k;		//num k
	int n;		//Hasta n
}str_params;

void *sumkn(void* param) {
	str_params str_p = *((str_params *) param);
	int *result = (int *)malloc(sizeof(int));
	int x;
	x = (str_p.n - 1)/str_p.k;
	*result = str_p.k*x*(x+1)/2;	
	pthread_exit((void *)result);
}

int main (int argc, char* argv[]) {
	int num[3];
	int lim;
	int i;
	pthread_t id[3];
	str_params param[3];
	int *response[3];
	int result = 0;
	
	if(argc != 4){
		fprintf(stderr,"El programa se debe ejecutar asi: %s <num1> <num2> <limite>\n", argv[0]);
		exit(0);
	}
	
	num[0] = atoi(argv[1]);
	num[1] = atoi(argv[2]);
	num[2] = num[0]*num[1];
	lim = atoi(argv[3]);

	for(i=0; i<3; i++){
		param[i].k = num[i];
		param[i].n = lim;
		pthread_create (&id[i], NULL, sumkn, (void *)&param[i]);		
	}
	
	for(i=0; i<3; i++){
		pthread_join(id[i],(void**)&response[i]);
		printf ("resultado parcial %d: %d\n", i+1, *response[i]);	
	}
	
	result = *response[0] + *response[1] - *response[2];
	printf ("\nresultado total = %d\n", result);
	
	return 0;
}
