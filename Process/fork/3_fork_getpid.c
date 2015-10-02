/*
	Example3:	Use system calls getpid() and getppid()
				Verified how child to return his finish status		
									
	compile: gcc -o fork 3_fork_getpid.c
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
		
		printf("\nCHILD     -> pid %d!\n", getpid());
		printf("My parent -> pid %d!\n", getppid());
		
		exit(25);
	}
	else {		/*Parent process */ 
		/*Parent will wait for the child */
		
		pidw = wait(&status);
		printf("\nPARENT -> pid %d!\n", getpid());
		printf("CHILD complete %d\n", pidw); 
		printf("Status %d\n", WEXITSTATUS(status)); 		
		return 0;

	}
	return 0;
}
