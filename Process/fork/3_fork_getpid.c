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
	int status;
	int value;
	pid  =  fork();

	if( pid < 0 ){		/*Error */ 
		fprintf(stderr, "Fork failed ");
		exit(1);
	}
	else if( pid == 0 ){	/*Child process */ 
		
		printf("\nCHILD  -> MY pid %d!", getpid());
		printf("\nCHILD  -> My parent pid %d!", getppid());
		printf("\nCHILD   > variable pid %d!\n", pid);
		exit(0);		

	}
	else {		/*Parent process */ 
		/*Parent will wait for the child */	
		wait(NULL);			
		printf("\nPARENT -> My pid %d!", getpid());
		printf("\nPARENT -> variable pid %d\n", pid); 	

	}

	printf("\nMessage\n\n"); 
	return 0;
}
