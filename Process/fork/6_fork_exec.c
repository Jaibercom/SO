/*
	Example: How to use system call exec
	compile: gcc -o fork 6_fork_exec.c
	What is the difference between execl and execlp?
	How can I execute ls command with options, for example ls -la 
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){

	pid_t pid;
	pid  =  fork();

	if(pid < 0 ){		/*Error */ 
		fprintf(stderr, "Fork failed ");
	}
	else if( pid == 0 ){	/*Child process */ 
		execl("./fork", "fork", NULL);
		printf("\nChild process \n" ); 
	}
	else {		/*Parent process */ 
		/*Parent will wait for the child */
		wait(NULL);
		printf("\nChild complete \n" ); //LINE A
		return 0;
	}
}
