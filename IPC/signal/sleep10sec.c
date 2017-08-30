#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

/* duerme 10 segundos y luego mide el tiempo*/
time_t tini;
time_t tfin;
long ti,tf;

// Funcion a ejecutar al capturar la alarma
int show(){
	long result;
	tf = time(&tfin);
	printf("Tiempo final: %s \n",ctime(&tfin));
	result = tf-ti;
	printf("El tiempo real fue: %ld segundos\n",result);
	return 0;  
}

int main(void){

	ti = time(&tini);
	printf("Tiempo inicial: %s \n", ctime(&tini));

	if(ti >= 0){
		printf("Voy a dormir\n"); 
		signal(SIGALRM,(void*)show); // Se prepara para recibir la alarma
		alarm(10); // programa alarma en 10 seg
		pause(); 
		printf("despues de la funcion\n");
	}
	else{
	 	fprintf(stderr,"Error\n"); 
	}
	printf("termina programa\n"); 
	return 0;
}

