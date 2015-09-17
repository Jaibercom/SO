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
	int status;
	pid  =  fork();

	if(pid < 0 ){		/*Error */ 
		fprintf(stderr, "Fork failed ");
	}
	else if( pid == 0 ){	/*Child process */ 
		
		printf("\nCHILD -> pid %d!\n", getpid());
		printf("My parent pid %d!\n", getppid());
		
		exit(25);
	}
	else {		/*Parent process */ 
		/*Parent will wait for the child */
		
		pid = wait(&status);
		printf("\nPARENT -> pid %d!\n", getpid());
		printf("Child complete %d\n", pid); 
		printf("Status %d\n", WEXITSTATUS(status)); 		
		return 0;

	}
	return 0;
}
