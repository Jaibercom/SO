#include <sys/types.h> 
#include <signal.h> 
#include <sys/wait.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{ 
	printf("\nInicia el hijo a ejecutarse\n");
	sleep(3);
	printf("Enviando la señal\n");
	//Manda señal de usuario al pid del padre
	kill(getppid(), SIGUSR1);

	printf("hijo termino\n");  
	exit(0);  
}
