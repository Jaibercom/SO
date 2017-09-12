/*
	Example5:	Creating some childs, all of them are running concurrently		
									
	compile: 	gcc -o return_status 5_fork_creating_some_childs.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main () {
    int i;
    int numHijos = 5;
    pid_t pid[5], pidw;

    for (i = 0; i < numHijos; i++) {
        pid[i] = fork();
        if (pid[i] == -1) {
            /* Error */
            printf("No fue posible crear un hijo\n");
            return -1;
        }
        if (pid == 0) {
			sleep(2);
            printf("Soy el hijo #%d con PID: %d\n",i+1, getpid());
            exit(0);
        }		
    }
	
	for (i = 0; i < numHijos; i++) {
		pidw = wait(NULL);

		printf("el hijo con PID #%d termino: \n", pidw);
	}

	printf("El padre termino\n");
    return 0;
}
