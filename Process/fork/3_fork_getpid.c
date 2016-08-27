/*
	Example3:	Use system calls getpid() and getppid()
				Verified how child to return his finish status		
									
	compile: gcc -o getpid 3_fork_getpid.c
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
		
		printf("\nCHILD  -> MY pid %d!\n", getpid());
		printf("\nCHILD  -> My parent pid %d!\n", getppid());
		printf("\nCHILD   > variable pid %d!\n", pid);		

	}
	else {		/*Parent process */ 
		/*Parent will wait for the child */	
		wait(NULL);			
		printf("\nPARENT -> My pid %d!\n", getpid());
		printf("\nPARENT -> value pid %d!\n", pid);	
		printf("\nPARENT -> variable %d\n", pid); 	

	}
	return 0;
}
