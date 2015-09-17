#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <pthread.h>
#include <semaphore.h>

// Numero máximo de clientes 
#define MAX_CUSTOMERS 25

// Firma de las funciones
void *customer(void *num);
void *barber(void *);
void randwait(int secs);

// Declaración de semáforos.
sem_t waitingRoom;	// waitingRoom limita el numero de clientes permitidos para entrar a la sala de espera.
sem_t barberChair;	// barberChair garantiza el acceso mutuamente exclusivo a la silla del barbero.
sem_t barberPillow;	// barberPillow se utiliza para poner al barbero a dormir hasta que llega un cliente.
sem_t seatBelt;		// seatBelt se utiliza para que un cliente espere hasta que el barbero corte su cabello.

int allDone = 0;		// Bandera para detener el hilo barbero cuando todos los clientes han sido atendidos.

int main(int argc, char *argv[]) 
{
    pthread_t btid;
    pthread_t tid[MAX_CUSTOMERS];
    long RandSeed;
    int i, numCustomers, numChairs;
    int Number[MAX_CUSTOMERS];
          
    // verificamos que halla el numero adecuado de
    // argumentos en la linea de comando.
    if (argc != 4) {
		 printf("Use: SleepBarber <Num Customers> <Num Chairs> <rand seed>\n");
		 exit(-1);
    }
    
    // Convertimos los argumentos en enteros.
    numCustomers = atoi(argv[1]);
    numChairs = atoi(argv[2]);
    RandSeed = atol(argv[3]);
    
    // Verificar que el numero de hilos es menor que el numero e clientes que se soṕorta
    if (numCustomers > MAX_CUSTOMERS) {
		 printf("El maximo numero de clientes es %d.\n", MAX_CUSTOMERS);
		 exit(-1);
    }
    
    printf("\nSleepBarber.c\n\n");
    printf("Una solucion al problema del barbero domilon.\n");
    
    //Inicializa el generador de numeros aleatorios
    srand48(RandSeed);

    // Se inicializa el vector de numeros
    for (i=0; i<MAX_CUSTOMERS; i++) {
    	Number[i] = i;
    }
        
    // Se inicializan los semaforos
    sem_init(&waitingRoom, 0, numChairs);
    sem_init(&barberChair, 0, 1);
    sem_init(&barberPillow, 0, 0);
    sem_init(&seatBelt, 0, 0);
    
    // Creacion del barbero
    pthread_create(&btid, NULL, barber, NULL);

    // Creacion de los clientes
    for (i=0; i<numCustomers; i++) {
    	pthread_create(&tid[i], NULL, customer, (void *)&Number[i]);
    }

    //Espera que los hilos terminen
    for (i=0; i<numCustomers; i++) {
    	pthread_join(tid[i],NULL);
    }

    // Cuando todos los clientes se atiendan matar al hilo barbero
    allDone = 1;
    sem_post(&barberPillow);  //Despierta al barbero para salir
    pthread_join(btid,NULL); 
    
	sem_destroy(&waitingRoom);
	sem_destroy(&barberChair);
	sem_destroy(&barberPillow);
	sem_destroy(&seatBelt);
    
    return 0;   
}

void *customer(void *number) {
    int num = *(int *)number+1;

    // Clientes que llegan a la peluqueria.
    printf("Cliente %d se dirige a la peluqueria.\n", num);
    randwait(5);
    printf("Cliente %d llega a la peluqueria.\n", num);

    // Espera en la sala de espera
    sem_wait(&waitingRoom);
    printf("Cliente %d entra en la sala de espera.\n", num);

    // Esperar que la silla del barbero este libre.
    sem_wait(&barberChair);
    
    // Cuando la silla este libre se va de la sala de espera
    sem_post(&waitingRoom);

    // Despertar al barbero
    printf("Cliente %d despierta el barbero\n", num);
    sem_post(&barberPillow);

    // Espera que el barbero corte el cabello
    sem_wait(&seatBelt);
    
    // Deja la silla
    sem_post(&barberChair);
    printf("Cliente %d deja la peluqueria.\n", num);
}

void *barber(void *junk) {
    // Mientras haya clientes por atender
    while (!allDone) {
		 // Duerme mientras que alguien llega y lo despierta
		 printf("El barbero esta durmiendo\n");
		 sem_wait(&barberPillow);

		 // Finaliza
		 if (!allDone) {
		     // Cantidad aleatoria de tiempo para cortar el cabello
		     printf("El barbero esta cortando el cabello\n");
		     randwait(3);
		     printf("El barbero finalizó el corte.\n");

		     // El cliente ya no le estan cortando el cabello
		     sem_post(&seatBelt);
		 }
		 else {
		     printf("El barbero fue a casa por hoy.\n");
		 }
    }
}

void randwait(int secs) {
    int len;
   
    // Generador de numero aleatorio
    len = (int) ((drand48() * secs) + 1);
    sleep(len);
}
