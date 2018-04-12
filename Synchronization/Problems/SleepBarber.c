/*
	Problema del barbero dormilón

	Modificar:
	- Usar la biblioteca semaphore.h
	- Que sean más de un barbero 
	- El número de clientes se debe pasar como parametro
*/


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define CHAIRS 3 //Sillas Disponibles
#define CANT_CUST 5 //Cantidad de Clientes
#define T_CUST 0 //Tiempo de llegada de Clientes
#define T_CORTE 3 //Tiempo de corte de pelo

typedef int semaphore;

//Prototipo de funciones
void *customer (void *);
void *barber (void *);
void signal (semaphore *);
void wait (semaphore *);

semaphore sem_barber=0, sem_customer=0,sem_mutex=1;
int waiting=0;

//Main function
int main (void) {
	pthread_t barb_t,cust_t[CANT_CUST];
	int i;

	pthread_create(&barb_t,NULL,barber,NULL);
	for (i=0;i<CANT_CUST;i++){
		sleep(T_CUST);
		pthread_create(&cust_t[i],NULL,customer,NULL);
	}

	pthread_join(barb_t,NULL);
	return(0);
}

void *customer (void *n) {
	printf ("Customer:entrando hay %d esperando\n",waiting);
	wait (&sem_mutex);
	if (waiting < CHAIRS) {
		waiting++;
		signal (&sem_customer);
		signal (&sem_mutex);
		wait (&sem_barber);
		printf ("Customer:Me estan cortando el pelo.\n");
	}
	else {
		signal (&sem_mutex);
		printf ("Customer:Me fui no hay lugar.\n");
	} 
}

void *barber (void *j) {
	printf ("Barber:Empiezo a trabajar\n"); 
	while (TRUE) {
		wait (&sem_customer);
		wait (&sem_mutex);
		waiting--;
		signal (&sem_barber);
		signal (&sem_mutex);
		
		printf ("Barber:Comienzo el corte de pelo de un cliente quedan %d 	esperando.\n",waiting);
		sleep (T_CORTE);
		printf ("Barber:Termine de cortar el pelo de un cliente quedan %d esperando.\n",waiting);
	}
}

void wait (semaphore *sem) {
	while (*sem<=0){};
	*sem-=1;
}

void signal (semaphore *sem) {
	*sem+=1;
}


