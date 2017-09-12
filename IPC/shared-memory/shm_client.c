#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    key_t my_key;
    int id_memory;
    int *memory = NULL; //Puntero a la memoria compartida
    int i;

    //1. Se obtiene una clave para la memoria compartida
    my_key = ftok ("clave", 10);
	printf("Mi llave es %d\n ", my_key);
    if (my_key == -1)
    {
        perror("No consigo clave para memoria compartida");
        return -1;
    }     

	// 2. Se obtiene el id de la memoria, no se crea
	id_memory = shmget (my_key, sizeof(int)*100, 0777 );
	if (id_memory == -1) {
		perror("No consigo id para memoria compartida");
		return -1;
	}

	//3. Se liga la memoria
	memory = (int *)shmat (id_memory, (void *)0, 0);
	if (memory == NULL){
		perror("No consigo memoria compartida");
		return -1;
	}

	//4. Se lee de la memoria
	for (i=0; i<10; i++){
		printf("Leido %d\n ",memory[i]);
		sleep (1);
	}

	//5.Desasociamos nuestro puntero de la memoria compartida.
	if (id_memory != -1){
		shmdt ((void *)memory);
	}
}

