/*
	Un proceso padre crea un proceso hijo. 
	Después de crear el hijo, crea un archivo y escribe en este.
	El proceso hijo debe esperar a que el proceso padre cree el archivo para poder leer el contenido.

*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

#define BLKSIZE 23

void handler(){
	FILE *pFile;
	char *buffer = (char *)malloc(BLKSIZE);
	
	pFile=fopen("miArchivo.txt","r");
	fread(buffer,1,BLKSIZE,pFile);
	printf("Contenido del archivo: %s\n",buffer);
	fclose(pFile);free(buffer);
}

int main(int argc, char*argv[]){
	pid_t childpid;
	FILE *pFile;
	char *buffer;	
	
	childpid=fork();
	if (childpid==-1){
		perror("Ha fallado el fork");  _exit(1);
	}
	else if(childpid==0){				
		signal(SIGUSR1, (void*)handler ); 
		pause();  _exit(1);
	}
	
	
	buffer=strdup("Informacion a compartir");
	pFile = fopen("miArchivo.txt","w");
	fwrite(buffer,1,BLKSIZE,pFile);
	fclose(pFile);
	//sleep(2);
	kill(childpid, SIGUSR1);

	return 0;
}

