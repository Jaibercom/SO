/*
	Example: How to use system call fork
	compile: gcc -o fork fork_ejemplo.c
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int value =5;

int main(){

	pid_t pid;
	pid  =  fork();

	if( !pid  ){
		value += 15;
		printf("\nChild: value = %d pid =%d\n", value, getpid() ); //LINE B
		return 0;
	}
	else if( pid > 0 ){
		wait(NULL);
		printf("\nPARENT: value = %d, child pid =%d \n", value, pid ); //LINE A
		return 0;

	}

}

