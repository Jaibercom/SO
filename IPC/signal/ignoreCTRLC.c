/*
*	Programa que ignora la señal de CTRL+C	
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void){
	
	signal(SIGINT, SIG_IGN);
	sleep(10); 
	return 0;
}
