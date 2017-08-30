#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>  

void function();

int main(void) 
{ 
    pid_t childpid;     
	int status;
    
	printf("\nInicia el padre a ejecutarse\n");
	signal(SIGUSR1, function);// se prepara para señal del usuario
    
	if ((childpid = fork()) == -1) {
       perror("Error en creación de hijo");  exit(1);
    } 
	else if (childpid == 0) {             
		if (execl("child","child", NULL) < 0){
			perror("Exec of hijo failed"); exit(1);
		} 
	} 
	printf("\nEl padre se va a dormir\n");
	pause();
	printf("\nTermina el padre\n");  
	exit(0);  
}

//Funcion a ejecutar cuando despierte
void function()
{  
     printf("Papa: Hijo ya terminó\n");  
} 
