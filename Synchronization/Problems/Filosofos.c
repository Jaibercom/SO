/*
	Cena de los filosofos con semáforos.
	Durante el tiempo que un filósofo está comiendo o pensando permanecerá 
	bloqueado un número aleatorio de segundos entre 0 y 10.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
 
#define N 5 			// Numero de filósofos
#define VIDA 10
#define IZQUIERDA(x)	((x) !=0 ? (x)-1 : (N-1)) //Calcula el filosofo de la izqda
#define DERECHA(x)		(((x)+1)%N) 	//Calcula el filosofo de la dcha

typedef enum{
	PENSANDO,HAMBRIENTO,COMIENDO
}status;

status estado[N]; //Estado en el que esta cada proceso en cada momento (pensando, hambriento o comiendo)
sem_t mutex,s[N]; //Mutex: Solo un filosofo puede coger o soltar tenedores; s[N]: Controlamos si he podido coger tenedores o no, si no he podido, me bloqueo hasta que nos despierte el filosofo de la izqda o dcha

void pensar(int id);
void comer(int id);
void coger_tenedores(int id);
void comprobar(int id);
void soltar_tenedores(int id);
void *Filosofo(void* );

int main(){

	int v[N]/*para decirle a cada hilo quien es*/; 
	int value,i;
	sem_init(&mutex,0,1);
	pthread_t filosofo[N];
	
	for(i=0;i<N;i++){
		sem_init(&s[i],0,0);
		estado[i]=PENSANDO;
	}

	for(i=0;i<N;i++){
		v[i]=i+1;
		if(value=pthread_create(&filosofo[i],NULL,Filosofo, (void *) &v[i]))
			exit(value);

	}
	
	for(i=0;i<N;i++){
		pthread_join(filosofo[i],NULL);
	}

	return 0;
}

void *Filosofo(void* i)
{
	int id,j;
	id=*(int *) i;

	for(j=0;j<2;j++){
		pensar(id);
		coger_tenedores(id);
		comer(id);
		soltar_tenedores(id);
	}
}

void pensar(int id)
{
	printf("Filosofo %d: pensando\n",id);
	sleep (random() % 10);
}

void comer(int id)
{
	printf("Filosofo %d: comiendo\n",id);
	sleep (random() % 10);
}

void coger_tenedores(int id)
{
	sem_wait(&mutex); //Si un filosofo esta cogiendo tenedores, no podre coger y me quedare bloqueado. Si no hay nadie cogiendo tenedores, cogere yo
	estado[id]=HAMBRIENTO;
	comprobar(id);
	sem_post(&mutex); //Permito que otro filosofo coja tenedores
	sem_wait(&s[id]); //Si no hace el post de la funcion comprobar(), se quedaria estancado aqui
}

void comprobar(int id)
{
	if(estado[id]==HAMBRIENTO && estado[IZQUIERDA(id)]!=COMIENDO && estado[DERECHA(id)]!=COMIENDO)
	{
		estado[id]=COMIENDO;
		sem_post(&s[id]); //Sirve para liberar al filosofo para que no se quede estancado mas adelante, puesto que ha podido coger tenedores
	}
}

void soltar_tenedores(int id)
{
	sem_wait(&mutex); //Si hay alguien cogiendo tenedores, nadie mas puede coger. Si estoy cogiendo tenedores, bloqueo para que nadie mas pueda hacerlo 
	estado[id]=PENSANDO;
	comprobar(IZQUIERDA(id));
	comprobar(DERECHA(id));
	sem_post(&mutex);
}
