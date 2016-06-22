
/*
 * Name         : 	process.c
 * Author       : 	Jaiber Yepes
 * Description  : 	This project request 2 numbers to user and create 4 children process using fork, 
					in order to add , subtract, multiply and divide the numbers in a parallel way  
					Each process must to return the result to his parent using exit() and wait()
					functions.
 * Compilation  : 	gcc -Wall process.c -o process
 * Execution    : 	./process 5 3     

*/


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
	int num1;
	int num2;
	int i;
	pid_t pid[4]; 
	pid_t pid_child; 
	int result,status;

	if (argc != 3) {
        printf("Error: Numero de parametros invalido.\nDebe iniciar asi: %s <num1> <num2> \n", argv[0]);
		exit(0);
    }

	num1=atoi(argv[1]);
	num2=atoi(argv[2]);

	for(i=0;i<4;i++){
		
		pid[i]=fork();

		if(pid[i]==0){
			switch(i){
				case 0:
					result = num1+num2;
				break;	
				case 1:
					result = num1-num2;
				break;
				case 2:
					result = num1*num2;
				break;	
				case 3:
					if(num2 != 0)
						result = num1/num2;
				break;				
			}

			exit(result);
		}
	}

	for(i=0;i<4;i++){

		pid_child = wait(&status);

		if(pid_child == pid[0]){
			printf("a+b = %d\n", WEXITSTATUS(status));	
		}	
		else if(pid_child == pid[1]){
			printf("a-b = %d\n", WEXITSTATUS(status));	
		}
		else if(pid_child == pid[2]){
			printf("a*b = %d\n", WEXITSTATUS(status));	
		}
		else if(pid_child == pid[3]){
			printf("a/b = %d\n", WEXITSTATUS(status));	
		}
	}

	return 0;
}
