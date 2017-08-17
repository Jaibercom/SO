/*
	Example: How to use system call exec
	compile: gcc -o exec 8_fork_exec.c
	What is the difference between execl and execlp?
	How can I execute ls command with options, for example ls -la 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	pid_t pid;
	pid  =  fork();

	if(pid < 0 ){		/*Error */ 
		fprintf(stderr, "Fork failed ");
		exit(1);
	}
	else if( pid == 0 ){	/*Child process */ 
		printf("\n\nExec example.....  \n");
		//execl("example", "example", NULL);		
		execlp("ls", "ls", "-al", NULL);
		//execv  ??
		//execvp   ??
		printf("\nChild process \n" ); 
	}
	else {		/*Parent process */ 
		/*Parent will wait for the child */
		wait(NULL);
		printf("\nChild complete \n" ); 
	}
	return 0;
}
