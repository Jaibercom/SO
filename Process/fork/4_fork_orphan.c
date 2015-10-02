/*
	compile: gcc 4_fork_orphan.c -o orphan
	In another console, use command "ps -al" to check running process   
	Check now which is the parent process using "ps -aux"
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int pid;

     /* let's create a child process */
    pid = fork();
    if (!pid) {	//child process
         /* this is a child: dies immediately and becomes zombie */
        printf("\nChild pid: %d!\n", getpid());
        printf("Please, press enter after looking at the orphan process...\n");
		//(void)getchar();
		sleep(20);
		printf("\nPID new parent: %d!\n", getppid());
        printf("Child finish\n");
        exit(0);
    }

     /* parent process: just asks for the user input */
     printf("\nParent pid: %d!\n", getpid());
     printf("Parent finish\n");
     exit(0);
} 
