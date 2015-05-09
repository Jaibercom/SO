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

	if( pid == 0 ){
		value += 15;
		return 0;
	}
	else if( pid > 0 ){
		wait(NULL);
		printf("\nPARENT: value = %d\n", value ); //LINE A
		return 0;

	}

}

