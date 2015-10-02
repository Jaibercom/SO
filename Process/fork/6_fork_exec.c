/*
	Example: How to use system call exec
	compile: gcc -o fork 6_fork_exec.c
	What is the difference between execl and execlp?
	How can I execute ls command with options, for example ls -la 
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	pid_t pid;
	pid  =  fork();

	if(pid < 0 ){		/*Error */ 
		fprintf(stderr, "Fork failed ");
	}
	else if( pid == 0 ){	/*Child process */ 
		
		//execl("/bin/ls", "ls", NULL);		
		execl("/bin/ls", "ls", "-l", "-a", NULL);
		//execv  ??
		//execvp   ??
		printf("\nChild process \n" ); 
	}
	else {		/*Parent process */ 
		/*Parent will wait for the child */
		wait(NULL);
		printf("\nChild complete \n" ); //LINE A
		return 0;
	}
	return 0;
}
