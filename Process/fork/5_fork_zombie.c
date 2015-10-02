/*
	compile: gcc -o zombie 5_fork_zombie.c
	
	In another console, use command "ps -al | grep Z" to check running process  
		
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int pid;
	
     /* let's create a child process */
    pid = fork();
    if (!pid) {		//child process
        /* this is a child: dies immediately and becomes zombie */
        printf("\nChild process finished-> pid: %d!\n", getpid());
        exit(0);
    }
	sleep(1);
	/* parent process: just asks for the user input */
	printf("\nParent pid: %d!\n", getpid());
	printf("Please, press enter after looking at the zombie process...");
	(void)getchar();
	return 0;
} 
