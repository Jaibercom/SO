/*
	Example2: How many process will be running before finish
	compile: gcc -o fork 2_fork_many_process.c
*/

#include <stdio.h>
#include <unistd.h>

int main(){
	
	fork();

	fork();

	fork();
	
	printf("\nProcess pid %d!\n", getpid());
	
	return 0;

}
