/*
	Example3:	Verified how child to return his finish status		
									
	compile: 	gcc -o return_status 3_fork_return_status.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){

	pid_t pid;
	pid_t pidw;
	int status;
	int value;
	pid  =  fork();

	if( pid < 0 ){		/*Error */ 
		fprintf(stderr, "Fork failed ");
		exit(1);
	}
	else if( pid == 0 ){	/*Child process */ 		
		
		value = 25;
		printf("\n\nCHILD Process pid: %d", getpid());
		printf("\nCHILD Process return status %d\n\n", value);	

		exit(value);
	}
									//void exit(int status);
									//pid_t wait(int *status);

	else {		/*Parent process */ 
		/*Parent will wait for the child */
		printf("\n\nPARENT Waiting ");
		pidw = wait(&status);				//status = 25 & 0377
		printf("\n\nPARENT Process !");
		printf("\nPARENT -> status value: %d!\n", WEXITSTATUS(status));
		printf("\nPARENT -> child process pid: %d!\n", pidw);
		
		return 0;

	}
	return 0;
}
