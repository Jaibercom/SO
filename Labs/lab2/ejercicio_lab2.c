#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct materias {
	char nombre[20];
	float nota;

}str_materia;

int main(int argc, char *argv[]){

	int var;
	FILE *pFile;
	str_materia *ptr = NULL;
	char buffer[100];
	char *pch;

	if (argc != 3){
		printf("Error usar asi; a.out <entero> ");
		exit(-1);	
	}
	
	pFile = fopen(argv[2], "r");
	if (pFile == NULL) perror ("Error opening file");
	
	
	if ( fgets (buffer , 100 , pFile) != NULL ){
    	puts (buffer);
	}
	if ( fgets (buffer , 100 , pFile) != NULL ){
    	puts (buffer);
		
		pch = strtok(buffer, ";");
		while(pch != NULL){
			printf ("%s\n",pch);
			pch=strtok(NULL, ";");
		}
	}




	var = atoi(argv[1]);
	if (var == 0){
		printf("Error atoi \n");
		exit(-1);	
	}
	ptr = malloc(sizeof(str_materia)*var);

	(ptr+2)->nota = 2.0;
	strcpy((ptr+2)->nombre, "Juanchito");
/*
	printf("argc = %d\n", var);
	printf("argv[0] = %s\n", argv[0]);
	printf("nota  = %.1f\n", (ptr+2)->nota);
	printf("nombre  = %s\n", (ptr+2)->nombre);
*/
	free(ptr);
	return 0;
}
